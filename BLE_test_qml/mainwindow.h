#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QQuickWidget>
#include <QQuickView>

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


private slots:
    void openSerialPort();
    void onSerialRead();
    void onSerialWrite();

    void onValueChanged();
    void valueChangedDialTemp();
    void valueChangedDialMin();

private:
    void initActionsConnections();



};
#endif // MAINWINDOW_H
