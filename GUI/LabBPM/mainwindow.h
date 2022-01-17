#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "includes.h"
#include "ghtypedefs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetUpGreenHouse (void);
    void SetUpReflection (void);
private:
    void HandleSectors (int XLeft, int XRight,
                        int Ytop, int YBot, bool bVertical, bool bReflected);
    void CalculateSectors (void);
    void CalculateReflectedSectors (void);

    Ui::MainWindow *ui;
    std:: vector <Sector> *pvSectors = new
                           std::vector <Sector> ();
    std:: vector <Sector> *pvReflectedSectors = new
                           std::vector <Sector> ();
    int iSectorsAmount;
    int iReflectedSectorsAmount;
};
#endif // MAINWINDOW_H
