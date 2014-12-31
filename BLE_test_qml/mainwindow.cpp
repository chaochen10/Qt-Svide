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

    qDebug()<<m_currentRootObject;


    QUrl source("qrc:userInterface/gui_test.qml");
    ui->guiSVide->setSource(source);
    m_currentRootObject = ui->guiSVide->rootObject();



    serial = new QSerialPort(this);
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        ui->portBox->addItem(info.portName());
        //        qDebug()<<info.portName();
    }
    ui->portBox->setCurrentIndex(ui->portBox->count()-1);
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

    connect(ui->test_slider,SIGNAL(valueChanged(int)),this,SLOT(onValueChanged()));
    connect(ui->dial_min, SIGNAL(valueChanged(int)), this, SLOT(valueChangedDialMin()));
    connect(ui->dial_temp, SIGNAL(valueChanged(int)), this, SLOT(valueChangedDialTemp()));

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
//            ui->consola->
//            serial->write("activarCOM");
        }


    }
    else{
        serial->close();
        ui->serialComButton->setIcon(QIcon(":/iconos/imagenes/disconnect.png"));
//        QString comandoActivar ="desactivarCOM";
//        serial->write(comandoActivar.toLatin1());

    }

}

void MainWindow::onSerialRead(){
    if (serial->bytesAvailable()) {

        QByteArray data = serial->readAll();
        ui->consola->insertPlainText(QString(data));
//        qDebug()<<data;
        ui->consola->moveCursor(QTextCursor::End);
//        inString = inString.append(data);
//        qDebug()<<"string"<<inString;
//        inString.clear();
    }


}

void MainWindow::onSerialWrite(){
    if (serial->isOpen() && !ui->comando->text().isEmpty()){
        serial->write(ui->comando->text().toLatin1());
        ui->comando->clear();
    }

}

void MainWindow::onValueChanged(){
    int int_test = ui->test_slider->value();
//    qDebug()<<"int:"<<int_test;
    text = (QString("%1").arg(int_test));
//    qDebug()<<"string:"<<text;
    m_currentRootObject->setProperty("currentText", text);
    qDebug()<<setProperty("currentText", text);

}

void MainWindow::valueChangedDialMin(){
//    int value_dialMin = ui->dial_min->value();

}

void MainWindow::valueChangedDialTemp(){
//    int value_dialTemp = ui->dial_temp->value();
}
