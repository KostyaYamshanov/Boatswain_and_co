// This header file is related to greenhouse
// painter module
#pragma once

#include <QPainter>
#include <QPen>
#include <QWidget>
#include<QDebug>

// general purpose default values
#define GH_DEFAULT_WIDTH 			500
#define GH_DEFAULT_LENGTH 			800
#define GH_DEFAULT_VRAMP_WIDTH 		100 
#define GH_DEFAULT_VRAMP_AMNT 		1
#define GH_DEFAULT_VRAMP_TYPE 		1
#define GH_DEFAULT_VRAMP_SPACING    150
#define GH_DEFAULT_HRAMP_AMNT 		2
#define GH_DEFAULT_HRAMP_WIDTH 		100
#define GH_DEFAULT_HRAMP_SPACING	75
#define GH_INITIAL_X_POS 			10
#define GH_INITIAL_Y_POS 			10

class GreenHouse : public QWidget
{
private:
	int iGHwidth;
	int iGHLength;
	int iVRampWidth;
	int iVRampAmnt;
	int iVRampType;
	int iVRampSpacing;
	int iHRampAmnt;
	int iHRampType;
	int iHRampWidth;
	int iHRampSpacing;
	QColor Color;

public:
	GreenHouse (QWidget *parent = 0);
 	void SetWidth (int iWidth);
 	void SetLength (int iLength);
 	void SetVertRampWidth (int iWidth);
    void SetVertRampAmount (int iAmonut);
    void SetVertRampType (int iType);
    void SetVertRampSpacing (int iSpacing);
    void SetHorRampAmount (int iAmount);
    void SetHorRampWidth (int iWidth);
    void SetHorRampType (int iType);
    void SetHorRampSpacing (int iSpacing);
    void Print (void);

protected:
    void paintEvent(QPaintEvent *event);    
	void PrintBorders (QPainter *painter);
	void PrintVRamp (QPainter *painter);
	void PrintHRamp (QPainter *painter);
};

/*class PrintWidget :: public QWidget
{
    Q_OBJECT
 
public:
    explicit PrintWidget(QWidget *parent = 0);
    ~PrintWidget();
 
private slots:
	// this is unused for now
    void on_radioButton_red_clicked();
 
    void on_radioButton_green_clicked();
 
    void on_radioButton_blue_clicked();
 
private:
    Ui::PrintWidget *pUi;
 
};*/