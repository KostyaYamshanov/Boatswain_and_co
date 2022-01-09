#include "includes.h"

int main(int argc, char *argv[])
{
    setlocale( LC_ALL,"Russian" );
    QApplication App(argc, argv);
    QMainWindow Window;

    // This should be moved to special function or class method (idk i'm bad at OOP)
    char acCompilerPath[256];
    getcwd(acCompilerPath, 256); //this will return path to compilator, but we need upper directory

    std::string sCurrPath= acCompilerPath;
    std::string sGui (PATH_SPLIT_TOKEN);
    std::string sLbpm (PATH_ADD_TOKEN);
    std::string sPicName (POTATO_PIC_NAME);
    std::string sWorkDir = sCurrPath.substr(0, sCurrPath.find(sGui));

    sWorkDir.append (sGui + '\\' + sLbpm + '\\' + sPicName);
    // end of block that gotta be moved

    Window.resize (512, 512);
    Window.setWindowIcon (QIcon (QString::fromStdString(sWorkDir)));
    Window.setWindowTitle ("Laboratory Business Process Manager");
    Window.setToolTip ("Laboratory Business Process Manager");
    Window.show();
    return App.exec ();
}
