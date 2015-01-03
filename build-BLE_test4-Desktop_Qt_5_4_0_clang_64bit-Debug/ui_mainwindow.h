/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QQuickWidget"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QQuickWidget *guiSVide;
    QPushButton *serialComButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *consola;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *comando;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *portBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *baudBox;
    QLabel *label_intro;
    QDial *dial_temp;
    QDial *dial_min;
    QLabel *label_temp;
    QLabel *dial_letraC;
    QLabel *label_min;
    QLabel *dial_letraMin;
    QLabel *label_imagIntro;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_sammicBLE;
    QPushButton *button_bleconfig;
    QPlainTextEdit *show_UUID;
    QLabel *label_6;
    QPushButton *button_blenotify;
    QLabel *label_notificacion;
    QPushButton *button_svideStart;
    QLabel *label_intro_2;
    QLabel *label_ordenCiclo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/iconos/imagenes/logo_sammic.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setStyleSheet(QStringLiteral("selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(200, 0, 10, 255), stop:1 rgba(255, 255, 255, 255));"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("color: rgb(59, 59, 59);"));
        guiSVide = new QQuickWidget(centralWidget);
        guiSVide->setObjectName(QStringLiteral("guiSVide"));
        guiSVide->setGeometry(QRect(449, 30, 430, 421));
        guiSVide->setResizeMode(QQuickWidget::SizeRootObjectToView);
        serialComButton = new QPushButton(centralWidget);
        serialComButton->setObjectName(QStringLiteral("serialComButton"));
        serialComButton->setGeometry(QRect(270, 30, 56, 56));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/iconos/imagenes/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/iconos/imagenes/connect.png"), QSize(), QIcon::Normal, QIcon::On);
        serialComButton->setIcon(icon1);
        serialComButton->setIconSize(QSize(50, 50));
        serialComButton->setAutoDefault(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 100, 421, 351));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        consola = new QTextEdit(layoutWidget);
        consola->setObjectName(QStringLiteral("consola"));
        consola->setStyleSheet(QLatin1String("selection-background-color: rgb(255, 183, 209);\n"
"color: rgb(62, 62, 62);\n"
""));
        consola->setReadOnly(true);

        verticalLayout->addWidget(consola);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 75 8pt \"MS Shell Dlg 2\";"));

        horizontalLayout->addWidget(label);

        comando = new QLineEdit(layoutWidget);
        comando->setObjectName(QStringLiteral("comando"));
        comando->setStyleSheet(QStringLiteral("selection-background-color: rgb(136, 178, 236);"));

        horizontalLayout->addWidget(comando);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 251, 64));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        portBox = new QComboBox(layoutWidget1);
        portBox->setObjectName(QStringLiteral("portBox"));

        horizontalLayout_2->addWidget(portBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        baudBox = new QComboBox(layoutWidget1);
        baudBox->setObjectName(QStringLiteral("baudBox"));

        horizontalLayout_3->addWidget(baudBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_intro = new QLabel(centralWidget);
        label_intro->setObjectName(QStringLiteral("label_intro"));
        label_intro->setGeometry(QRect(470, 10, 311, 16));
        QFont font;
        font.setFamily(QStringLiteral("Papyrus"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label_intro->setFont(font);
        label_intro->setStyleSheet(QLatin1String("color: rgb(170, 0, 0);\n"
"font: 75 11pt \"Papyrus\";"));
        dial_temp = new QDial(centralWidget);
        dial_temp->setObjectName(QStringLiteral("dial_temp"));
        dial_temp->setGeometry(QRect(614, 460, 90, 90));
        dial_temp->setStyleSheet(QStringLiteral("background-color: rgb(250, 10, 24);"));
        dial_temp->setMinimum(25);
        dial_temp->setMaximum(100);
        dial_temp->setTracking(true);
        dial_temp->setWrapping(false);
        dial_temp->setNotchesVisible(true);
        dial_min = new QDial(centralWidget);
        dial_min->setObjectName(QStringLiteral("dial_min"));
        dial_min->setGeometry(QRect(724, 460, 90, 90));
        dial_min->setMouseTracking(false);
        dial_min->setAutoFillBackground(false);
        dial_min->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        dial_min->setInputMethodHints(Qt::ImhNone);
        dial_min->setMaximum(120);
        dial_min->setInvertedAppearance(false);
        dial_min->setInvertedControls(false);
        dial_min->setWrapping(false);
        dial_min->setNotchesVisible(true);
        label_temp = new QLabel(centralWidget);
        label_temp->setObjectName(QStringLiteral("label_temp"));
        label_temp->setGeometry(QRect(639, 495, 25, 16));
        dial_letraC = new QLabel(centralWidget);
        dial_letraC->setObjectName(QStringLiteral("dial_letraC"));
        dial_letraC->setGeometry(QRect(668, 495, 21, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        dial_letraC->setFont(font1);
        dial_letraC->setStyleSheet(QStringLiteral(""));
        label_min = new QLabel(centralWidget);
        label_min->setObjectName(QStringLiteral("label_min"));
        label_min->setGeometry(QRect(750, 495, 25, 16));
        dial_letraMin = new QLabel(centralWidget);
        dial_letraMin->setObjectName(QStringLiteral("dial_letraMin"));
        dial_letraMin->setGeometry(QRect(775, 495, 21, 16));
        dial_letraMin->setFont(font1);
        label_imagIntro = new QLabel(centralWidget);
        label_imagIntro->setObjectName(QStringLiteral("label_imagIntro"));
        label_imagIntro->setGeometry(QRect(370, 30, 61, 61));
        label_imagIntro->setAutoFillBackground(true);
        label_imagIntro->setFrameShape(QFrame::WinPanel);
        label_imagIntro->setLineWidth(0);
        label_imagIntro->setPixmap(QPixmap(QString::fromUtf8(":/iconos/imagenes/module_RN.png")));
        label_imagIntro->setScaledContents(true);
        label_imagIntro->setWordWrap(false);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(760, 510, 31, 16));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        label_4->setFont(font2);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(650, 510, 31, 16));
        label_5->setFont(font2);
        label_sammicBLE = new QLabel(centralWidget);
        label_sammicBLE->setObjectName(QStringLiteral("label_sammicBLE"));
        label_sammicBLE->setGeometry(QRect(16, 510, 61, 51));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setWeight(75);
        label_sammicBLE->setFont(font3);
        label_sammicBLE->setAutoFillBackground(false);
        label_sammicBLE->setFrameShape(QFrame::Box);
        label_sammicBLE->setScaledContents(true);
        label_sammicBLE->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        button_bleconfig = new QPushButton(centralWidget);
        button_bleconfig->setObjectName(QStringLiteral("button_bleconfig"));
        button_bleconfig->setGeometry(QRect(20, 530, 53, 21));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button_bleconfig->sizePolicy().hasHeightForWidth());
        button_bleconfig->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setPointSize(6);
        font4.setBold(true);
        font4.setWeight(75);
        button_bleconfig->setFont(font4);
        button_bleconfig->setStyleSheet(QLatin1String("background-color: rgb(181, 161, 181);\n"
""));
        show_UUID = new QPlainTextEdit(centralWidget);
        show_UUID->setObjectName(QStringLiteral("show_UUID"));
        show_UUID->setGeometry(QRect(100, 520, 261, 34));
        QFont font5;
        font5.setPointSize(7);
        show_UUID->setFont(font5);
        show_UUID->setStyleSheet(QStringLiteral("selection-background-color: rgb(85, 85, 255);"));
        show_UUID->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        show_UUID->setUndoRedoEnabled(false);
        show_UUID->setReadOnly(true);
        show_UUID->setCursorWidth(1);
        show_UUID->setCenterOnScroll(false);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(110, 505, 171, 16));
        QFont font6;
        font6.setPointSize(7);
        font6.setBold(true);
        font6.setWeight(75);
        label_6->setFont(font6);
        label_6->setTextFormat(Qt::RichText);
        button_blenotify = new QPushButton(centralWidget);
        button_blenotify->setObjectName(QStringLiteral("button_blenotify"));
        button_blenotify->setGeometry(QRect(6, 465, 91, 23));
        button_blenotify->setAutoDefault(false);
        button_blenotify->setFlat(false);
        label_notificacion = new QLabel(centralWidget);
        label_notificacion->setObjectName(QStringLiteral("label_notificacion"));
        label_notificacion->setGeometry(QRect(110, 470, 321, 20));
        QFont font7;
        font7.setPointSize(11);
        label_notificacion->setFont(font7);
        label_notificacion->setFrameShape(QFrame::WinPanel);
        label_notificacion->setFrameShadow(QFrame::Sunken);
        button_svideStart = new QPushButton(centralWidget);
        button_svideStart->setObjectName(QStringLiteral("button_svideStart"));
        button_svideStart->setGeometry(QRect(830, 480, 61, 51));
        button_svideStart->setAutoDefault(false);
        button_svideStart->setDefault(false);
        label_intro_2 = new QLabel(centralWidget);
        label_intro_2->setObjectName(QStringLiteral("label_intro_2"));
        label_intro_2->setGeometry(QRect(20, 10, 311, 16));
        label_intro_2->setFont(font);
        label_intro_2->setStyleSheet(QLatin1String("color: rgb(170, 0, 0);\n"
"font: 75 11pt \"Papyrus\";"));
        label_intro_2->setTextFormat(Qt::AutoText);
        label_ordenCiclo = new QLabel(centralWidget);
        label_ordenCiclo->setObjectName(QStringLiteral("label_ordenCiclo"));
        label_ordenCiclo->setGeometry(QRect(450, 470, 131, 81));
        label_ordenCiclo->setFont(font7);
        label_ordenCiclo->setFrameShape(QFrame::WinPanel);
        label_ordenCiclo->setFrameShadow(QFrame::Sunken);
        label_ordenCiclo->setLineWidth(1);
        label_ordenCiclo->setMidLineWidth(0);
        label_ordenCiclo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        guiSVide->raise();
        serialComButton->raise();
        label_intro->raise();
        dial_temp->raise();
        dial_min->raise();
        label_temp->raise();
        dial_letraC->raise();
        label_min->raise();
        dial_letraMin->raise();
        label_imagIntro->raise();
        label_4->raise();
        label_5->raise();
        label_sammicBLE->raise();
        button_bleconfig->raise();
        show_UUID->raise();
        label_6->raise();
        button_blenotify->raise();
        label_notificacion->raise();
        button_svideStart->raise();
        label_intro_2->raise();
        label_ordenCiclo->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(dial_min, SIGNAL(valueChanged(int)), label_min, SLOT(setNum(int)));
        QObject::connect(dial_temp, SIGNAL(valueChanged(int)), label_temp, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        serialComButton->setText(QString());
        label->setText(QApplication::translate("MainWindow", "comando: ", 0));
        label_2->setText(QApplication::translate("MainWindow", "conexi\303\263n con :", 0));
        label_3->setText(QApplication::translate("MainWindow", "baudios bps  :", 0));
        label_intro->setText(QApplication::translate("MainWindow", "SAMMIC   SVide      - GUI -", 0));
        label_temp->setText(QApplication::translate("MainWindow", "25", 0));
        dial_letraC->setText(QApplication::translate("MainWindow", "\302\272C", 0));
        label_min->setText(QApplication::translate("MainWindow", "0", 0));
        dial_letraMin->setText(QApplication::translate("MainWindow", "min", 0));
        label_imagIntro->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "SET", 0));
        label_5->setText(QApplication::translate("MainWindow", "SET", 0));
        label_sammicBLE->setText(QApplication::translate("MainWindow", "Sammic", 0));
        button_bleconfig->setText(QApplication::translate("MainWindow", "BLE config", 0));
        show_UUID->setPlainText(QString());
        label_6->setText(QApplication::translate("MainWindow", "BLE caracter\303\255sticas Sammic", 0));
        button_blenotify->setText(QApplication::translate("MainWindow", "BLE Notificacion", 0));
        label_notificacion->setText(QApplication::translate("MainWindow", "notificacion: ----", 0));
        button_svideStart->setText(QApplication::translate("MainWindow", "start", 0));
        label_intro_2->setText(QApplication::translate("MainWindow", "SAMMIC   SVide      - BLE comunicaci\303\263n Test -", 0));
        label_ordenCiclo->setText(QApplication::translate("MainWindow", "Orden para Svide\n"
"\n"
"agua set: ---\n"
"sonda set: ---\n"
"tiempo set: ---", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
