#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetUpGreenHouse (void)
{
    int       iWidth;
    Sector InitialSector;

    QRect     Screen = QDesktopWidget ().screenGeometry (ui->centralwidget);
    iWidth = Screen.width () * 0.75;

    // Section one geometrics
    ui->lSectOne->setGeometry (QRect(20, 10,
                               Screen.width () * GUI_LABEL_WIDTH_MULTIPLIER <
                               GUI_LABEL_MIN_WIDTH ? GUI_LABEL_MIN_WIDTH
                               : Screen.width () * GUI_LABEL_WIDTH_MULTIPLIER,
                               Screen.height () * GUI_LABEL_HEIGHT_MULTIPLIER <
                               GUI_LABEL_MIN_HEIGHT ? GUI_LABEL_MIN_HEIGHT
                               : Screen.height () * GUI_LABEL_HEIGHT_MULTIPLIER));

    ui->SectionOne->SetWinWidth (iWidth);
    ui->SectionOne->setGeometry (QRect(10, 50, iWidth, Screen.height () * 0.4));
    ui->SectionOne->setFixedWidth (iWidth);
    ui->SectionOne->setFixedHeight (Screen.height () * 0.4);

    this->resize (Screen.width (), Screen.height ());
    this->repaint ();

    InitialSector.LeftX (GH_INITIAL_X_POS);
    InitialSector.RightX (GH_INITIAL_X_POS + ui->SectionOne->GetWidth ());
    InitialSector.TopY (GH_INITIAL_Y_POS);
    InitialSector.BotY (GH_INITIAL_Y_POS + ui->SectionOne->GetHeight ());

    pvSectors->push_back (InitialSector);
    iSectorsAmount++;

    CalculateSectors ();
    //Drawing sectors, huge, long and awful implementation
    qDebug ("straight sectors amount %d", pvSectors->size());
    ui->Sector_1->SetSector (pvSectors, 0);

    qDebug ("reflected sectors amount %d", pvReflectedSectors->size());
    this->resize (Screen.width (), Screen.height ());
    this->repaint ();
}

void MainWindow::SetUpReflection (void)
{
    int       iWidth;
    int       iSectOneHeight;
    QRect     Screen = QDesktopWidget ().screenGeometry (ui->centralwidget);
    // Section two geometrics

    iWidth = Screen.width () * 0.75;
    iSectOneHeight = ui->SectionOne->GetHeight () + 50;
    ui->lSectTwo->setGeometry (QRect(20, iSectOneHeight + 10,
                               Screen.width () * GUI_LABEL_WIDTH_MULTIPLIER <
                               GUI_LABEL_MIN_WIDTH ? GUI_LABEL_MIN_WIDTH
                               : Screen.width () * GUI_LABEL_WIDTH_MULTIPLIER,
                               Screen.height () * GUI_LABEL_HEIGHT_MULTIPLIER <
                               GUI_LABEL_MIN_HEIGHT ? GUI_LABEL_MIN_HEIGHT
                               : Screen.height () * GUI_LABEL_HEIGHT_MULTIPLIER));

    ui->SectionTwo->SetReflection (true);
    ui->SectionTwo->SetWinWidth (iWidth);
    ui->SectionTwo->setGeometry (QRect(10, iSectOneHeight + 50,
                                 iWidth, Screen.height () * 0.4));
    ui->SectionTwo->setFixedWidth (iWidth);
    ui->SectionTwo->setFixedHeight (Screen.height () * 0.4);
    this->repaint ();
}

