#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "authorization.h"
#include "signup.h"
#include "user.h"
#include "icon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Authorization *AuthWindow;
    SignUp *SignUpWindow;
    User UserSession;

public slots:
    void AuthSlot(QString login, QString pass);
    void SignUpSlot ();
    void SignUpFinishedSlot (QString Name, QString Surname,
                             QString Email, QString Password);
};
#endif // MAINWINDOW_H
