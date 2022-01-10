#include "includes.h"

int main(int argc, char *argv[])
{
    setlocale( LC_ALL,"Russian" );

    Icon IconHandler;
    QApplication App(argc, argv);
    QMainWindow Window;
    GreenHouse GreenHouseHandler;


    IconHandler.SetIcon (&Window);

    Window.resize (1024, 1024);
    Window.setWindowTitle ("Laboratory Business Process Manager");
    Window.setToolTip ("Laboratory Business Process Manager");
    Window.setCentralWidget (&GreenHouseHandler);
    Window.show();
    return App.exec ();
}
