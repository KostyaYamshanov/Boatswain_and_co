/********************************************************************************
** Form generated from reading UI file 'authorization.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATION_H
#define UI_AUTHORIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Authorization
{
public:
    QPushButton *pbLogin;
    QPushButton *pbSignUp;
    QLabel *WarnLabel;
    QLabel *HeaderLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *LogLabel;
    QLineEdit *LogField;
    QHBoxLayout *horizontalLayout_2;
    QLabel *PassLabel;
    QLineEdit *PassField;

    void setupUi(QDialog *Authorization)
    {
        if (Authorization->objectName().isEmpty())
            Authorization->setObjectName(QString::fromUtf8("Authorization"));
        Authorization->resize(240, 320);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Authorization->sizePolicy().hasHeightForWidth());
        Authorization->setSizePolicy(sizePolicy);
        pbLogin = new QPushButton(Authorization);
        pbLogin->setObjectName(QString::fromUtf8("pbLogin"));
        pbLogin->setGeometry(QRect(20, 170, 80, 24));
        pbSignUp = new QPushButton(Authorization);
        pbSignUp->setObjectName(QString::fromUtf8("pbSignUp"));
        pbSignUp->setGeometry(QRect(130, 170, 80, 24));
        WarnLabel = new QLabel(Authorization);
        WarnLabel->setObjectName(QString::fromUtf8("WarnLabel"));
        WarnLabel->setGeometry(QRect(28, 165, 181, 31));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(227, 227, 227, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(160, 160, 160, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush6(QColor(105, 105, 105, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush7(QColor(0, 120, 215, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        QBrush brush8(QColor(0, 0, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush8);
        QBrush brush9(QColor(255, 0, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush9);
        QBrush brush10(QColor(245, 245, 245, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        QBrush brush11(QColor(0, 0, 0, 255));
        brush11.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush11);
        QBrush brush12(QColor(255, 255, 220, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush12);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush5);
        QBrush brush13(QColor(0, 0, 0, 128));
        brush13.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        QBrush brush14(QColor(0, 0, 0, 255));
        brush14.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush14);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        QBrush brush15(QColor(120, 120, 120, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        QBrush brush16(QColor(247, 247, 247, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        QBrush brush17(QColor(0, 0, 0, 255));
        brush17.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush17);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush12);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        WarnLabel->setPalette(palette);
        QFont font;
        font.setPointSize(10);
        font.setUnderline(true);
        WarnLabel->setFont(font);
        WarnLabel->setCursor(QCursor(Qt::ArrowCursor));
        WarnLabel->setAlignment(Qt::AlignCenter);
        HeaderLabel = new QLabel(Authorization);
        HeaderLabel->setObjectName(QString::fromUtf8("HeaderLabel"));
        HeaderLabel->setGeometry(QRect(10, 0, 221, 20));
        HeaderLabel->setAlignment(Qt::AlignCenter);
        widget = new QWidget(Authorization);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 60, 211, 60));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LogLabel = new QLabel(widget);
        LogLabel->setObjectName(QString::fromUtf8("LogLabel"));

        horizontalLayout->addWidget(LogLabel);

        LogField = new QLineEdit(widget);
        LogField->setObjectName(QString::fromUtf8("LogField"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LogField->sizePolicy().hasHeightForWidth());
        LogField->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(LogField);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        PassLabel = new QLabel(widget);
        PassLabel->setObjectName(QString::fromUtf8("PassLabel"));

        horizontalLayout_2->addWidget(PassLabel);

        PassField = new QLineEdit(widget);
        PassField->setObjectName(QString::fromUtf8("PassField"));
        sizePolicy1.setHeightForWidth(PassField->sizePolicy().hasHeightForWidth());
        PassField->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(PassField);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Authorization);

        QMetaObject::connectSlotsByName(Authorization);
    } // setupUi

    void retranslateUi(QDialog *Authorization)
    {
        Authorization->setWindowTitle(QCoreApplication::translate("Authorization", "Dialog", nullptr));
        pbLogin->setText(QCoreApplication::translate("Authorization", "PushButton", nullptr));
        pbSignUp->setText(QCoreApplication::translate("Authorization", "PushButton", nullptr));
        WarnLabel->setText(QCoreApplication::translate("Authorization", "TextLabel", nullptr));
        HeaderLabel->setText(QCoreApplication::translate("Authorization", "TextLabel", nullptr));
        LogLabel->setText(QCoreApplication::translate("Authorization", "TextLabel", nullptr));
        PassLabel->setText(QCoreApplication::translate("Authorization", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Authorization: public Ui_Authorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATION_H
