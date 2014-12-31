#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QQuickWidget>
#include <QQuickView>
#include <QTime>

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
    QSerialPort *serial;
    QString datosSerial;
    QObject *m_currentRootObject;
    QString text ;
    QString inString;
    int numComandoIntro;
    QTime time1;

private slots:
    void openSerialPort();
    void onSerialRead();
    void onSerialWrite();

    void valueChangedDialTemp();
    void valueChangedDialMin();
    void initBLEconfig();

private:
    void initActionsConnections();




};
#endif // MAINWINDOW_H
