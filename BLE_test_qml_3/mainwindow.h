#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "svide.h"
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QQuickWidget>
#include <QQuickView>
#include <QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    svide *Svide;
    QSerialPort *serial;
    QString datosSerial;
    QObject *m_currentRootObject;
    QString text ;
    QString inString;
    int numComandoIntro;
    int numBLEConfig;
    QTimer *timer_BLEconfig;
    QString Ble_servicio;
    QString Ble_notificacion;
    QString Ble_escLect;
//    QString UUID_servicio;
//    QString UUID_Notificacion;
//    QString UUID_EscrituraLectura;
    QTimer *timer_BLEnotificacion;

private slots:
    void openSerialPort();
    void onSerialRead();
    void onSerialWrite();

    void valueChangedDialTemp();
    void valueChangedDialMin();
    void initBLEconfig();
    void update_initBLEconfig();
    void BLEnotify();
    void update_BLEnotify();

private:
    void initActionsConnections();




};
#endif // MAINWINDOW_H
