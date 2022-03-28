#include "icon.h"

void Icon:: SetIcon (QMainWindow *pWindow)
{
    Path oPath;
    std::string sPicName (POTATO_PIC_NAME);
    std::string sFullPath;

    sFullPath = oPath.GetPath();
    sFullPath = oPath.GetPathToPictures (sFullPath);

    sFullPath.append (sPicName);

    pWindow->setWindowIcon (QIcon (QString::fromStdString(sFullPath)));

    return;
}

void Icon:: SetIcon (QWidget *pWidget)
{
    Path oPath;
    std::string sPicName (POTATO_PIC_NAME);
    std::string sFullPath;

    sFullPath = oPath.GetPath();
    sFullPath = oPath.GetPathToPictures (sFullPath);

    sFullPath.append (sPicName);

    pWidget->setWindowIcon (QIcon (QString::fromStdString(sFullPath)));

    return;
}
