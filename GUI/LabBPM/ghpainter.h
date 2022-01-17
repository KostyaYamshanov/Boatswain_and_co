// This header file is related to greenhouse
// painter module
#pragma once

#include <QPainter>
#include <QPen>
#include <QWidget>
#include <QBrush>
#include <QPixmap>
#include "debtrace.h"
#include "ghtypedefs.h"

// values in pixels
#define GH_INITIAL_X_POS 				5
#define GH_INITIAL_Y_POS 				5

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
	int GetHeight (void);
	int GetWidth (void);
	int GetVertRampAmnt (void);
	int GetHorRampAmnt (void);
	int GetVRampWidth (int iIndex);
	int GetHRampWidth (int iIndex);
	int GetVRampSpacing (void);
	int GetHRampSpacing (void);
protected:
	void paintEvent (QPaintEvent *event);
	void PrintBorders (QPainter *painter);
	void PrintVRamp (QPainter *painter);
	void PrintHRamp (QPainter *painter);
};
