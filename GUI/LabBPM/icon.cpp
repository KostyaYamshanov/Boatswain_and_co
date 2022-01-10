#include "icon.h"

void Icon:: SetIcon (QMainWindow *pWindow)
{
    char acCompilerPath[256];
    std::string sGui (PATH_SPLIT_TOKEN);
    std::string sLbpm (PATH_ADD_TOKEN);
    std::string sPicName (POTATO_PIC_NAME);

    getcwd(acCompilerPath, 256); //this will return path to compilator, but we need upper directory

    std::string sCurrPath = acCompilerPath;
    std::string sWorkDir = sCurrPath.substr(0, sCurrPath.find(sGui));

    sWorkDir.append (sGui + '\\' + sLbpm + '\\' + sPicName);
    pWindow->setWindowIcon (QIcon (QString::fromStdString(sWorkDir)));
};
