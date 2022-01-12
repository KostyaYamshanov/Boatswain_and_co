#include "includes.h"
#include <QLabel>
#include <QBoxLayout>
#include <QFont>

int main(int argc, char *argv[])
{
    setlocale( LC_ALL,"Russian" );
    int iWidth;
    Icon IconHandler;
    QApplication App(argc, argv);
    QMainWindow Window;
    QWidget *CentralWidget = new QWidget ();
    QVBoxLayout *TopLayout = new QVBoxLayout (CentralWidget);
    QLabel SectOne;
    QLabel SectTwo;
    QFont Font("Helvetica", 12, QFont::Bold);
    QRect Screen = QDesktopWidget().screenGeometry(CentralWidget);

    iWidth = Screen.width () * 0.77;
    TRACE_DBG_FILE_AND_LINE;
    GreenHouse *GreenHouseHandler = new GreenHouse (CentralWidget, iWidth);
    TRACE_DBG_FILE_AND_LINE;
    GreenHouse *ReflectedGreenHouseHandler = new GreenHouse (CentralWidget, iWidth);
    TRACE_DBG_FILE_AND_LINE;

    IconHandler.SetIcon (&Window);

    Window.resize(Screen.size());

    Window.setWindowTitle ("Laboratory Business Process Manager");
    Window.setToolTip ("Laboratory Business Process Manager");

    ReflectedGreenHouseHandler->SetReflection (true);

    SectOne.setText ("Section 1");
    SectOne.setFont (Font);
    SectTwo.setText ("Section 2");
    SectTwo.setFont (Font);

    TopLayout->addWidget (&SectOne);
    TopLayout->addWidget (GreenHouseHandler);
    TopLayout->addWidget (&SectTwo);
    TopLayout->addWidget (ReflectedGreenHouseHandler);
    TopLayout->setMargin (10);
    TopLayout->addStretch(1);

    GreenHouseHandler->setFixedHeight(Screen.height () * 0.3);
    GreenHouseHandler->setFixedWidth(iWidth);
    ReflectedGreenHouseHandler->setFixedHeight(Screen.height () * 0.3);
    ReflectedGreenHouseHandler->setFixedWidth(iWidth);

    CentralWidget->setLayout (TopLayout);

    Window.setCentralWidget (CentralWidget);

    // going fullscreen
    Window.showMaximized();
    return App.exec ();
}
