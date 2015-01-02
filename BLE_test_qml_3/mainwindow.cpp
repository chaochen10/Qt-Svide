#include "mainwindow.h"
#include "svideBle.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QtSerialPort>
#include <QQuickItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Svide = new svideBle();
    timer_BLEconfig = new QTimer(this);
    timer_BLEnotificacion = new QTimer(this);
    timer_termocirculador = new QTimer(this);
    value_dialMin_set = ui->dial_min->value();
    value_dialTemp_set = ui->dial_temp->value();
    estadoSvide = "reposo";
    min_actual = 0;
    segRestante_actual = 0;
    temp_actual = 20;
    contarTiempoMostrar=0; ///para enviar tiempo actual al GUI
    comandoFinalizado=false;

    ui->button_blenotify->setDefault(false);
    Ble_servicio = Svide->UUID_servicio;
    Ble_notificacion = Svide->UUID_Notificacion;
    Ble_escLect = Svide->UUID_EscrituraLectura;
    ui->show_UUID->insertPlainText("R/W: "+Ble_escLect+"\n");
    ui->show_UUID->insertPlainText("Notif: "+Ble_notificacion);

    numComandoIntro =1; ///muestra en la ventana las veces de comandos introducidos
    numBLEConfig =0; ///contandor para configuración BLE Servicios/Características Sammic
    //    ui->button_bleconfig->setEnabled(false);

    QUrl source("qrc:userInterface/gui_test.qml");
    ui->guiSVide->setSource(source);
    m_currentRootObject = ui->guiSVide->rootObject();
    //    qDebug()<<m_currentRootObject;


    serial = new QSerialPort(this);
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        ui->portBox->addItem(info.portName());
        //        qDebug()<<info.portName();
    }
    ui->portBox->setCurrentIndex(ui->portBox->count()-1); //ui->portBox->count()-1

    ui->baudBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->baudBox->setCurrentIndex(3);

    initActionsConnections();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initActionsConnections(){
    ///comunicacion serie
    connect(ui->serialComButton, SIGNAL(clicked()), this, SLOT(openSerialPort()));
    connect(serial, SIGNAL(readyRead()),this, SLOT(onSerialRead()));
    connect(ui->comando, SIGNAL(returnPressed()), SLOT(onSerialWrite()));
    ///widget
    connect(ui->dial_min, SIGNAL(valueChanged(int)), this, SLOT(valueChangedDialMin()));
    connect(ui->dial_temp, SIGNAL(valueChanged(int)), this, SLOT(valueChangedDialTemp()));
    connect(ui->button_svideStart,SIGNAL(clicked()),this,SLOT(onStartBotonTermocirculador()));
    ///BLE
    connect(ui->button_bleconfig,SIGNAL(clicked()),this, SLOT(initBLEconfig()));
    connect(timer_BLEconfig, SIGNAL(timeout()), this, SLOT(update_initBLEconfig()));
    timer_BLEconfig->stop();
    connect(ui->button_blenotify,SIGNAL(clicked()),this, SLOT(BLEnotify()));
    connect(timer_BLEnotificacion,SIGNAL(timeout()),this,SLOT(update_BLEnotify()));
    timer_BLEnotificacion->stop();
    ///termocirculador
    connect(timer_termocirculador, SIGNAL(timeout()),this, SLOT(update_termocirculador()));
    timer_termocirculador->stop();
}

