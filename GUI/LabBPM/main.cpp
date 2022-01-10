#include "includes.h"

int main(int argc, char *argv[])
{
    Icon IconHandler;
    setlocale( LC_ALL,"Russian" );
    QApplication App(argc, argv);
    QMainWindow Window;


    IconHandler.SetIcon (&Window);

    Window.resize (512, 512);
    Window.setWindowTitle ("Laboratory Business Process Manager");
    Window.setToolTip ("Laboratory Business Process Manager");
    Window.show();
    return App.exec ();
}
