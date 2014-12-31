#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QtSerialPort>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QUrl source("qrc:userInterface/gui_test.qml");
    ui->guiSVide->setSource(source);




    serial = new QSerialPort(this);
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        ui->portBox->addItem(info.portName());
        //        qDebug()<<info.portName();
    }

    ui->baudBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);

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
        ui->consola->moveCursor(QTextCursor::End);
        QByteArray data = serial->readAll();
        ui->consola->insertPlainText(QString(data));
        //        qDebug()<<data;
        //        ui->consola->moveCursor(QTextCursor::End);
        //        ui->consola->insertPlainText(datosSerial=QString::fromLatin1(serial->readLine()));
        //        qDebug()<<datosSerial;
    }

}

void MainWindow::onSerialWrite(){
    if (serial->isOpen() && !ui->comando->text().isEmpty()){
        serial->write(ui->comando->text().toLatin1());
        ui->comando->clear();
    }

}

cppSlot(const QString &msg) {
        qDebug() << "Called the C++ slot with message:" << msg;
    }
