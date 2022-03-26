#include "getpath.h"

std::string Path:: GetPath (void)
{
    char acCompilerPath[PATH_MAX_LEN];
    std::string sGui (PATH_SPLIT_TOKEN);
    std::string sLbpm (PATH_ADD_TOKEN);

    getcwd(acCompilerPath, PATH_MAX_LEN); //this will return path to compilator, but we need upper directory

    std::string sCurrPath = acCompilerPath;
    std::string sWorkDir = sCurrPath.substr(0, sCurrPath.find(sGui));
    sWorkDir.append (sGui + '\\' + sLbpm + '\\');

    return sWorkDir;;
};

std::string Path:: GetPathToPictures (std::string sWorkDir)
{
    std::string sPicFolder (PATH_PIC_TOKEN);

    sWorkDir.append (sPicFolder + '\\');

    return sWorkDir;
}

std::string Path:: GetPathToStraigth (std::string sWorkDir)
{
    std::string sPicName = GetPathToPictures (sWorkDir);

    sPicName.append (BG_NAME_STRAIGHT);

    return sPicName;
}

std::string Path:: GetPathToReflected (std::string sWorkDir)
{
    std::string sPicName = GetPathToPictures (sWorkDir);

    sPicName.append (BG_NAME_REFLECTED);

    return sPicName;
}
