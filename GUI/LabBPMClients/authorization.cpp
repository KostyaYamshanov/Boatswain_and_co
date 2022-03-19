#include "authorization.h"
#include "ui_authorization.h"

Authorization::Authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);
    ui->WarnLabel->setVisible(false);
    this->setWindowTitle(QCoreApplication::translate("Authorization", "Authorization", nullptr));
    ui->HeaderLabel->setText(QCoreApplication::translate("Authorization", "Login or sign up!", nullptr));
    ui->pbLogin->setText(QCoreApplication::translate("Authorization", "Login", nullptr));
    ui->pbSignUp->setText(QCoreApplication::translate("Authorization", "Sign Up", nullptr));
    ui->PassField->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->LogField->setPlaceholderText("example_address@example.org");
    ui->PassField->setPlaceholderText("********");
    ui->LogLabel->setText(QCoreApplication::translate("Authorization", "Login", nullptr));
    ui->PassLabel->setText(QCoreApplication::translate("Authorization", "Password", nullptr));
}

Authorization::~Authorization()
{
    delete ui;
}

void Authorization::on_pbLogin_clicked()
{
    ui->pbLogin->setGeometry(QRect(20, 220, 80, 24));
    ui->pbSignUp->setGeometry(QRect(130, 220, 80, 24));
    if (ui->LogField->text().isEmpty())
    {
        ui->pbLogin->setGeometry(QRect(20, 240, 80, 24));
        ui->pbSignUp->setGeometry(QRect(130, 240, 80, 24));
        ui->WarnLabel->setVisible(true);
        ui->LogField->setStyleSheet("border: 1px solid red");
        ui->WarnLabel->setText("Login must not be empty!");
         return;
    }

    if (ui->PassField->text().isEmpty())
    {
        ui->pbLogin->setGeometry(QRect(20, 240, 80, 24));
        ui->pbSignUp->setGeometry(QRect(130, 240, 80, 24));
        ui->WarnLabel->setVisible(true);
        ui->PassField->setStyleSheet("border: 1px solid red");
        ui->WarnLabel->setText("Password must not be empty!");
         return;
    }

    emit AuthSignal (Login, Password);
    close ();
}


void Authorization::on_LogField_editingFinished()
{
    Login = ui->LogField->text();
    ui->LogField->setStyleSheet("border: 1px solid black");
    ui->WarnLabel->setVisible(false);
    ui->pbLogin->setGeometry(QRect(20, 220, 80, 24));
    ui->pbSignUp->setGeometry(QRect(130, 220, 80, 24));
}


void Authorization::on_PassField_editingFinished()
{

    Password = ui->PassField->text();
    ui->PassField->setStyleSheet("border: 1px solid black");
    ui->WarnLabel->setVisible(false);
    ui->pbLogin->setGeometry(QRect(20, 220, 80, 24));
    ui->pbSignUp->setGeometry(QRect(130, 220, 80, 24));
}


void Authorization::on_LogField_returnPressed()
{
    ui->pbLogin->setGeometry(QRect(20, 220, 80, 24));
    ui->pbSignUp->setGeometry(QRect(130, 220, 80, 24));
    if (ui->LogField->text().isEmpty())
    {
        ui->pbLogin->setGeometry(QRect(20, 240, 80, 24));
        ui->pbSignUp->setGeometry(QRect(130, 240, 80, 24));
        ui->WarnLabel->setVisible(true);
        ui->LogField->setStyleSheet("border: 1px solid red");
        ui->WarnLabel->setText("Login must not be empty!");
         return;
    }
}


void Authorization::on_PassField_returnPressed()
{
    if (ui->PassField->text().isEmpty())
    {
        ui->pbLogin->setGeometry(QRect(20, 240, 80, 24));
        ui->pbSignUp->setGeometry(QRect(130, 240, 80, 24));
        ui->WarnLabel->setVisible(true);
        ui->PassField->setStyleSheet("border: 1px solid red");
        ui->WarnLabel->setText("Password must not be empty!");
         return;
    }
}


void Authorization::on_PassField_textChanged(const QString &arg1)
{
     Q_UNUSED(&arg1);
    if (ui->PassField->text().isEmpty())
    {
        ui->pbLogin->setGeometry(QRect(20, 240, 80, 24));
        ui->pbSignUp->setGeometry(QRect(130, 240, 80, 24));
        ui->WarnLabel->setVisible(true);
        ui->PassField->setStyleSheet("border: 1px solid red");
        ui->WarnLabel->setText("Password must not be empty!");
         return;
    }
}


void Authorization::on_LogField_textEdited(const QString &arg1)
{
    Q_UNUSED(&arg1);
    if (ui->PassField->text().isEmpty())
    {
        ui->pbLogin->setGeometry(QRect(20, 240, 80, 24));
        ui->pbSignUp->setGeometry(QRect(130, 240, 80, 24));
        ui->WarnLabel->setVisible(true);
        ui->PassField->setStyleSheet("border: 1px solid red");
        ui->WarnLabel->setText("Password must not be empty!");
         return;
    }
}


void Authorization::on_pbSignUp_clicked()
{
    emit SignUpSignal();
    close ();
}


void Authorization::on_LogField_selectionChanged()
{
    ui->LogField->setStyleSheet("border: 1px solid black");
    ui->WarnLabel->setVisible(false);
    ui->pbLogin->setGeometry(QRect(20, 220, 80, 24));
    ui->pbSignUp->setGeometry(QRect(130, 220, 80, 24));
}


void Authorization::on_PassField_selectionChanged()
{
    ui->PassField->setStyleSheet("border: 1px solid black");
    ui->WarnLabel->setVisible(false);
    ui->pbLogin->setGeometry(QRect(20, 220, 80, 24));
    ui->pbSignUp->setGeometry(QRect(130, 220, 80, 24));
}

