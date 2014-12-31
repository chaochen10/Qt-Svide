#include "mainwindow.h"
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

    numComandoIntro =1;
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
    connect(ui->serialComButton, SIGNAL(clicked()), this, SLOT(openSerialPort()));
    connect(serial, SIGNAL(readyRead()),this, SLOT(onSerialRead()));
    connect(ui->comando, SIGNAL(returnPressed()), SLOT(onSerialWrite()));

    connect(ui->dial_min, SIGNAL(valueChanged(int)), this, SLOT(valueChangedDialMin()));
    connect(ui->dial_temp, SIGNAL(valueChanged(int)), this, SLOT(valueChangedDialTemp()));

    connect(ui->button_bleconfig,SIGNAL(clicked()),this, SLOT(initBLEconfig()));
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
        //        if (serial->open(QIODevice::ReadWrite)) {
        //                ui->consola->setEnabled(true);
        //        }
        serial->open(QIODevice::ReadWrite);

        qDebug()<<"conexión:"<<serial->portName()<<" bps:"<<serial->baudRate()<<"databits:"<<serial->dataBits()
               <<"paridad:"<<serial->parity()<<" stopbit:"<<serial->stopBits()<<"flow:"<<serial->flowControl();
        //        qDebug()<<serial->isOpen();
        //        qDebug()<<serial->error();
        if(serial->isOpen()){
            ui->serialComButton->setIcon(QIcon(":/iconos/imagenes/connect.png"));
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

        QByteArray data = serial->readAll();
        ui->consola->insertPlainText(QString(data));
        qDebug()<<data;
        ui->consola->moveCursor(QTextCursor::End);
//        inString = inString.append(data);
//        qDebug()<<"string"<<inString;
//        inString.clear();
    }
}

void MainWindow::onSerialWrite(){
    if (serial->isOpen() && !ui->comando->text().isEmpty()){
        serial->write(ui->comando->text().toLatin1());
        QString writeDatos = QString("[%1").arg(numComandoIntro)+"]: "+QString(ui->comando->text())+"\n";
        ui->consola->insertPlainText(writeDatos);
//        qDebug()<<writeDatos;
        ui->comando->clear();
        numComandoIntro ++;
    }
}

void MainWindow::valueChangedDialMin(){
    int value_dialMin = ui->dial_min->value();
     value_dialMin = int(value_dialMin/1.2);

     value_dialMin = 100 -value_dialMin;
     if(value_dialMin==0)value_dialMin =1;
     else if(value_dialMin==100)value_dialMin=0;

     m_currentRootObject->setProperty("angTiempo_p", value_dialMin);
}

void MainWindow::valueChangedDialTemp(){
    int value_dialTemp = ui->dial_temp->value();

    m_currentRootObject->setProperty("angTemp_p", value_dialTemp);
}

void MainWindow::initBLEconfig(){
//    ui->button_bleconfig->setStyleSheet("background-color:(168, 255, 53)");
    int numConfig = 0;
    QString comando;
    time1.start();
    ui->consola->insertPlainText("Iniciando configuración RN4020 de Sammic\n");
//    while(true){
        if(time1.elapsed()>1000){
            numConfig++;
            switch(numConfig){
                case 1:
                    comando = "SS,00000001";
                    qDebug()<<"SS,00000001                   Enable private service support";
                    ui->consola->insertPlainText(comando);
                    break;
                 case 2:
                    comando = "PZ\n";
                    qDebug()<<"PZ       clear the current private service and characteristics";
                    ui->consola->insertPlainText(comando);
                    break;
                case 3:
                    comando = "PS,53346d6d3163424c457333727631\n";
                    qDebug()<<"PS,53346d6d3163424c457333727631      Set private service UUID";
                    ui->consola->insertPlainText(comando);
                    break;
                case 4:
                    comando = "PC,53346d6d3163424c4573656e6421,A,F\n";
                    qDebug()<<"PC,53346d6d3163424c4573656e6421,A,F                Read/Write";
                    ui->consola->insertPlainText(comando);
                    break;
                case 5:
                    comando = "PC,53346d6d3163424c456e6f747966,10,F\n";
                    qDebug()<<"PC,53346d6d3163424c456e6f747966,10,F                   Notify";
                    ui->consola->insertPlainText(comando);
                    break;
                case 6:
                    qDebug()<<"R,1                                                    Reboot";
                    ui->consola->insertPlainText(comando);
                    break;
                default: break;
            }
            time1.restart();
        }
        if(numConfig==6)  break;
//    }

}
