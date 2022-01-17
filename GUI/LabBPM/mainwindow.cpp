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
    ui->Sector_1->SetSector (pvSectors, 0);
    Sector TmpSector;
    for (int i = 0; i < pvSectors->size(); i++)
    {
        TmpSector = pvSectors->at (i);
        qDebug ("sector %d, LeftX %d, RightX %d, topY %d, botY %d",i, TmpSector.LeftX (),
            TmpSector.RightX (), TmpSector.TopY (), TmpSector.BotY ());
    }

    ui->Sector_1->setGeometry (QRect(0, 0 ,
                                     TmpSector.Width () + ui->SectionOne->GetVRampWidth(0),
                                     TmpSector.Height () - ui->SectionOne->GetHRampWidth(0)));
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

    qDebug("input %d %d %d %d", XLeft, XRight, Ytop, YBot);
    if (bReflected)
    {
        iSectorsAmnt = iReflectedSectorsAmount;
    }
    else
    {
        iSectorsAmnt = iSectorsAmount;
    }

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
                if (!bReflected)
                {
                    TmpSector.LeftX (XLeft + ui->SectionOne->GetVRampWidth(iIndex));
                    pvSectors->at (iIndex) = TmpSector;
                }
                else
                {
                    TmpSector.LeftX (XLeft + ui->SectionTwo->GetVRampWidth(iIndex));
                    pvReflectedSectors->at (iIndex) = TmpSector;
                }
                continue;
            }
            if (XRight == TmpSector.RightX ())
            {
                if (!bReflected)
                {
                    TmpSector.RightX (TmpSector.RightX () - ui->SectionOne->GetVRampWidth(iIndex));
                    pvSectors->at (iIndex) = TmpSector;
                }
                else
                {
                    TmpSector.RightX (TmpSector.RightX () - ui->SectionTwo->GetVRampWidth(iIndex));
                    pvReflectedSectors->at (iIndex) = TmpSector;
                }
                continue;
            }
            // qDebug ("comparing %d with range %d, %d", XLeft, TmpSector.LeftX (), TmpSector.RightX ());
            if (XLeft > TmpSector.LeftX () &&
                XLeft < TmpSector.RightX ())
            {
                // we are inside existing sector
                //update right border of existing sector
                //create new sector, inherit Y coordinates from collision sector
                Sector NewSector;
                NewSector.LeftX (XRight);
                // qDebug ("new left x%d", NewSector.LeftX ());
                NewSector.RightX (TmpSector.RightX ());
                TmpSector.RightX (XLeft);
                if (bReflected)
                {
                    pvReflectedSectors->at (iIndex) = TmpSector;
                }
                else
                {
                    pvSectors->at (iIndex) = TmpSector;
                }
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
                if (!bReflected)
                {
                    TmpSector.TopY (Ytop + ui->SectionOne->GetHRampWidth(iIndex));
                    pvSectors->at (iIndex) = TmpSector;
                    qDebug ("updated sector X:%d, x:%d, Y:%d, y:%d",
                             TmpSector.LeftX (), TmpSector.RightX (),TmpSector.TopY (), TmpSector.BotY ());
                    // qDebug ("set new top coord %d that is result of %d + %d", TmpSector.TopY (), Ytop, ui->SectionOne->GetHRampWidth(iIndex));
                }
                else
                {
                    TmpSector.TopY (Ytop + ui->SectionOne->GetHRampWidth(iIndex));
                    pvReflectedSectors->at (iIndex) = TmpSector;
                }
                continue;
            }
            if (YBot == TmpSector.BotY ())
            {
                if (!bReflected)
                {
                    TmpSector.BotY (TmpSector.BotY () - ui->SectionOne->GetHRampWidth(iIndex));
                    pvSectors->at (iIndex) = TmpSector;
                    qDebug ("updated sector X:%d, x:%d, Y:%d, y:%d",
                             TmpSector.LeftX (), TmpSector.RightX (),TmpSector.TopY (), TmpSector.BotY ());

                    // qDebug ("set new top coord %d that is result of %d + %d", TmpSector.TopY (), Ytop, ui->SectionOne->GetHRampWidth(iIndex));
                }
                else
                {
                    TmpSector.BotY (TmpSector.BotY () - ui->SectionTwo->GetHRampWidth(iIndex));
                    pvReflectedSectors->at (iIndex) = TmpSector;
                }
                continue;
            }
            // qDebug ("comparing hor %d in range %d %d",  Ytop, TmpSector.TopY (),TmpSector.BotY ());
            if (Ytop > TmpSector.TopY () &&
                Ytop < TmpSector.BotY ())
            {
                // we are inside existing sector
                //update bottom border of existing sector
                //create new sector, inherit Y coordinates from collision sector
                Sector NewSector;
                NewSector.LeftX (TmpSector.LeftX());
                NewSector.RightX (TmpSector.RightX());
                NewSector.TopY (YBot);
                NewSector.BotY (TmpSector.BotY ());
                TmpSector.BotY (Ytop);
                if (!bReflected)
                {
                    pvSectors->at (iIndex) = TmpSector;
                    pvSectors->push_back (NewSector);
                    iSectorsAmount++;
                }
                else
                {
                    pvReflectedSectors->at (iIndex) = TmpSector;
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
    // qDebug ("vert ramp amount %d", iVertRamps);
    for (int iRampCounter = 0; iRampCounter <
            iVertRamps; iRampCounter++)
    {
        // qDebug ("sector calculator vertical iteration %d", iRampCounter);
        HandleSectors (iLeftPos, iLeftPos + ui->SectionOne->GetVRampWidth(iRampCounter),
                        GH_INITIAL_Y_POS,
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
        // qDebug ("sector calculator horizontal iteration %d", iRampCounter);
        HandleSectors (GH_INITIAL_X_POS,
                        GH_INITIAL_X_POS + ui->SectionOne->GetWidth (),
                        iTopPos,
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
