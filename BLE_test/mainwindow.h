#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>

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


private slots:
    void openSerialPort();
    void onSerialRead();
    void onSerialWrite();
private:
    void initActionsConnections();



};
#endif // MAINWINDOW_H
