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
    DrawSectors ();
    DrawButtons ();

    this->resize (Screen.width (), Screen.height ());
    this->repaint ();
}

void MainWindow::SetUpReflection (void)
{
    int       iWidth;
    int       iSectOneHeight;
    QRect     Screen = QDesktopWidget ().screenGeometry (ui->centralwidget);
    Sector    InitialSector;

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
    DrawReflectedSectors ();
    DrawReflectedButtons ();
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

void MainWindow:: DrawSectors (void)
{
    Sector    TmpSector;
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

    return;
}

void MainWindow:: DrawReflectedSectors (void)
{
    Sector    TmpSector;

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
    return;
}

void MainWindow:: DrawButtons (void)
{
    ui->pbSector_1->setGeometry (QRect(0, 0, ui->Sector_1->Width (), ui->Sector_1->Height ()));
    ui->pbSector_1->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_1->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_1->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2->setGeometry (QRect(0, 0, ui->Sector_2->Width (), ui->Sector_2->Height ()));
    ui->pbSector_2->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_3->setGeometry (QRect(0, 0, ui->Sector_3->Width (), ui->Sector_3->Height ()));
    ui->pbSector_3->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_3->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_3->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_4->setGeometry (QRect(0, 0, ui->Sector_4->Width (), ui->Sector_4->Height ()));
    ui->pbSector_4->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_4->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_4->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_5->setGeometry (QRect(0, 0, ui->Sector_5->Width (), ui->Sector_5->Height ()));
    ui->pbSector_5->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_5->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_5->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_6->setGeometry (QRect(0, 0, ui->Sector_6->Width (), ui->Sector_6->Height ()));
    ui->pbSector_6->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_6->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_6->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_7->setGeometry (QRect(0, 0, ui->Sector_7->Width (), ui->Sector_7->Height ()));
    ui->pbSector_7->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_7->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_7->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_8->setGeometry (QRect(0, 0, ui->Sector_8->Width (), ui->Sector_8->Height ()));
    ui->pbSector_8->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_8->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_8->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_9->setGeometry (QRect(0, 0, ui->Sector_9->Width (), ui->Sector_9->Height ()));
    ui->pbSector_9->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_9->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_9->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_10->setGeometry (QRect(0, 0, ui->Sector_10->Width (), ui->Sector_10->Height ()));
    ui->pbSector_10->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_10->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_10->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_11->setGeometry (QRect(0, 0, ui->Sector_11->Width (), ui->Sector_11->Height ()));
    ui->pbSector_11->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_11->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_11->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_12->setGeometry (QRect(0, 0, ui->Sector_12->Width (), ui->Sector_12->Height ()));
    ui->pbSector_12->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_12->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_12->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    return;
}

void MainWindow:: DrawReflectedButtons (void)
{
    ui->pbSector_2_1->setGeometry (QRect(0, 0, ui->Sector_2_1->Width (), ui->Sector_2_1->Height ()));
    ui->pbSector_2_1->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_1->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_1->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2_2->setGeometry (QRect(0, 0, ui->Sector_2_2->Width (), ui->Sector_2_2->Height ()));
    ui->pbSector_2_2->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_2->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_2->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2_3->setGeometry (QRect(0, 0, ui->Sector_2_3->Width (), ui->Sector_2_3->Height ()));
    ui->pbSector_2_3->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_3->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_3->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2_4->setGeometry (QRect(0, 0, ui->Sector_2_4->Width (), ui->Sector_2_4->Height ()));
    ui->pbSector_2_4->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_4->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_4->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2_5->setGeometry (QRect(0, 0, ui->Sector_2_5->Width (), ui->Sector_2_5->Height ()));
    ui->pbSector_2_5->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_5->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_5->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2_6->setGeometry (QRect(0, 0, ui->Sector_2_6->Width (), ui->Sector_2_6->Height ()));
    ui->pbSector_2_6->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_6->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_6->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2_7->setGeometry (QRect(0, 0, ui->Sector_2_7->Width (), ui->Sector_2_7->Height ()));
    ui->pbSector_2_7->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_7->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_7->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2_8->setGeometry (QRect(0, 0, ui->Sector_2_8->Width (), ui->Sector_2_8->Height ()));
    ui->pbSector_2_8->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_8->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_8->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2_9->setGeometry (QRect(0, 0, ui->Sector_2_9->Width (), ui->Sector_2_9->Height ()));
    ui->pbSector_2_9->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_9->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_9->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2_10->setGeometry (QRect(0, 0, ui->Sector_2_10->Width (), ui->Sector_2_10->Height ()));
    ui->pbSector_2_10->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_10->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_10->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2_11->setGeometry (QRect(0, 0, ui->Sector_2_11->Width (), ui->Sector_2_11->Height ()));
    ui->pbSector_2_11->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_11->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_11->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    ui->pbSector_2_12->setGeometry (QRect(0, 0, ui->Sector_2_12->Width (), ui->Sector_2_12->Height ()));
    ui->pbSector_2_12->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbSector_2_12->setStyleSheet("QPushButton{background:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}");
    ui->pbSector_2_12->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));

    return;
}

