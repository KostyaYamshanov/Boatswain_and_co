#pragma once

#include <QMainWindow>
#include <filesystem>
#include <unistd.h>

// Path related macros
#define PATH_SPLIT_TOKEN "GUI"
#define PATH_ADD_TOKEN "LabBPM"
#define POTATO_PIC_NAME "potato.png"

int IcnSetIcon (QMainWindow *pWindow);
