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
    Sector TmpSector;

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
    ui->Sector_2->SetSector (pvSectors, 1);
    ui->Sector_3->SetSector (pvSectors, 2);
    ui->Sector_4->SetSector (pvSectors, 3);
    ui->Sector_5->SetSector (pvSectors, 4);
    ui->Sector_6->SetSector (pvSectors, 5);
    ui->Sector_7->SetSector (pvSectors, 6);
    ui->Sector_8->SetSector (pvSectors, 7);
    ui->Sector_9->SetSector (pvSectors, 8);
    ui->Sector_10->SetSector (pvSectors, 9);
    ui->Sector_11->SetSector (pvSectors, 10);
    ui->Sector_12->SetSector (pvSectors, 11);

    TmpSector = pvSectors->at (0);

    ui->Sector_1->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_1->Width () + ui->SectionOne->GetVRampWidth(SCT_LEFT_RAMP_IDX),
                                     ui->Sector_1->Height () + ui->SectionOne->GetHRampWidth(SCT_TOP_RAMP_IDX)));
    TmpSector = pvSectors->at (1);
    ui->Sector_2->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                      ui->Sector_2->Width () + ui->SectionOne->GetVRampWidth(1),
                                      ui->Sector_2->Height () + ui->SectionOne->GetHRampWidth(SCT_TOP_RAMP_IDX)));
    TmpSector = pvSectors->at (2);
    ui->Sector_3->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_3->Width () + ui->SectionOne->GetVRampWidth(2),
                                     ui->Sector_3->Height () + ui->SectionOne->GetHRampWidth(SCT_TOP_RAMP_IDX)));
    TmpSector = pvSectors->at (3);
    ui->Sector_4->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_3->Width () + ui->SectionOne->GetVRampWidth(SCT_LEFT_RAMP_IDX),
                                     ui->Sector_3->Height () + ui->SectionOne->GetHRampWidth(1)));
    TmpSector = pvSectors->at (4);
    ui->Sector_5->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_3->Width () + ui->SectionOne->GetVRampWidth(1),
                                     ui->Sector_3->Height () + ui->SectionOne->GetHRampWidth(1)));
    TmpSector = pvSectors->at (5);
    ui->Sector_6->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_3->Width () + ui->SectionOne->GetVRampWidth(2),
                                     ui->Sector_3->Height () + ui->SectionOne->GetHRampWidth(1)));
    TmpSector = pvSectors->at (6);
    ui->Sector_7->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_3->Width () + ui->SectionOne->GetVRampWidth(SCT_LEFT_RAMP_IDX),
                                     ui->Sector_3->Height () + ui->SectionOne->GetHRampWidth(2)));
    TmpSector = pvSectors->at (7);
    ui->Sector_8->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_3->Width () + ui->SectionOne->GetVRampWidth(1),
                                     ui->Sector_3->Height () + ui->SectionOne->GetHRampWidth(2)));
    TmpSector = pvSectors->at (8);
    ui->Sector_9->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_3->Width () + ui->SectionOne->GetVRampWidth(2),
                                     ui->Sector_3->Height () + ui->SectionOne->GetHRampWidth(2)));
    TmpSector = pvSectors->at (9);
    ui->Sector_10->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_3->Width () + ui->SectionOne->GetVRampWidth(SCT_LEFT_RAMP_IDX),
                                     ui->Sector_3->Height () + ui->SectionOne->GetHRampWidth(3)));
    TmpSector = pvSectors->at (10);
    ui->Sector_11->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_3->Width () + ui->SectionOne->GetVRampWidth(1),
                                     ui->Sector_3->Height () + ui->SectionOne->GetHRampWidth(3)));
    TmpSector = pvSectors->at (11);
    ui->Sector_12->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_3->Width () + ui->SectionOne->GetVRampWidth(2),
                                     ui->Sector_3->Height () + ui->SectionOne->GetHRampWidth(3)));


    this->resize (Screen.width (), Screen.height ());
    this->repaint ();
}

