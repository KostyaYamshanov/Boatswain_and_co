#include "signup.h"
#include "ui_signup.h"
#include <QString>

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    Icon            IconHandler;
    IconHandler.SetIcon (this);

    ui->setupUi(this);
    ui->WarnLabel->setVisible(false);
    this->setWindowTitle(QCoreApplication::translate("Authorization", "Sign Up", nullptr));
    ui->TitleLabel->setText(QCoreApplication::translate("Authorization", "Enter your credentials", nullptr));
    ui->NameLabel->setText(QCoreApplication::translate("Authorization", "Name:", nullptr));
    ui->SecondNameLabel->setText(QCoreApplication::translate("Authorization", "Surname:", nullptr));
    ui->EmailLabel->setText(QCoreApplication::translate("Authorization", "E-mail:", nullptr));
    ui->PassLabel->setText(QCoreApplication::translate("Authorization", "Password:", nullptr));
    ui->PassRepeatLabel->setText(QCoreApplication::translate("Authorization", "Password again:", nullptr));
    ui->pbSignUp->setText(QCoreApplication::translate("Authorization", "Sign Up!", nullptr));
    ui->PassField->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->RepPassField->setEchoMode(QLineEdit::PasswordEchoOnEdit);

}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pbSignUp_clicked()
{
    RestoreFields ();
    if (ui->NameField->text().isEmpty())
    {
        EmptyFieldHandle ("Name");
        ui->NameField->setStyleSheet("border: 1px solid red");
        return;
    }

    if (ui->SecondNameField->text().isEmpty())
    {
        EmptyFieldHandle ("Surname");
        ui->SecondNameField->setStyleSheet("border: 1px solid red");
        return;
    }

    if (ui->EmailField->text().isEmpty())
    {
        EmptyFieldHandle ("E-mail");
        ui->EmailField->setStyleSheet("border: 1px solid red");
        return;
    }

    if (ui->PassField->text().isEmpty())
    {
        EmptyFieldHandle ("Password");
        ui->PassField->setStyleSheet("border: 1px solid red");
        return;
    }

    if (ui->RepPassField->text().isEmpty())
    {
        EmptyFieldHandle ("Password");
        ui->RepPassField->setStyleSheet("border: 1px solid red");
        return;
    }

    if (QString::compare(ui->PassField->text(),
                         ui->RepPassField->text(),
                         Qt::CaseInsensitive) != 0)
    {
       ui->pbSignUp->setGeometry(QRect(70, 250, 80, 24));
       ui->WarnLabel->setVisible(true);
       ui->WarnLabel->setText("Passwords do not match!");
       return;
    }
    emit SignUpFinishSignal (ui->NameField->text(),
                             ui->SecondNameField->text(),
                             ui->EmailField->text(),
                             ui->PassField->text());
    close ();
}

void SignUp::EmptyFieldHandle (std::string Field)
{
    std::string ErrMsgTail = " must not be empty!";
    std::string ErrMsg = Field + ErrMsgTail;

    ui->pbSignUp->setGeometry(QRect(70, 250, 80, 24));
    ui->WarnLabel->setVisible(true);
    ui->WarnLabel->setText(QString::fromStdString(ErrMsg));
    return;
}

void SignUp::RestoreFields ()
{
    ui->pbSignUp->setGeometry(QRect(70, 220, 80, 24));
    ui->WarnLabel->setVisible(false);
    ui->NameField->setStyleSheet("border: 1px solid black");
    ui->SecondNameField->setStyleSheet("border: 1px solid black");
    ui->EmailField->setStyleSheet("border: 1px solid black");
    ui->PassField->setStyleSheet("border: 1px solid black");
    ui->RepPassField->setStyleSheet("border: 1px solid black");
    return;
}


void SignUp::on_NameField_selectionChanged()
{
    RestoreFields ();
    return;
}


void SignUp::on_SecondNameField_selectionChanged()
{
    RestoreFields ();
    return;
}


void SignUp::on_EmailField_selectionChanged()
{
    RestoreFields ();
    return;
}


void SignUp::on_PassField_selectionChanged()
{
    RestoreFields ();
    return;
}


void SignUp::on_RepPassField_selectionChanged()
{
    RestoreFields ();
    return;
}