void MainWindow::openSerialPort()
{
    if(!serial->isOpen()){
        serial->setPortName(ui->portBox->currentText());
        serial->setBaudRate(ui->baudBox->currentData().toInt());
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity( QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl( QSerialPort::NoFlowControl);
        serial->open(QIODevice::ReadWrite);

        qDebug()<<"conexión:"<<serial->portName()<<" bps:"<<serial->baudRate()<<"databits:"<<serial->dataBits()
               <<"paridad:"<<serial->parity()<<" stopbit:"<<serial->stopBits()<<"flow:"<<serial->flowControl();

        if(serial->isOpen()){
            ui->serialComButton->setIcon(QIcon(":/iconos/imagenes/connect.png"));
            timer_termocirculador->start(2000);
        }
        ui->button_bleconfig->setEnabled(true);
    }
    else{
        serial->close();
        ui->serialComButton->setIcon(QIcon(":/iconos/imagenes/disconnect.png"));
    }
}

void MainWindow::onSerialRead(){
    if (serial->bytesAvailable()) {
        ui->consola->setTextColor("grey");
        QByteArray data = serial->readAll();
        ui->consola->insertPlainText(QString(data));
        qDebug()<<data;
        ui->consola->moveCursor(QTextCursor::End);
        ui->consola->setTextColor("black");
    }
}

void MainWindow::onSerialWrite(){
    if (serial->isOpen() && !ui->comando->text().isEmpty()){
        QString writeDatos = QString("\n[%1").arg(numComandoIntro)+"]: "+QString(ui->comando->text())+"\n";
        ui->consola->insertPlainText(writeDatos);
        serial->write(ui->comando->text().toLatin1());
        //        qDebug()<<writeDatos;
        ui->comando->clear();
        numComandoIntro ++;
    }
}

void MainWindow::valueChangedDialMin(){
    value_dialMin_set = ui->dial_min->value();
    m_currentRootObject->setProperty("angTiempo_p", value_dialMin_set);
}

void MainWindow::valueChangedDialTemp(){
    value_dialTemp_set = ui->dial_temp->value();
    m_currentRootObject->setProperty("angTemp_p", value_dialTemp_set);
    //    m_currentRootObject->setProperty("tiempo_mostrar",value_dialTemp_set);
}
/*preConfiguración BLE SAMMIC*/
void MainWindow::initBLEconfig(){
    ui->button_bleconfig->setStyleSheet("background-color:rgb(168, 255, 53);");
    ui->consola->setTextColor("blue");
    ui->consola->insertPlainText("** Iniciando configuración RN4020 de Sammic: **\n");
    timer_BLEconfig->start(2000);
}
void MainWindow::update_initBLEconfig(){
    ui->consola->setTextColor("blue");
    QString comando;
    numBLEConfig++;
    comando = Svide->preConfigBleSammic(numBLEConfig);

    if(comandoFinalizado==false){
        serial->write(comando.toLatin1());
        comando = "-> "+comando+"\n";
        qDebug()<<comando;
        ui->consola->insertPlainText(comando);
        if (comando=="-> R,1\n"){
            comandoFinalizado =true;
        }
    }

    else if(comandoFinalizado==true){
        comando ="** Configuración finalizada ** ¡reiniciar RN4020!";
        comando =comando+"\n";
        qDebug()<<comando;
        ui->consola->insertPlainText(comando);
        ui->button_bleconfig->setStyleSheet("background-color: rgb(181, 161, 181);");
        ui->consola->setTextColor("black");
        comandoFinalizado=false;
        numBLEConfig=0;
        timer_BLEconfig->stop();
    }
}
/*Envio de notificación BLE SAMMIC*/
void MainWindow::BLEnotify(){
    if(!ui->button_blenotify->isDefault()){
        ui->button_blenotify->setStyleSheet("background-color:rgb(255, 178, 102);");
        ui->button_blenotify->setDefault(true);
        //        qDebug()<<ui->button_blenotify->isDefault();
        timer_BLEnotificacion->start(2000);
    }
    else if(ui->button_blenotify->isDefault()){
        ui->button_blenotify->setStyleSheet("");
        ui->button_blenotify->setDefault(false);
        //        qDebug()<<ui->button_blenotify->isDefault();
        timer_BLEnotificacion->stop();
        ui->label_notificacion->setText("notificacion: Cancelada");
    }
    //    qDebug()<<ui->button_blenotify->isDefault();
}
void MainWindow::update_BLEnotify(){
    QString soloUUIDnotify = Ble_notificacion.left(32);
    //    qDebug()<<soloUUIDnotify;
    QString dato_notificacion = Svide->characterEstado();
    QString notificacion ="suw,"+soloUUIDnotify+","+dato_notificacion;
    qDebug()<<notificacion;
    ui->label_notificacion->setText(notificacion);
    serial->write(notificacion.toLatin1());

}
/*Funcionamiento Svide*/
void MainWindow::onStartBotonTermocirculador(){
    if(estadoSvide=="reposo"){
        //        value_dialTemp_set = ui->dial_temp->value();
        estadoSvide="calentando";
        timer_termocirculador->start(1000);
        imagenMostrarAgua =true;
        //         m_currentRootObject->setProperty("onCiclo",false);
    }
    else if(estadoSvide=="calentamientoTerminado"){
        estadoSvide="ciclo";
        ui->label_imagIntro->setPixmap(QPixmap(":/iconos/imagenes/agua3_ciclo.png"));
        timer_termocirculador->start(1000);
        //         m_currentRootObject->setProperty("onCiclo",true);
    }
    else if(estadoSvide=="ciclo"){
        estadoSvide="pausa";
        ui->label_imagIntro->setPixmap(QPixmap(":/iconos/imagenes/agua3_pausa.png"));
    }
    else if(estadoSvide=="pausa"){
        estadoSvide="ciclo";
        ui->label_imagIntro->setPixmap(QPixmap(":/iconos/imagenes/agua3_ciclo.png"));
        timer_termocirculador->start(1000);
    }
    else if(estadoSvide=="completado"){
        estadoSvide="reposo";
        //         m_currentRootObject->setProperty("onCiclo",false);
        ui->label_imagIntro->setPixmap(QPixmap(":/iconos/imagenes/agua00_reposo.png"));
        Svide->estado_info= estadoSvide;
        temp_actual = 20;
        min_actual = 0;
    }
}
void MainWindow::update_termocirculador(){
    //    if(serial->isOpen()){
    if(estadoSvide=="reposo"){

    }
    else if(estadoSvide =="calentando"){
        temp_actual = temp_actual + 1; ///actualización temperatura
        segRestante_actual = (timer_termocirculador->interval())/1000*(value_dialTemp_set-temp_actual);//actualización tiempo restante de calentamiento
        ///cambiar imagen agua0 calentando
        if(imagenMostrarAgua){
            ui->label_imagIntro->setPixmap(QPixmap(":/iconos/imagenes/agua0.png"));
            imagenMostrarAgua=false;
        }
        ///cambiar imagen agua1 calentando
        else if(!imagenMostrarAgua){
            ui->label_imagIntro->setPixmap(QPixmap(":/iconos/imagenes/agua1.png"));
            imagenMostrarAgua=true;
        }
        ///cambiar imagen agua2 calentamiento terminado
        if(temp_actual>=value_dialTemp_set){
            temp_actual=value_dialTemp_set;
            estadoSvide="calentamientoTerminado";
            ui->label_imagIntro->setPixmap(QPixmap(":/iconos/imagenes/agua2.png"));
            timer_termocirculador->stop();
        }
        m_currentRootObject->setProperty("temp_mostrar", temp_actual);
        m_currentRootObject->setProperty("tiempo_mostrar_seg",segRestante_actual);

    }
    else if(estadoSvide =="ciclo"){
        if(contarTiempoMostrar == 0){
            min_actual = min_actual + 1;
            contarTiempoMostrar = contarTiempoMostrar+1;
            ui->label_imagIntro->setPixmap(QPixmap(":/iconos/imagenes/agua3_ciclo.png"));
            if(min_actual>= value_dialMin_set){ ///completado
                min_actual =  ui->dial_min->value();
                estadoSvide ="completado";
                ui->label_imagIntro->setPixmap(QPixmap(":/iconos/imagenes/agua4_fin.png"));
                timer_termocirculador->stop();
            }
        }
        else if(contarTiempoMostrar!=0){
            contarTiempoMostrar = contarTiempoMostrar +1;
            ui->label_imagIntro->setPixmap(QPixmap(":/iconos/imagenes/agua3_ciclo2.png"));
            if(contarTiempoMostrar==2){ ///Tiempo segundos muertos
                contarTiempoMostrar=0;
            }
        }
        //                qDebug()<<"contartiempo:"<<contarTiempoMostrar;
        m_currentRootObject->setProperty("tiempo_mostrar",min_actual);

    }
    else if(estadoSvide=="pausa"){
        timer_termocirculador->stop();
    }

    Svide->estado_info= estadoSvide;
    Svide->estado_tempAgua = temp_actual;
    Svide->estado_tiempo_ciclo = min_actual;
    Svide->estado_tiempo_calentamiento = segRestante_actual;
    //      qDebug()<<estadoSvide<<"\ttemperatura actual:"<<temp_actual<<"ºC\ttiempo transcurrido:"<<min_actual<<"min";
    //    qDebug()<<Svide->characterEstado();
    //    }
}

