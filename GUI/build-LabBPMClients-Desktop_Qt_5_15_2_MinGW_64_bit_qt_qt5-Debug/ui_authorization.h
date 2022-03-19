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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Authorization
{
public:
    QPushButton *pbLogin;
    QPushButton *pbSignUp;

    void setupUi(QDialog *Authorization)
    {
        if (Authorization->objectName().isEmpty())
            Authorization->setObjectName(QString::fromUtf8("Authorization"));
        Authorization->resize(240, 320);
        pbLogin = new QPushButton(Authorization);
        pbLogin->setObjectName(QString::fromUtf8("pbLogin"));
        pbLogin->setGeometry(QRect(20, 220, 80, 24));
        pbSignUp = new QPushButton(Authorization);
        pbSignUp->setObjectName(QString::fromUtf8("pbSignUp"));
        pbSignUp->setGeometry(QRect(130, 220, 80, 24));

        retranslateUi(Authorization);

        QMetaObject::connectSlotsByName(Authorization);
    } // setupUi

    void retranslateUi(QDialog *Authorization)
    {
        Authorization->setWindowTitle(QCoreApplication::translate("Authorization", "Authorization", nullptr));
        pbLogin->setText(QCoreApplication::translate("Authorization", "Login", nullptr));
        pbSignUp->setText(QCoreApplication::translate("Authorization", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Authorization: public Ui_Authorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATION_H
