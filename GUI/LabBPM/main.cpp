#include "includes.h"
#include <QLabel>
#include <QBoxLayout>
#include <QFont>
#include <QDebug>

int main(int argc, char *argv[])
{
    setlocale( LC_ALL,"Russian" );
    Icon            IconHandler;
    QApplication    App (argc, argv);
    MainWindow Window;
    QLabel          SectOne;
    QLabel          SectTwo;
    QFont           Font("Helvetica", 12, QFont::Bold);

    IconHandler.SetIcon (&Window);

    Window.setWindowTitle ("Laboratory Business Process Manager");
    Window.setToolTip ("Laboratory Business Process Manager");
    qDebug ("trying to set up greenhouse");
    Window.SetUpGreenHouse ();
    qDebug ("greenhouse good");
    Window.SetUpReflection ();
    qDebug ("reflection good");
    Window.SetUpDialogue ();
    qDebug ("dialogue good");
    Window.showMaximized();

    return App.exec ();
}
