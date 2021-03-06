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
public slots:
    void sector_selected (int iSectionId, int SectorId);
private slots:
    void on_pbSector_1_clicked();
    void on_pbSector_2_clicked();
    void on_pbSector_3_clicked();
    void on_pbSector_4_clicked();
    void on_pbSector_5_clicked();
    void on_pbSector_6_clicked();
    void on_pbSector_7_clicked();
    void on_pbSector_8_clicked();
    void on_pbSector_9_clicked();
    void on_pbSector_10_clicked();
    void on_pbSector_11_clicked();
    void on_pbSector_12_clicked();
    void on_pbSector_2_1_clicked();
    void on_pbSector_2_2_clicked();
    void on_pbSector_2_3_clicked();
    void on_pbSector_2_4_clicked();
    void on_pbSector_2_5_clicked();
    void on_pbSector_2_6_clicked();
    void on_pbSector_2_7_clicked();
    void on_pbSector_2_8_clicked();
    void on_pbSector_2_9_clicked();
    void on_pbSector_2_10_clicked();
    void on_pbSector_2_11_clicked();
    void on_pbSector_2_12_clicked();

private:
    void HandleSectors (int XLeft, int XRight,
                        int Ytop, int YBot, bool bVertical, bool bReflected);
    void CalculateSectors (void);
    void CalculateReflectedSectors (void);
    void DrawSectors (void);
    void DrawReflectedSectors (void);
    void DrawButtons (void);
    void DrawReflectedButtons (void);
    void DropButtonsText (void);
    void DropColors (int iSectionId, int iSectorId);
    Ui::MainWindow *ui;
    std:: vector <Sector> *pvSectors = new
                           std::vector <Sector> ();
    std:: vector <Sector> *pvReflectedSectors = new
                           std::vector <Sector> ();
    int iSectorsAmount;
    int iReflectedSectorsAmount;
};
#endif // MAINWINDOW_H
