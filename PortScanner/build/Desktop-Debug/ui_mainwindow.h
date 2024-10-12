/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QPushButton *startButton;
    QListWidget *OutputWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *startSpinBox;
    QLabel *label_3;
    QSpinBox *EndSpinBox;
    QLabel *label_4;
    QSpinBox *threadSpinBox;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *ipLine;
    QMenuBar *menubar;
    QMenu *menuPortScanner;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(647, 608);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(70, 450, 481, 23));
        progressBar->setValue(24);
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(260, 20, 80, 25));
        OutputWidget = new QListWidget(centralwidget);
        OutputWidget->setObjectName(QString::fromUtf8("OutputWidget"));
        OutputWidget->setGeometry(QRect(180, 220, 256, 192));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 120, 431, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        startSpinBox = new QSpinBox(horizontalLayoutWidget);
        startSpinBox->setObjectName(QString::fromUtf8("startSpinBox"));

        horizontalLayout->addWidget(startSpinBox);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        EndSpinBox = new QSpinBox(horizontalLayoutWidget);
        EndSpinBox->setObjectName(QString::fromUtf8("EndSpinBox"));

        horizontalLayout->addWidget(EndSpinBox);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        threadSpinBox = new QSpinBox(horizontalLayoutWidget);
        threadSpinBox->setObjectName(QString::fromUtf8("threadSpinBox"));

        horizontalLayout->addWidget(threadSpinBox);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(60, 40, 481, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        ipLine = new QLineEdit(horizontalLayoutWidget_3);
        ipLine->setObjectName(QString::fromUtf8("ipLine"));

        horizontalLayout_3->addWidget(ipLine);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 647, 22));
        menuPortScanner = new QMenu(menubar);
        menuPortScanner->setObjectName(QString::fromUtf8("menuPortScanner"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPortScanner->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "StartPort :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "EndPort :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "    Threads  :", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "IP:", nullptr));
        menuPortScanner->setTitle(QCoreApplication::translate("MainWindow", "PortScanner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
