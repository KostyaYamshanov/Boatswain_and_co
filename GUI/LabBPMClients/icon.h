#ifndef ICON_H
#define ICON_H

#include <QMainWindow>
#include <QWidget>
#include <QIcon>
#include "getpath.h"

#define POTATO_PIC_NAME     "potato.png"

class Icon
{
public:
    void SetIcon (QMainWindow *pWindow);
    void SetIcon (QWidget *pWidget);
};

#endif // ICON_H
