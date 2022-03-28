#ifndef GETPATH_H
#define GETPATH_H
#include <filesystem>
#include <unistd.h>
#include <string>

// Path related macros
#define PATH_SPLIT_TOKEN 	"GUI"
#define PATH_ADD_TOKEN 		"LabBPM"
#define PATH_PIC_TOKEN 		"pictures"
#define PATH_MAX_LEN 		256

#define BG_NAME_STRAIGHT 	"greenhouse.png"
#define BG_NAME_REFLECTED 	"greenhouse_r.png"

class Path
{
public:
    std::string GetPath (void);
    std::string GetPathToPictures (std::string sWorkDir);
    std::string GetPathToStraigth (std::string sWorkDir);
    std::string GetPathToReflected (std::string sWorkDir);
};
#endif // GETPATH_H
