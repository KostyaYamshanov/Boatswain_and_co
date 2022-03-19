/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *loglabel;
    QLabel *paslabel;
    QLabel *label;
    QLabel *surnlabel;
    QLabel *emaillabel;
    QLabel *HelloLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loglabel = new QLabel(centralwidget);
        loglabel->setObjectName(QString::fromUtf8("loglabel"));
        loglabel->setGeometry(QRect(10, 250, 191, 31));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loglabel->sizePolicy().hasHeightForWidth());
        loglabel->setSizePolicy(sizePolicy);
        paslabel = new QLabel(centralwidget);
        paslabel->setObjectName(QString::fromUtf8("paslabel"));
        paslabel->setGeometry(QRect(10, 300, 211, 16));
        sizePolicy.setHeightForWidth(paslabel->sizePolicy().hasHeightForWidth());
        paslabel->setSizePolicy(sizePolicy);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 230, 49, 16));
        surnlabel = new QLabel(centralwidget);
        surnlabel->setObjectName(QString::fromUtf8("surnlabel"));
        surnlabel->setGeometry(QRect(10, 280, 181, 16));
        sizePolicy.setHeightForWidth(surnlabel->sizePolicy().hasHeightForWidth());
        surnlabel->setSizePolicy(sizePolicy);
        emaillabel = new QLabel(centralwidget);
        emaillabel->setObjectName(QString::fromUtf8("emaillabel"));
        emaillabel->setGeometry(QRect(10, 320, 201, 16));
        sizePolicy.setHeightForWidth(emaillabel->sizePolicy().hasHeightForWidth());
        emaillabel->setSizePolicy(sizePolicy);
        HelloLabel = new QLabel(centralwidget);
        HelloLabel->setObjectName(QString::fromUtf8("HelloLabel"));
        HelloLabel->setGeometry(QRect(10, 10, 141, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loglabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        paslabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Debug", nullptr));
        surnlabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        emaillabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        HelloLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
