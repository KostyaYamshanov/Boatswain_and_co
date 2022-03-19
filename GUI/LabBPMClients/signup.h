#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_pbSignUp_clicked();

    void on_NameField_selectionChanged();

    void on_SecondNameField_selectionChanged();

    void on_EmailField_selectionChanged();

    void on_PassField_selectionChanged();

    void on_RepPassField_selectionChanged();

private:
    Ui::SignUp *ui;
    void EmptyFieldHandle (std::string Field);
    void RestoreFields ();

signals:
    void SignUpFinishSignal (QString Name, QString Surname,
                             QString Email, QString Password);
};

#endif // SIGNUP_H