void MainWindow::sector_selected (int iSectionId, int SectorId)
{
    std::string sString ("Selected");
    int iPos = ui->SectionTwo->GetHeight ();
    sString.append (" sector:");
    sString.append (std::to_string(SectorId));

    if (iSectionId == 1)
    {
        ui->SectorNum->setGeometry (QRect(100, 10, 150, 35));
    }
    else
    {
        int       iSectOneHeight;
        iSectOneHeight = ui->SectionOne->GetHeight () + 60;
        ui->SectorNum->setGeometry (QRect(100, iSectOneHeight, 150, 35));
    }

    ui->SectorNum->setText(QString::fromStdString(sString));

    return;
}

void MainWindow::on_pbSector_1_clicked()
{
    std::string sString ("I'm ready");
    DropColors (1, 1);
    ui->Sector_1->SetPressEvent (true);
    ui->Sector_1->repaint ();
    DropButtonsText ();
    ui->pbSector_1->setText (QString::fromStdString (sString));
    sector_selected (1, 1);
    return;
}

void MainWindow::on_pbSector_2_clicked()
{
    std::string sString ("I'm ready");

    DropColors (1, 2);
    DropButtonsText ();
    ui->Sector_2->SetPressEvent (true);
    ui->Sector_2->repaint ();
    ui->pbSector_2->setText (QString::fromStdString (sString));
    sector_selected (1, 2);
    return;
}

void MainWindow::on_pbSector_3_clicked()
{
    std::string sString ("I'm ready");

    DropColors (1, 3);
    DropButtonsText ();
    ui->Sector_3->SetPressEvent (true);
    ui->Sector_3->repaint ();
    ui->pbSector_3->setText (QString::fromStdString (sString));
    sector_selected (1, 3);
    return;
}

void MainWindow::on_pbSector_4_clicked()
{
    std::string sString ("I'm ready");

    DropColors (1, 4);
    DropButtonsText ();
    ui->Sector_4->SetPressEvent (true);
    ui->Sector_4->repaint ();
    ui->pbSector_4->setText (QString::fromStdString (sString));
    sector_selected (1, 4);
    return;
}

void MainWindow::on_pbSector_5_clicked()
{
    std::string sString ("I'm ready");

    DropColors (1, 5);
    DropButtonsText ();
    ui->Sector_5->SetPressEvent (true);
    ui->Sector_5->repaint ();
    ui->pbSector_5->setText (QString::fromStdString (sString));
    sector_selected (1, 5);
    return;
}

void MainWindow::on_pbSector_6_clicked()
{
    std::string sString ("I'm ready");

    DropColors (1, 6);
    DropButtonsText ();
    ui->Sector_6->SetPressEvent (true);
    ui->Sector_6->repaint ();
    ui->pbSector_6->setText (QString::fromStdString (sString));
    sector_selected (1, 6);
    return;
}

void MainWindow::on_pbSector_7_clicked()
{
    std::string sString ("I'm ready");

    DropColors (1, 7);
    DropButtonsText ();
    ui->Sector_7->SetPressEvent (true);
    ui->Sector_7->repaint ();
    ui->pbSector_7->setText (QString::fromStdString (sString));
    sector_selected (1, 7);
    return;
}

void MainWindow::on_pbSector_8_clicked()
{
    std::string sString ("I'm ready");

    DropColors (1, 8);
    DropButtonsText ();
    ui->Sector_8->SetPressEvent (true);
    ui->Sector_8->repaint ();
    ui->pbSector_8->setText (QString::fromStdString (sString));
    sector_selected (1, 8);
    return;
}