void MainWindow::HandleSectors (int XLeft, int XRight,
                                int Ytop, int YBot, bool bVertical, bool bReflected)
{
    //XLeft is a coordinate rectangle drawn from
    //XRight is XLeft + RampWidth
    //same logic is for horizontal ramp but for Y coordinates
    Sector TmpSector;
    int iSectorsAmnt;
    int iCustomCoordinateX;
    int iCustomCoordinateY;

    if (bReflected)
    {
        iSectorsAmnt = iReflectedSectorsAmount;
        iCustomCoordinateX = ui->SectionOne->GetHeight ();
        iCustomCoordinateY = ui->SectionOne->GetWidth ();
    }
    else
    {
        iSectorsAmnt = iSectorsAmount;
        iCustomCoordinateX = ui->SectionTwo->GetHeight ();
        iCustomCoordinateY = ui->SectionTwo->GetWidth ();
    }
    qDebug ("sectors amnt %d", iSectorsAmnt);
    for (int iIndex = 0; iIndex < iSectorsAmnt; iIndex++)
    {
        if (bReflected)
        {
            TmpSector = pvReflectedSectors->at (iIndex);
        }
        else
        {
            TmpSector = pvSectors->at (iIndex);
        }
        if (bVertical)
        {
            if (XLeft == TmpSector.LeftX ())
            {
                TmpSector.LeftX (XLeft);
                continue;
            }
            if (XLeft > TmpSector.LeftX () &&
                XLeft <= TmpSector.RightX ())
            {
                // we are inside existing sector
                //update right border of existing sector
                TmpSector.RightX (XLeft);
                //create new sector, inherit Y coordinates from collision sector
                Sector NewSector;
                NewSector.LeftX (XRight);
                NewSector.RightX (iCustomCoordinateX);
                NewSector.TopY (TmpSector.TopY ());
                NewSector.BotY (TmpSector.BotY ());
                if (!bReflected)
                {
                    pvSectors->push_back (NewSector);
                    iSectorsAmount++;
                }
                else
                {
                    pvReflectedSectors->push_back (NewSector);
                    iReflectedSectorsAmount++;
                }
                qDebug ("created new sector X:%d, x:%d, Y:%d, y:%d",
                        NewSector.LeftX (), NewSector.RightX (),NewSector.TopY (), NewSector.BotY ());
            }
        }
        else
        {
            if (Ytop == TmpSector.TopY ())
            {
                TmpSector.TopY (Ytop);
                continue;
            }
            if (Ytop > TmpSector.TopY () &&
                Ytop <= TmpSector.BotY ())
            {
                // we are inside existing sector
                //update bottom border of existing sector
                TmpSector.BotY (XLeft);
                //create new sector, inherit Y coordinates from collision sector
                Sector NewSector;
                NewSector.LeftX (TmpSector.LeftX());
                NewSector.RightX (TmpSector.RightX());
                NewSector.TopY (YBot);
                NewSector.BotY (iCustomCoordinateY);

                if (!bReflected)
                {
                    pvSectors->push_back (NewSector);
                    iSectorsAmount++;
                }
                else
                {
                    pvReflectedSectors->push_back (NewSector);
                    iReflectedSectorsAmount++;
                }
                qDebug ("created new sector X:%d, x:%d, Y:%d, y:%d",
                        NewSector.LeftX (), NewSector.RightX (),NewSector.TopY (), NewSector.BotY ());
            }

        }
    }
}

void MainWindow:: CalculateSectors (void)
{
    // Calculate verticals
    int iLeftPos;
    int iVertRamps = 0;

    iLeftPos = GH_INITIAL_X_POS;

    iVertRamps = ui->SectionOne->GetVertRampAmnt ();
    qDebug ("vert ramp amount %d", iVertRamps);
    for (int iRampCounter = 0; iRampCounter <
            iVertRamps; iRampCounter++)
    {
        qDebug ("sector calculator vertical iteration %d", iRampCounter);
        HandleSectors (iLeftPos, GH_INITIAL_Y_POS,
                        iLeftPos + ui->SectionOne->GetVRampWidth(iRampCounter),
                        GH_INITIAL_Y_POS + ui->SectionOne->GetHeight (),
                        true, false);

        iLeftPos += (ui->SectionOne->GetVRampWidth(iRampCounter) +
                     ui->SectionOne->GetVRampSpacing ());
    }

    // Calculate horizontals
    int iTopPos;
    iTopPos = GH_INITIAL_Y_POS;
    for (int iRampCounter = 0; iRampCounter <
         ui->SectionOne->GetHorRampAmnt (); iRampCounter++)
    {
        qDebug ("sector calculator horizontal iteration %d", iRampCounter);
        HandleSectors (GH_INITIAL_X_POS, iTopPos,
                        GH_INITIAL_X_POS + ui->SectionOne->GetWidth (),
                        iTopPos + ui->SectionOne->GetHRampWidth(iRampCounter),
                        false, false);
        iTopPos += (ui->SectionOne->GetHRampWidth(iRampCounter) +
                    ui->SectionOne->GetHRampSpacing ());
    }
}

void MainWindow:: CalculateReflectedSectors (void)
{
    // Calculate verticals
    int iLeftPos;
    int iVertRamps = 0;

    iLeftPos = GH_INITIAL_X_POS;
    iVertRamps = ui->SectionTwo->GetVertRampAmnt ();
    for (int iRampCounter = iVertRamps - 1; iRampCounter >= 0; iRampCounter--)
    {
        HandleSectors (iLeftPos, GH_INITIAL_Y_POS,
                        iLeftPos + ui->SectionTwo->GetVRampWidth(iRampCounter),
                        GH_INITIAL_Y_POS + ui->SectionTwo->GetHeight (),
                        true, true);

        iLeftPos += (ui->SectionTwo->GetVRampWidth(iRampCounter) +
                     ui->SectionTwo->GetVRampSpacing ());
    }

    // Calculate horizontals
    int iTopPos;

    iTopPos = GH_INITIAL_Y_POS;
    for (int iRampCounter = ui->SectionTwo->GetHorRampAmnt () - 1;
         iRampCounter >= 0; iRampCounter--)
    {

        HandleSectors (GH_INITIAL_X_POS, iTopPos,
                        GH_INITIAL_X_POS + ui->SectionTwo->GetWidth (),
                        iTopPos + ui->SectionTwo->GetHRampWidth(iRampCounter),
                        false, true);

        iTopPos += (ui->SectionTwo->GetHRampWidth(iRampCounter) +
                    ui->SectionTwo->GetHRampSpacing ());
    }

}
