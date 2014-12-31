/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
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
    QLabel *logo_sammic;
    QLabel *label_intro;
    QDial *dial_temp;
    QDial *dial_min;
    QLabel *label_temp;
    QLabel *dial_letraC;
    QLabel *label_min;
    QLabel *dial_letraMin;
    QLabel *label_imagBLE;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *button_bleconfig;
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
        guiSVide->setGeometry(QRect(449, 30, 430, 400));
        guiSVide->setResizeMode(QQuickWidget::SizeRootObjectToView);
        serialComButton = new QPushButton(centralWidget);
        serialComButton->setObjectName(QStringLiteral("serialComButton"));
        serialComButton->setGeometry(QRect(370, 10, 56, 56));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/iconos/imagenes/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/iconos/imagenes/connect.png"), QSize(), QIcon::Normal, QIcon::On);
        serialComButton->setIcon(icon1);
        serialComButton->setIconSize(QSize(50, 50));
        serialComButton->setAutoDefault(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 80, 421, 351));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        consola = new QTextEdit(layoutWidget);
        consola->setObjectName(QStringLiteral("consola"));
        consola->setStyleSheet(QStringLiteral("selection-background-color: rgb(121, 124, 255);"));
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
        layoutWidget1->setGeometry(QRect(110, 10, 251, 64));
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

        logo_sammic = new QLabel(centralWidget);
        logo_sammic->setObjectName(QStringLiteral("logo_sammic"));
        logo_sammic->setGeometry(QRect(840, 520, 60, 60));
        logo_sammic->setStyleSheet(QStringLiteral("image: url(:/iconos/imagenes/logo_sammic.png);"));
        logo_sammic->setFrameShape(QFrame::StyledPanel);
        logo_sammic->setScaledContents(true);
        logo_sammic->setWordWrap(true);
        label_intro = new QLabel(centralWidget);
        label_intro->setObjectName(QStringLiteral("label_intro"));
        label_intro->setGeometry(QRect(470, 10, 191, 16));
        QFont font;
        font.setFamily(QStringLiteral("Phosphate"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_intro->setFont(font);
        label_intro->setStyleSheet(QLatin1String("\n"
"color: rgb(170, 0, 0);\n"
"font: 16pt \"Phosphate\";"));
        dial_temp = new QDial(centralWidget);
        dial_temp->setObjectName(QStringLiteral("dial_temp"));
        dial_temp->setGeometry(QRect(654, 450, 90, 90));
        dial_temp->setStyleSheet(QStringLiteral("background-color: rgb(250, 10, 24);"));
        dial_temp->setMinimum(20);
        dial_temp->setMaximum(100);
        dial_temp->setTracking(true);
        dial_temp->setWrapping(false);
        dial_temp->setNotchesVisible(true);
        dial_min = new QDial(centralWidget);
        dial_min->setObjectName(QStringLiteral("dial_min"));
        dial_min->setGeometry(QRect(544, 450, 90, 90));
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
        label_temp->setGeometry(QRect(679, 485, 25, 16));
        dial_letraC = new QLabel(centralWidget);
        dial_letraC->setObjectName(QStringLiteral("dial_letraC"));
        dial_letraC->setGeometry(QRect(708, 485, 21, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        dial_letraC->setFont(font1);
        dial_letraC->setStyleSheet(QStringLiteral(""));
        label_min = new QLabel(centralWidget);
        label_min->setObjectName(QStringLiteral("label_min"));
        label_min->setGeometry(QRect(570, 485, 25, 16));
        dial_letraMin = new QLabel(centralWidget);
        dial_letraMin->setObjectName(QStringLiteral("dial_letraMin"));
        dial_letraMin->setGeometry(QRect(595, 485, 21, 16));
        dial_letraMin->setFont(font1);
        label_imagBLE = new QLabel(centralWidget);
        label_imagBLE->setObjectName(QStringLiteral("label_imagBLE"));
        label_imagBLE->setGeometry(QRect(10, 10, 61, 61));
        label_imagBLE->setAutoFillBackground(true);
        label_imagBLE->setFrameShape(QFrame::WinPanel);
        label_imagBLE->setLineWidth(0);
        label_imagBLE->setPixmap(QPixmap(QString::fromUtf8(":/iconos/imagenes/module_RN.png")));
        label_imagBLE->setScaledContents(true);
        label_imagBLE->setWordWrap(false);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(580, 500, 31, 16));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        label_4->setFont(font2);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(690, 500, 31, 16));
        label_5->setFont(font2);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(366, 510, 61, 51));
        label_6->setFont(font1);
        label_6->setAutoFillBackground(false);
        label_6->setFrameShape(QFrame::Box);
        label_6->setScaledContents(true);
        label_6->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        button_bleconfig = new QPushButton(centralWidget);
        button_bleconfig->setObjectName(QStringLiteral("button_bleconfig"));
        button_bleconfig->setGeometry(QRect(370, 530, 53, 21));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setWeight(75);
        button_bleconfig->setFont(font3);
        button_bleconfig->setStyleSheet(QLatin1String("background-color: rgb(181, 161, 181);\n"
"alternate-background-color: rgb(168, 255, 53);"));
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        guiSVide->raise();
        serialComButton->raise();
        logo_sammic->raise();
        label_intro->raise();
        dial_temp->raise();
        dial_min->raise();
        label_temp->raise();
        dial_letraC->raise();
        label_min->raise();
        dial_letraMin->raise();
        label_imagBLE->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        button_bleconfig->raise();
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
        logo_sammic->setText(QString());
        label_intro->setText(QApplication::translate("MainWindow", "SAMMIC   SVide       BLE TEST", 0));
        label_temp->setText(QApplication::translate("MainWindow", "20", 0));
        dial_letraC->setText(QApplication::translate("MainWindow", "\302\272C", 0));
        label_min->setText(QApplication::translate("MainWindow", "0", 0));
        dial_letraMin->setText(QApplication::translate("MainWindow", "min", 0));
        label_imagBLE->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "SET", 0));
        label_5->setText(QApplication::translate("MainWindow", "SET", 0));
        label_6->setText(QApplication::translate("MainWindow", "Sammic", 0));
        button_bleconfig->setText(QApplication::translate("MainWindow", "BLE config", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