void MainWindow::on_pbSector_9_clicked()
{
    std::string sString ("I'm ready");

    DropColors (1, 9);
    DropButtonsText ();
    ui->Sector_9->SetPressEvent (true);
    ui->Sector_9->repaint ();
    ui->pbSector_9->setText (QString::fromStdString (sString));
    sector_selected (1, 9);
    return;
}

void MainWindow::on_pbSector_10_clicked()
{
    std::string sString ("I'm ready");

    DropColors (1, 10);
    DropButtonsText ();
    ui->Sector_10->SetPressEvent (true);
    ui->Sector_10->repaint ();
    ui->pbSector_10->setText (QString::fromStdString (sString));
    sector_selected (1, 10);
    return;
}

void MainWindow::on_pbSector_11_clicked()
{
    std::string sString ("I'm ready");

    DropColors (1, 11);
    DropButtonsText ();
    ui->Sector_11->SetPressEvent (true);
    ui->Sector_11->repaint ();
    ui->pbSector_11->setText (QString::fromStdString (sString));
    sector_selected (1, 11);
    return;
}

void MainWindow::on_pbSector_12_clicked()
{
    std::string sString ("I'm ready");

    DropColors (1, 12);
    DropButtonsText ();
    ui->Sector_12->SetPressEvent (true);
    ui->Sector_12->repaint ();
    sector_selected (1, 12);
    return;
}

void MainWindow::on_pbSector_2_1_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 1);
    DropButtonsText ();
    ui->Sector_2_1->SetPressEvent (true);
    ui->Sector_2_1->repaint ();
    ui->pbSector_2_1->setText (QString::fromStdString (sString));
    sector_selected (2, 1);
    return;
}

void MainWindow::on_pbSector_2_2_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 2);
    DropButtonsText ();
    ui->Sector_2_2->SetPressEvent (true);
    ui->Sector_2_2->repaint ();
    ui->pbSector_2_2->setText (QString::fromStdString (sString));
    sector_selected (2, 2);
    return;
}

void MainWindow::on_pbSector_2_3_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 3);
    DropButtonsText ();
    ui->Sector_2_3->SetPressEvent (true);
    ui->Sector_2_3->repaint ();
    ui->pbSector_2_3->setText (QString::fromStdString (sString));
    sector_selected (2, 3);
    return;
}

void MainWindow::on_pbSector_2_4_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 4);
    DropButtonsText ();
    ui->Sector_2_4->SetPressEvent (true);
    ui->Sector_2_4->repaint ();
    ui->pbSector_2_4->setText (QString::fromStdString (sString));
    sector_selected (2, 4);
    return;
}

void MainWindow::on_pbSector_2_5_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 5);
    DropButtonsText ();
    ui->Sector_2_5->SetPressEvent (true);
    ui->Sector_2_5->repaint ();
    ui->pbSector_2_5->setText (QString::fromStdString (sString));
    sector_selected (2, 5);
    return;
}

void MainWindow::on_pbSector_2_6_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 6);
    DropButtonsText ();
    ui->Sector_2_6->SetPressEvent (true);
    ui->Sector_2_6->repaint ();
    ui->pbSector_2_6->setText (QString::fromStdString (sString));
    sector_selected (2, 6);
    return;
}

void MainWindow::on_pbSector_2_7_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 7);
    DropButtonsText ();
    ui->Sector_2_7->SetPressEvent (true);
    ui->Sector_2_7->repaint ();
    ui->pbSector_2_7->setText (QString::fromStdString (sString));
    sector_selected (2, 7);
    return;
}

void MainWindow::on_pbSector_2_8_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 8);
    DropButtonsText ();
    ui->Sector_2_8->SetPressEvent (true);
    ui->Sector_2_8->repaint ();
    ui->pbSector_2_8->setText (QString::fromStdString (sString));
    sector_selected (2, 8);
    return;
}

void MainWindow::on_pbSector_2_9_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 9);
    DropButtonsText ();
    ui->Sector_2_9->SetPressEvent (true);
    ui->Sector_2_9->repaint ();
    ui->pbSector_2_9->setText (QString::fromStdString (sString));
    sector_selected (2, 9);
    return;
}

void MainWindow::on_pbSector_2_10_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 10);
    DropButtonsText ();
    ui->Sector_2_10->SetPressEvent (true);
    ui->Sector_2_10->repaint ();
    ui->pbSector_2_10->setText (QString::fromStdString (sString));
    sector_selected (2, 10);
    return;
}

