#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>
#include <QString>
#include <QLineEdit>
#include <QCloseEvent>
#include "icon.h"

namespace Ui {
class Authorization;
}

class Authorization : public QDialog
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();

private:
    Ui::Authorization *ui;
    QString Login;
    QString Password;

signals:
    void AuthSignal (QString login, QString pass);
    void SignUpSignal ();

private slots:
    void on_pbLogin_clicked();
    void on_LogField_editingFinished();
    void on_PassField_editingFinished();
    void on_LogField_returnPressed();
    void on_PassField_returnPressed();
    void on_PassField_textChanged(const QString &arg1);
    void on_LogField_textEdited(const QString &arg1);
    void on_pbSignUp_clicked();
    void on_LogField_selectionChanged();
    void on_PassField_selectionChanged();
};

#endif // AUTHORIZATION_H
