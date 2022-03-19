#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    AuthWindow = new Authorization (this);
    ui->setupUi(this);
    hide ();
    ui->HelloLabel->setVisible (false);
    AuthWindow->setModal(true);
    AuthWindow->show();

    connect (AuthWindow, &Authorization::AuthSignal, this, &MainWindow::AuthSlot);
    connect (AuthWindow, &Authorization::SignUpSignal, this, &MainWindow::SignUpSlot);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AuthSlot(QString login, QString pass)
{
    std::string Hello = "Hello, ";
    ui->loglabel->setText(login);
    ui->paslabel->setText(pass);
    UserSession.SetName (login.toStdString ());
    UserSession.SetSurname ("Thingamabob");
    UserSession.SetEmail ("Thingamabob@whatchamacallit.com");
    ui->surnlabel->setText(QString::fromStdString(UserSession.GetSurname()));
    ui->emaillabel->setText(QString::fromStdString(UserSession.GetEmail()));
    Hello = Hello + UserSession.GetName () + " !";
    ui->HelloLabel->setText (QString::fromStdString(Hello));
    ui->HelloLabel->setVisible (true);
}


void MainWindow::SignUpSlot()
{
    SignUpWindow = new SignUp (this);
    SignUpWindow->setModal(true);
    SignUpWindow->show ();
    connect (SignUpWindow, &SignUp::SignUpFinishSignal, this, &MainWindow::SignUpFinishedSlot);
}

void MainWindow::SignUpFinishedSlot(QString Name, QString Surname,
                                    QString Email, QString Password)
{
    std::string Hello = "Hello, ";
    UserSession.SetName (Name.toStdString ());
    UserSession.SetSurname (Surname.toStdString ());
    UserSession.SetEmail (Email.toStdString ());
    ui->paslabel->setText(Password);
    ui->loglabel->setText(Name);
    ui->surnlabel->setText(QString::fromStdString(UserSession.GetSurname()));
    ui->emaillabel->setText(QString::fromStdString(UserSession.GetEmail()));
    Hello = Hello + UserSession.GetName () + "!";
    ui->HelloLabel->setText (QString::fromStdString(Hello));
    ui->HelloLabel->setVisible (true);
}