void MainWindow::on_pbSector_2_11_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 11);
    DropButtonsText ();
    ui->Sector_2_11->SetPressEvent (true);
    ui->Sector_2_11->repaint ();
    ui->pbSector_2_11->setText (QString::fromStdString (sString));
    sector_selected (2, 11);
    return;
}

void MainWindow::on_pbSector_2_12_clicked()
{
    std::string sString ("I'm ready");

    DropColors (2, 12);
    DropButtonsText ();
    ui->Sector_2_12->SetPressEvent (true);
    ui->Sector_2_12->repaint ();
    ui->pbSector_2_12->setText (QString::fromStdString (sString));
    sector_selected (2, 12);
    return;
}

void MainWindow:: DropButtonsText (void)
{
    ui->pbSector_1->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_3->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_4->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_5->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_6->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_7->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_8->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_9->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_10->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_11->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_12->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_2->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_12->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_9->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_4->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_6->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_8->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_10->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_11->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_1->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_5->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_3->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    ui->pbSector_2_7->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
}

void MainWindow:: DropColors (int iSectionId, int iSectorId)
{
    static int siSectionId = 0;
    static int siSectorId = 0;

    if (siSectionId ==1)
    {
        switch (siSectorId)
        {
            case 1:
                ui->Sector_1->SetPressEvent (false);
                ui->Sector_1->repaint ();
                break;
            case 2:
                ui->Sector_2->SetPressEvent (false);
                ui->Sector_2->repaint ();
                break;
            case 3:
                ui->Sector_3->SetPressEvent (false);
                ui->Sector_3->repaint ();
                break;
            case 4:
                ui->Sector_4->SetPressEvent (false);
                ui->Sector_4->repaint ();
                break;
            case 5:
                ui->Sector_5->SetPressEvent (false);
                ui->Sector_5->repaint ();
                break;
            case 6:
                ui->Sector_6->SetPressEvent (false);
                ui->Sector_6->repaint ();
                break;
            case 7:
                ui->Sector_7->SetPressEvent (false);
                ui->Sector_7->repaint ();
                break;
            case 8:
                ui->Sector_8->SetPressEvent (false);
                ui->Sector_8->repaint ();
                break;
            case 9:
                ui->Sector_9->SetPressEvent (false);
                ui->Sector_9->repaint ();
                break;
            case 10:
                ui->Sector_10->SetPressEvent (false);
                ui->Sector_10->repaint ();
                break;
            case 11:
                ui->Sector_11->SetPressEvent (false);
                ui->Sector_11->repaint ();
                break;
            default:
                ui->Sector_12->SetPressEvent (false);
                ui->Sector_12->repaint ();
                break;
        }
    }
    else
    {
        switch (siSectorId)
        {
            case 1:
                ui->Sector_2_1->SetPressEvent (false);
                ui->Sector_2_1->repaint ();
                break;
            case 2:
                ui->Sector_2_2->SetPressEvent (false);
                ui->Sector_2_2->repaint ();
                break;
            case 3:
                ui->Sector_2_3->SetPressEvent (false);
                ui->Sector_2_3->repaint ();
                break;
            case 4:
                ui->Sector_2_4->SetPressEvent (false);
                ui->Sector_2_4->repaint ();
                break;
            case 5:
                ui->Sector_2_5->SetPressEvent (false);
                ui->Sector_2_5->repaint ();
                break;
            case 6:
                ui->Sector_2_6->SetPressEvent (false);
                ui->Sector_2_6->repaint ();
                break;
            case 7:
                ui->Sector_2_7->SetPressEvent (false);
                ui->Sector_2_7->repaint ();
                break;
            case 8:
                ui->Sector_2_8->SetPressEvent (false);
                ui->Sector_2_8->repaint ();
                break;
            case 9:
                ui->Sector_2_9->SetPressEvent (false);
                ui->Sector_2_9->repaint ();
                break;
            case 10:
                ui->Sector_2_10->SetPressEvent (false);
                ui->Sector_2_10->repaint ();
                break;
            case 11:
                ui->Sector_2_11->SetPressEvent (false);
                ui->Sector_2_11->repaint ();
                break;
            default:
                ui->Sector_2_12->SetPressEvent (false);
                ui->Sector_2_12->repaint ();
                break;
        }
    }

    siSectionId = iSectionId;
    siSectorId = iSectorId;

    return;
}