void MainWindow::SetUpReflection (void)
{
    int       iWidth;
    int       iSectOneHeight;
    QRect     Screen = QDesktopWidget ().screenGeometry (ui->centralwidget);
    Sector    InitialSector;
    Sector    TmpSector;

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

    InitialSector.LeftX (GH_INITIAL_X_POS);
    InitialSector.RightX (GH_INITIAL_X_POS + ui->SectionTwo->GetWidth ());
    InitialSector.TopY (GH_INITIAL_Y_POS);
    InitialSector.BotY (GH_INITIAL_Y_POS + ui->SectionTwo->GetHeight ());
    pvReflectedSectors->push_back (InitialSector);
    iReflectedSectorsAmount++;

    CalculateReflectedSectors ();

    ui->Sector_2_1->SetSector (pvReflectedSectors, 0);
    TmpSector = pvReflectedSectors->at (0);
    ui->Sector_2_1->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_1->Width () + ui->SectionTwo->GetVRampWidth(SCT_LEFT_RAMP_IDX),
                                     ui->Sector_2_1->Height () + ui->SectionTwo->GetHRampWidth(SCT_TOP_RAMP_IDX)));

    ui->Sector_2_2->SetSector (pvReflectedSectors, 1);
    TmpSector = pvReflectedSectors->at (1);
    ui->Sector_2_2->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_2->Width () + ui->SectionTwo->GetVRampWidth(1),
                                     ui->Sector_2_2->Height () + ui->SectionTwo->GetHRampWidth(SCT_TOP_RAMP_IDX)));

    ui->Sector_2_3->SetSector (pvReflectedSectors, 2);
    TmpSector = pvReflectedSectors->at (2);
    ui->Sector_2_3->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_3->Width () + ui->SectionTwo->GetVRampWidth(2),
                                     ui->Sector_2_3->Height () + ui->SectionTwo->GetHRampWidth(SCT_TOP_RAMP_IDX)));

    ui->Sector_2_4->SetSector (pvReflectedSectors, 0);
    TmpSector = pvReflectedSectors->at (3);
    ui->Sector_2_4->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_4->Width () + ui->SectionTwo->GetVRampWidth(SCT_LEFT_RAMP_IDX),
                                     ui->Sector_2_4->Height () + ui->SectionTwo->GetHRampWidth(1)));

    ui->Sector_2_5->SetSector (pvReflectedSectors, 1);
    TmpSector = pvReflectedSectors->at (4);
    ui->Sector_2_5->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_5->Width () + ui->SectionTwo->GetVRampWidth(1),
                                     ui->Sector_2_5->Height () + ui->SectionTwo->GetHRampWidth(1)));

    ui->Sector_2_6->SetSector (pvReflectedSectors, 2);
    TmpSector = pvReflectedSectors->at (5);
    ui->Sector_2_6->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_6->Width () + ui->SectionTwo->GetVRampWidth(2),
                                     ui->Sector_2_6->Height () + ui->SectionTwo->GetHRampWidth(1)));

    ui->Sector_2_7->SetSector (pvReflectedSectors, 0);
    TmpSector = pvReflectedSectors->at (6);
    ui->Sector_2_7->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_7->Width () + ui->SectionTwo->GetVRampWidth(SCT_LEFT_RAMP_IDX),
                                     ui->Sector_2_7->Height () + ui->SectionTwo->GetHRampWidth(2)));

    ui->Sector_2_8->SetSector (pvReflectedSectors, 1);
    TmpSector = pvReflectedSectors->at (7);
    ui->Sector_2_8->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_8->Width () + ui->SectionTwo->GetVRampWidth(1),
                                     ui->Sector_2_8->Height () + ui->SectionTwo->GetHRampWidth(2)));

    ui->Sector_2_9->SetSector (pvReflectedSectors, 2);
    TmpSector = pvReflectedSectors->at (8);
    ui->Sector_2_9->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_9->Width () + ui->SectionTwo->GetVRampWidth(2),
                                     ui->Sector_2_9->Height () + ui->SectionTwo->GetHRampWidth(2)));

    ui->Sector_2_10->SetSector (pvReflectedSectors, 0);
    TmpSector = pvReflectedSectors->at (9);
    ui->Sector_2_10->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_10->Width () + ui->SectionTwo->GetVRampWidth(SCT_LEFT_RAMP_IDX),
                                     ui->Sector_2_10->Height () + ui->SectionTwo->GetHRampWidth(3)));

    ui->Sector_2_11->SetSector (pvReflectedSectors, 1);
    TmpSector = pvReflectedSectors->at (10);
    ui->Sector_2_11->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_11->Width () + ui->SectionTwo->GetVRampWidth(1),
                                     ui->Sector_2_11->Height () + ui->SectionTwo->GetHRampWidth(3)));

    ui->Sector_2_12->SetSector (pvReflectedSectors, 2);
    TmpSector = pvReflectedSectors->at (11);
    ui->Sector_2_12->setGeometry (QRect(TmpSector.LeftX (), TmpSector.TopY (),
                                     ui->Sector_2_12->Width () + ui->SectionTwo->GetVRampWidth(2),
                                     ui->Sector_2_12->Height () + ui->SectionTwo->GetHRampWidth(3)));

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
                    TmpSector.LeftX (XLeft + ui->SectionOne->GetVRampWidth(SCT_LEFT_RAMP_IDX));
                    pvSectors->at (iIndex) = TmpSector;
                }
                else
                {
                    TmpSector.LeftX (XLeft + ui->SectionTwo->GetVRampWidth(SCT_LEFT_RAMP_IDX));
                    pvReflectedSectors->at (iIndex) = TmpSector;
                }
                continue;
            }
            if (XRight == TmpSector.RightX ())
            {
                if (!bReflected)
                {
                    TmpSector.RightX (TmpSector.RightX () - ui->SectionOne->GetVRampWidth(SCT_RIGHT_RAMP_IDX));
                    pvSectors->at (iIndex) = TmpSector;
                }
                else
                {
                    TmpSector.RightX (TmpSector.RightX () - ui->SectionTwo->GetVRampWidth(SCT_RIGHT_RAMP_IDX));
                    pvReflectedSectors->at (iIndex) = TmpSector;
                }
                continue;
            }

            if (XLeft > TmpSector.LeftX () &&
                XLeft < TmpSector.RightX ())
            {
                // we are inside existing sector
                //update right border of existing sector
                //create new sector, inherit Y coordinates from collision sector
                Sector NewSector;
                NewSector.LeftX (XRight);

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
            }
        }
        else
        {
            if (Ytop == TmpSector.TopY ())
            {
                if (!bReflected)
                {
                    TmpSector.TopY (Ytop + ui->SectionOne->GetHRampWidth(SCT_TOP_RAMP_IDX));
                    pvSectors->at (iIndex) = TmpSector;
                }
                else
                {
                    TmpSector.TopY (Ytop + ui->SectionTwo->GetHRampWidth(SCT_TOP_RAMP_IDX));
                    pvReflectedSectors->at (iIndex) = TmpSector;
                }
                continue;
            }
            if (YBot == TmpSector.BotY ())
            {
                if (!bReflected)
                {
                    TmpSector.BotY (TmpSector.BotY () - ui->SectionOne->GetHRampWidth(SCT_BOT_RAMP_IDX));
                    pvSectors->at (iIndex) = TmpSector;
                }
                else
                {
                    TmpSector.BotY (TmpSector.BotY () - ui->SectionTwo->GetHRampWidth(SCT_BOT_RAMP_IDX));
                    pvReflectedSectors->at (iIndex) = TmpSector;
                }
                continue;
            }
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

    for (int iRampCounter = 0; iRampCounter <
            iVertRamps; iRampCounter++)
    {
        HandleSectors (iLeftPos, iLeftPos + ui->SectionTwo->GetVRampWidth(iRampCounter),
                        GH_INITIAL_Y_POS,
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

        HandleSectors (GH_INITIAL_X_POS,
                        GH_INITIAL_X_POS + ui->SectionTwo->GetWidth (),
                        iTopPos,
                        iTopPos + ui->SectionTwo->GetHRampWidth(iRampCounter),
                        false, true);

        iTopPos += (ui->SectionTwo->GetHRampWidth(iRampCounter) +
                    ui->SectionTwo->GetHRampSpacing ());
    }

}
