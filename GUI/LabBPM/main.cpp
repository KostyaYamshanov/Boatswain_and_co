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
    Window.SetUpGreenHouse ();
    Window.SetUpReflection ();
    Window.showMaximized();

    return App.exec ();
}
