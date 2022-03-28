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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "ghpainter.h"
#include "sectors.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *lSectOne;
    GreenHouse *SectionOne;
    SectorWidget *Sector_1;
    QPushButton *pbSector_1;
    SectorWidget *Sector_2;
    QPushButton *pbSector_2;
    SectorWidget *Sector_3;
    QPushButton *pbSector_3;
    SectorWidget *Sector_4;
    QPushButton *pbSector_4;
    SectorWidget *Sector_5;
    QPushButton *pbSector_5;
    SectorWidget *Sector_6;
    QPushButton *pbSector_6;
    SectorWidget *Sector_7;
    QPushButton *pbSector_7;
    SectorWidget *Sector_8;
    QPushButton *pbSector_8;
    SectorWidget *Sector_9;
    QPushButton *pbSector_9;
    SectorWidget *Sector_10;
    QPushButton *pbSector_10;
    SectorWidget *Sector_11;
    QPushButton *pbSector_11;
    SectorWidget *Sector_12;
    QPushButton *pbSector_12;
    QLabel *lSectTwo;
    GreenHouse *SectionTwo;
    SectorWidget *Sector_2_2;
    QPushButton *pbSector_2_2;
    SectorWidget *Sector_2_12;
    QPushButton *pbSector_2_12;
    SectorWidget *Sector_2_9;
    QPushButton *pbSector_2_9;
    SectorWidget *Sector_2_4;
    QPushButton *pbSector_2_4;
    SectorWidget *Sector_2_6;
    QPushButton *pbSector_2_6;
    SectorWidget *Sector_2_8;
    QPushButton *pbSector_2_8;
    SectorWidget *Sector_2_10;
    QPushButton *pbSector_2_10;
    SectorWidget *Sector_2_11;
    QPushButton *pbSector_2_11;
    SectorWidget *Sector_2_1;
    QPushButton *pbSector_2_1;
    SectorWidget *Sector_2_5;
    QPushButton *pbSector_2_5;
    SectorWidget *Sector_2_3;
    QPushButton *pbSector_2_3;
    SectorWidget *Sector_2_7;
    QPushButton *pbSector_2_7;
    QLabel *SectorNum;
    QWidget *gridLayoutWidget;
    QGridLayout *InfoBox;
    QLabel *lPlantVar;
    QLabel *lPlaceSize;
    QLineEdit *lePlantVar;
    QLabel *lSpecie;
    QLabel *lAmount;
    QLineEdit *leAmount;
    QLineEdit *leSpecie;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leWidth;
    QLabel *lMultiplier;
    QLineEdit *leHeight;
    QLabel *lCentimeter;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbRefresh;
    QPushButton *pbSave;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1309, 656);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setWindowOpacity(1.000000000000000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lSectOne = new QLabel(centralwidget);
        lSectOne->setObjectName(QString::fromUtf8("lSectOne"));
        lSectOne->setGeometry(QRect(20, 10, 81, 16));
        lSectOne->setFont(font);
        SectionOne = new GreenHouse(centralwidget);
        SectionOne->setObjectName(QString::fromUtf8("SectionOne"));
        SectionOne->setGeometry(QRect(30, 30, 841, 111));
        Sector_1 = new SectorWidget(SectionOne);
        Sector_1->setObjectName(QString::fromUtf8("Sector_1"));
        Sector_1->setGeometry(QRect(10, 10, 120, 31));
        pbSector_1 = new QPushButton(Sector_1);
        pbSector_1->setObjectName(QString::fromUtf8("pbSector_1"));
        pbSector_1->setGeometry(QRect(20, 0, 80, 24));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pbSector_1->sizePolicy().hasHeightForWidth());
        pbSector_1->setSizePolicy(sizePolicy1);
        pbSector_1->setCursor(QCursor(Qt::PointingHandCursor));
        pbSector_1->setAutoFillBackground(true);
        Sector_2 = new SectorWidget(SectionOne);
        Sector_2->setObjectName(QString::fromUtf8("Sector_2"));
        Sector_2->setGeometry(QRect(10, 40, 120, 31));
        pbSector_2 = new QPushButton(Sector_2);
        pbSector_2->setObjectName(QString::fromUtf8("pbSector_2"));
        pbSector_2->setGeometry(QRect(20, 10, 80, 24));
        Sector_3 = new SectorWidget(SectionOne);
        Sector_3->setObjectName(QString::fromUtf8("Sector_3"));
        Sector_3->setGeometry(QRect(10, 80, 120, 31));
        pbSector_3 = new QPushButton(Sector_3);
        pbSector_3->setObjectName(QString::fromUtf8("pbSector_3"));
        pbSector_3->setGeometry(QRect(20, 0, 80, 24));
        Sector_4 = new SectorWidget(SectionOne);
        Sector_4->setObjectName(QString::fromUtf8("Sector_4"));
        Sector_4->setGeometry(QRect(150, 10, 120, 31));
        pbSector_4 = new QPushButton(Sector_4);
        pbSector_4->setObjectName(QString::fromUtf8("pbSector_4"));
        pbSector_4->setGeometry(QRect(10, 0, 80, 24));
        Sector_5 = new SectorWidget(SectionOne);
        Sector_5->setObjectName(QString::fromUtf8("Sector_5"));
        Sector_5->setGeometry(QRect(150, 40, 120, 31));
        pbSector_5 = new QPushButton(Sector_5);
        pbSector_5->setObjectName(QString::fromUtf8("pbSector_5"));
        pbSector_5->setGeometry(QRect(20, 0, 80, 24));
        Sector_6 = new SectorWidget(SectionOne);
        Sector_6->setObjectName(QString::fromUtf8("Sector_6"));
        Sector_6->setGeometry(QRect(150, 70, 120, 31));
        pbSector_6 = new QPushButton(Sector_6);
        pbSector_6->setObjectName(QString::fromUtf8("pbSector_6"));
        pbSector_6->setGeometry(QRect(10, 0, 80, 24));
        Sector_7 = new SectorWidget(SectionOne);
        Sector_7->setObjectName(QString::fromUtf8("Sector_7"));
        Sector_7->setGeometry(QRect(300, 10, 120, 31));
        pbSector_7 = new QPushButton(Sector_7);
        pbSector_7->setObjectName(QString::fromUtf8("pbSector_7"));
        pbSector_7->setGeometry(QRect(30, 10, 80, 24));
        Sector_8 = new SectorWidget(SectionOne);
        Sector_8->setObjectName(QString::fromUtf8("Sector_8"));
        Sector_8->setGeometry(QRect(300, 40, 120, 31));
        pbSector_8 = new QPushButton(Sector_8);
        pbSector_8->setObjectName(QString::fromUtf8("pbSector_8"));
        pbSector_8->setGeometry(QRect(10, 0, 80, 24));
        Sector_9 = new SectorWidget(SectionOne);
        Sector_9->setObjectName(QString::fromUtf8("Sector_9"));
        Sector_9->setGeometry(QRect(300, 70, 120, 31));
        pbSector_9 = new QPushButton(Sector_9);
        pbSector_9->setObjectName(QString::fromUtf8("pbSector_9"));
        pbSector_9->setGeometry(QRect(20, 0, 80, 24));
        Sector_10 = new SectorWidget(SectionOne);
        Sector_10->setObjectName(QString::fromUtf8("Sector_10"));
        Sector_10->setGeometry(QRect(440, 10, 120, 31));
        pbSector_10 = new QPushButton(Sector_10);
        pbSector_10->setObjectName(QString::fromUtf8("pbSector_10"));
        pbSector_10->setGeometry(QRect(30, 10, 80, 24));
        Sector_11 = new SectorWidget(SectionOne);
        Sector_11->setObjectName(QString::fromUtf8("Sector_11"));
        Sector_11->setGeometry(QRect(440, 40, 120, 31));
        pbSector_11 = new QPushButton(Sector_11);
        pbSector_11->setObjectName(QString::fromUtf8("pbSector_11"));
        pbSector_11->setGeometry(QRect(20, 10, 80, 24));
        Sector_12 = new SectorWidget(SectionOne);
        Sector_12->setObjectName(QString::fromUtf8("Sector_12"));
        Sector_12->setGeometry(QRect(440, 70, 120, 31));
        pbSector_12 = new QPushButton(Sector_12);
        pbSector_12->setObjectName(QString::fromUtf8("pbSector_12"));
        pbSector_12->setGeometry(QRect(30, 10, 80, 24));
        lSectTwo = new QLabel(centralwidget);
        lSectTwo->setObjectName(QString::fromUtf8("lSectTwo"));
        lSectTwo->setGeometry(QRect(10, 150, 49, 16));
        lSectTwo->setFont(font);
        SectionTwo = new GreenHouse(centralwidget);
        SectionTwo->setObjectName(QString::fromUtf8("SectionTwo"));
        SectionTwo->setGeometry(QRect(10, 170, 841, 141));
        Sector_2_2 = new SectorWidget(SectionTwo);
        Sector_2_2->setObjectName(QString::fromUtf8("Sector_2_2"));
        Sector_2_2->setGeometry(QRect(30, 50, 120, 31));
        pbSector_2_2 = new QPushButton(Sector_2_2);
        pbSector_2_2->setObjectName(QString::fromUtf8("pbSector_2_2"));
        pbSector_2_2->setGeometry(QRect(20, 0, 80, 24));
        Sector_2_12 = new SectorWidget(SectionTwo);
        Sector_2_12->setObjectName(QString::fromUtf8("Sector_2_12"));
        Sector_2_12->setGeometry(QRect(460, 80, 120, 31));
        pbSector_2_12 = new QPushButton(Sector_2_12);
        pbSector_2_12->setObjectName(QString::fromUtf8("pbSector_2_12"));
        pbSector_2_12->setGeometry(QRect(20, 0, 80, 24));
        Sector_2_9 = new SectorWidget(SectionTwo);
        Sector_2_9->setObjectName(QString::fromUtf8("Sector_2_9"));
        Sector_2_9->setGeometry(QRect(320, 80, 120, 31));
        pbSector_2_9 = new QPushButton(Sector_2_9);
        pbSector_2_9->setObjectName(QString::fromUtf8("pbSector_2_9"));
        pbSector_2_9->setGeometry(QRect(20, 0, 80, 24));
        Sector_2_4 = new SectorWidget(SectionTwo);
        Sector_2_4->setObjectName(QString::fromUtf8("Sector_2_4"));
        Sector_2_4->setGeometry(QRect(170, 20, 120, 31));
        pbSector_2_4 = new QPushButton(Sector_2_4);
        pbSector_2_4->setObjectName(QString::fromUtf8("pbSector_2_4"));
        pbSector_2_4->setGeometry(QRect(20, 0, 80, 24));
        Sector_2_6 = new SectorWidget(SectionTwo);
        Sector_2_6->setObjectName(QString::fromUtf8("Sector_2_6"));
        Sector_2_6->setGeometry(QRect(170, 80, 120, 31));
        pbSector_2_6 = new QPushButton(Sector_2_6);
        pbSector_2_6->setObjectName(QString::fromUtf8("pbSector_2_6"));
        pbSector_2_6->setGeometry(QRect(20, 10, 80, 24));
        Sector_2_8 = new SectorWidget(SectionTwo);
        Sector_2_8->setObjectName(QString::fromUtf8("Sector_2_8"));
        Sector_2_8->setGeometry(QRect(320, 50, 120, 31));
        pbSector_2_8 = new QPushButton(Sector_2_8);
        pbSector_2_8->setObjectName(QString::fromUtf8("pbSector_2_8"));
        pbSector_2_8->setGeometry(QRect(10, 0, 80, 24));
        Sector_2_10 = new SectorWidget(SectionTwo);
        Sector_2_10->setObjectName(QString::fromUtf8("Sector_2_10"));
        Sector_2_10->setGeometry(QRect(460, 20, 120, 31));
        pbSector_2_10 = new QPushButton(Sector_2_10);
        pbSector_2_10->setObjectName(QString::fromUtf8("pbSector_2_10"));
        pbSector_2_10->setGeometry(QRect(20, 0, 80, 24));
        Sector_2_11 = new SectorWidget(SectionTwo);
        Sector_2_11->setObjectName(QString::fromUtf8("Sector_2_11"));
        Sector_2_11->setGeometry(QRect(460, 50, 120, 31));
        pbSector_2_11 = new QPushButton(Sector_2_11);
        pbSector_2_11->setObjectName(QString::fromUtf8("pbSector_2_11"));
        pbSector_2_11->setGeometry(QRect(30, 0, 80, 24));
        Sector_2_1 = new SectorWidget(SectionTwo);
        Sector_2_1->setObjectName(QString::fromUtf8("Sector_2_1"));
        Sector_2_1->setGeometry(QRect(30, 20, 120, 31));
        pbSector_2_1 = new QPushButton(Sector_2_1);
        pbSector_2_1->setObjectName(QString::fromUtf8("pbSector_2_1"));
        pbSector_2_1->setGeometry(QRect(20, 0, 80, 24));
        Sector_2_5 = new SectorWidget(SectionTwo);
        Sector_2_5->setObjectName(QString::fromUtf8("Sector_2_5"));
        Sector_2_5->setGeometry(QRect(170, 50, 120, 31));
        pbSector_2_5 = new QPushButton(Sector_2_5);
        pbSector_2_5->setObjectName(QString::fromUtf8("pbSector_2_5"));
        pbSector_2_5->setGeometry(QRect(20, 0, 80, 24));
        Sector_2_3 = new SectorWidget(SectionTwo);
        Sector_2_3->setObjectName(QString::fromUtf8("Sector_2_3"));
        Sector_2_3->setGeometry(QRect(30, 90, 120, 31));
        pbSector_2_3 = new QPushButton(Sector_2_3);
        pbSector_2_3->setObjectName(QString::fromUtf8("pbSector_2_3"));
        pbSector_2_3->setGeometry(QRect(30, 10, 80, 24));
        Sector_2_7 = new SectorWidget(SectionTwo);
        Sector_2_7->setObjectName(QString::fromUtf8("Sector_2_7"));
        Sector_2_7->setGeometry(QRect(320, 20, 120, 31));
        pbSector_2_7 = new QPushButton(Sector_2_7);
        pbSector_2_7->setObjectName(QString::fromUtf8("pbSector_2_7"));
        pbSector_2_7->setGeometry(QRect(0, 10, 80, 24));
        SectorNum = new QLabel(centralwidget);
        SectorNum->setObjectName(QString::fromUtf8("SectorNum"));
        SectorNum->setGeometry(QRect(100, 10, 49, 16));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(880, 20, 384, 161));
        InfoBox = new QGridLayout(gridLayoutWidget);
        InfoBox->setObjectName(QString::fromUtf8("InfoBox"));
        InfoBox->setContentsMargins(0, 0, 0, 0);
        lPlantVar = new QLabel(gridLayoutWidget);
        lPlantVar->setObjectName(QString::fromUtf8("lPlantVar"));

        InfoBox->addWidget(lPlantVar, 2, 0, 1, 1);

        lPlaceSize = new QLabel(gridLayoutWidget);
        lPlaceSize->setObjectName(QString::fromUtf8("lPlaceSize"));

        InfoBox->addWidget(lPlaceSize, 4, 0, 1, 1);

        lePlantVar = new QLineEdit(gridLayoutWidget);
        lePlantVar->setObjectName(QString::fromUtf8("lePlantVar"));

        InfoBox->addWidget(lePlantVar, 2, 1, 1, 1);

        lSpecie = new QLabel(gridLayoutWidget);
        lSpecie->setObjectName(QString::fromUtf8("lSpecie"));

        InfoBox->addWidget(lSpecie, 0, 0, 1, 1);

        lAmount = new QLabel(gridLayoutWidget);
        lAmount->setObjectName(QString::fromUtf8("lAmount"));

        InfoBox->addWidget(lAmount, 3, 0, 1, 1);

        leAmount = new QLineEdit(gridLayoutWidget);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));

        InfoBox->addWidget(leAmount, 3, 1, 1, 1);

        leSpecie = new QLineEdit(gridLayoutWidget);
        leSpecie->setObjectName(QString::fromUtf8("leSpecie"));

        InfoBox->addWidget(leSpecie, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leWidth = new QLineEdit(gridLayoutWidget);
        leWidth->setObjectName(QString::fromUtf8("leWidth"));

        horizontalLayout->addWidget(leWidth);

        lMultiplier = new QLabel(gridLayoutWidget);
        lMultiplier->setObjectName(QString::fromUtf8("lMultiplier"));

        horizontalLayout->addWidget(lMultiplier);

        leHeight = new QLineEdit(gridLayoutWidget);
        leHeight->setObjectName(QString::fromUtf8("leHeight"));

        horizontalLayout->addWidget(leHeight);

        lCentimeter = new QLabel(gridLayoutWidget);
        lCentimeter->setObjectName(QString::fromUtf8("lCentimeter"));

        horizontalLayout->addWidget(lCentimeter);


        InfoBox->addLayout(horizontalLayout, 4, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pbRefresh = new QPushButton(gridLayoutWidget);
        pbRefresh->setObjectName(QString::fromUtf8("pbRefresh"));
        pbRefresh->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(pbRefresh);

        pbSave = new QPushButton(gridLayoutWidget);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        pbSave->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(pbSave);


        InfoBox->addLayout(horizontalLayout_2, 5, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1309, 21));
        menubar->setDefaultUp(true);
        menubar->setNativeMenuBar(false);
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
        lSectOne->setText(QCoreApplication::translate("MainWindow", "Section 1", nullptr));
#if QT_CONFIG(tooltip)
        pbSector_1->setToolTip(QCoreApplication::translate("MainWindow", "Sector 1", nullptr));
#endif // QT_CONFIG(tooltip)
        pbSector_1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
#if QT_CONFIG(tooltip)
        pbSector_2->setToolTip(QCoreApplication::translate("MainWindow", "Sector 2", nullptr));
#endif // QT_CONFIG(tooltip)
        pbSector_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
#if QT_CONFIG(tooltip)
        pbSector_3->setToolTip(QCoreApplication::translate("MainWindow", "Sector 3", nullptr));
#endif // QT_CONFIG(tooltip)
        pbSector_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_9->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_10->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_11->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_12->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        lSectTwo->setText(QCoreApplication::translate("MainWindow", "Section 2", nullptr));
        pbSector_2_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_2_12->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_2_9->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_2_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_2_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_2_8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_2_10->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_2_11->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_2_1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_2_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_2_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pbSector_2_7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        SectorNum->setText(QString());
        lPlantVar->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lPlaceSize->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lSpecie->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lAmount->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lMultiplier->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lCentimeter->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
#if QT_CONFIG(tooltip)
        pbRefresh->setToolTip(QCoreApplication::translate("MainWindow", "Update data with database", nullptr));
#endif // QT_CONFIG(tooltip)
        pbRefresh->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
#if QT_CONFIG(tooltip)
        pbSave->setToolTip(QCoreApplication::translate("MainWindow", "Send changes to the Database", nullptr));
#endif // QT_CONFIG(tooltip)
        pbSave->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
