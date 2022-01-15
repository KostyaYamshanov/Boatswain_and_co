// This header file is related to greenhouse
// painter module
#pragma once

#include <QPainter>
#include <QPen>
#include <QWidget>
#include <QBrush>
#include "debtrace.h"
#include "ghtypedefs.h"

// general purpose default values in centimeters
#define GH_DEFAULT_WIDTH 				1000
#define GH_DEFAULT_LENGTH 				4800
#define GH_DEFAULT_VRAMP_WIDTH 			60
#define GH_DEFAULT_VRAMP_LWIDTH 		80
#define GH_DEFAULT_VRAMP_RWIDTH 		100
#define GH_DEFAULT_VRAMP_AMNT 			4
#define GH_DEFAULT_VRAMP_SPACING 		1500
#define GH_DEFAULT_HRAMP_AMNT 			5
#define GH_DEFAULT_HRAMP_WIDTH 			75
#define GH_DEFAULT_HRAMP_BWIDTH 		50
#define GH_DEFAULT_HRAMP_SPACING 		170

// values in pixels
#define GH_INITIAL_X_POS 				10
#define GH_INITIAL_Y_POS 				10

class GreenHouse : public QWidget
{
private:
	int iWinWidth;
	int iwidth;
	int iLength;
	int iVRampWidth;
	int iVRampAmnt;
	int iHRampAmnt;
	int iHRampWidth;
	int iHRampSpacing;
	std:: vector <int> vVRampWidth;
	std:: vector <int> vHRampWidth;
	bool bReflected;
	tRealValues RealValues;
	tPixelValues PxlValues;

	bool IsReflected (void);

public:
	GreenHouse (QWidget *parent = 0, int iWidth = 1024);
	void SetWidth (int iWidth);
	void SetLength (int iLength);
	void SetVertRampAmount (int iAmonut);
	void SetVertRampSpacing (int iSpacing);
	void SetHorRampAmount (int iAmount);
	void SetHorRampSpacing (int iSpacing);
	void SetReflection (bool bValue);
	void SetWinWidth (int iWidth);

protected:
	void paintEvent(QPaintEvent *event);
	void PrintBorders (QPainter *painter);
	void PrintVRamp (QPainter *painter);
	void PrintHRamp (QPainter *painter);
};
