#include "ghpainter.h"
#include <QDebug>

GreenHouse:: GreenHouse (QWidget *parent, int iWinWidth) : QWidget (parent)
{
	SetWinWidth (iWinWidth);
	SetVertRampAmount (GH_DEFAULT_VRAMP_AMNT);
	SetHorRampAmount (GH_DEFAULT_HRAMP_AMNT);
};

void GreenHouse:: SetWidth (int iWidth)
{
	RealValues.iWidth = iWidth;
	PxlValues.iWidth =
				(iWinWidth * RealValues.iWidth) / RealValues.iLength;
	return;
}

void GreenHouse:: SetLength (int iLength)
{
	RealValues.iLength = iLength;
	// fuck u that's why
	PxlValues.iLength =
				(iWinWidth * RealValues.iLength) / RealValues.iLength;
	return;
}

void GreenHouse:: SetVertRampAmount (int iAmonut)
{
	iVRampAmnt = iAmonut;
	qDebug ("set ramp amnt %d", iVRampAmnt);
	return;
}

void GreenHouse:: SetVertRampSpacing (int iSpacing)
{
	RealValues.iVRampSpacing = iSpacing;
	PxlValues.iVRampSpacing = 
				(iWinWidth * RealValues.iVRampSpacing) / RealValues.iLength;
	return;
}

void GreenHouse:: SetHorRampAmount (int iAmonut)
{
	iHRampAmnt = iAmonut;
	return;
}

void GreenHouse:: SetHorRampSpacing (int iSpacing)
{
	RealValues.iHRampSpacing = iSpacing;
	PxlValues.iHRampSpacing = 
				(iWinWidth * RealValues.iHRampSpacing) / RealValues.iLength;
	return;
}


void GreenHouse:: paintEvent (QPaintEvent *event)
{
	Q_UNUSED(event);

	QPainter Painter (this);
	QPen Pen(Qt::black, 2, Qt::SolidLine);

	Painter.setPen (Pen);
	Painter.setBrush (QBrush (Qt::white));

	PrintBorders (&Painter);
	PrintVRamp (&Painter);
	PrintHRamp (&Painter);

	return;
}

void GreenHouse:: PrintBorders (QPainter *pPainter)
{
	pPainter->drawRect (GH_INITIAL_X_POS, GH_INITIAL_Y_POS,
					    PxlValues.iLength, PxlValues.iWidth);

	return;
}

void GreenHouse:: PrintVRamp (QPainter *pPainter)
{
	int iLeftPos;

	QPen Pen(Qt::gray, 2, Qt::SolidLine);

	pPainter->setPen (Pen);
	pPainter->setBrush(QBrush(Qt::gray));

	iLeftPos = GH_INITIAL_X_POS;

	if (!IsReflected ())
	{
		for (int iRampCounter = 0; iRampCounter < iVRampAmnt; iRampCounter++)
		{
			// drawrect (Xcoord,Ycoord, width, height)
			pPainter->drawRect (iLeftPos, GH_INITIAL_Y_POS,
					  			vVRampWidth[iRampCounter],
					  			PxlValues.iWidth);
			iLeftPos += (vVRampWidth[iRampCounter] + PxlValues.iVRampSpacing);
		}
	}
	else
	{
		for (int iRampCounter = iVRampAmnt - 1; iRampCounter >= 0; iRampCounter--)
		{
			// drawrect (Xcoord,Ycoord, width, height)
			pPainter->drawRect (iLeftPos, GH_INITIAL_Y_POS,
					  			vVRampWidth[iRampCounter],
					  			PxlValues.iWidth);
			iLeftPos += (vVRampWidth[iRampCounter] + PxlValues.iVRampSpacing);
		}
	}

	pPainter->setBrush(QBrush(Qt::white));
	Pen.setColor (Qt::black);
	pPainter->setPen (Pen);

	return;
}

void GreenHouse:: PrintHRamp (QPainter *pPainter)
{
	int iTopPos;
	QPen Pen(Qt::gray, 2, Qt::SolidLine);

	pPainter->setPen (Pen);
	pPainter->setBrush(QBrush(Qt::gray));

	iTopPos = GH_INITIAL_Y_POS;
	if (!IsReflected ())
	{
		for (int iRampCounter = 0; iRampCounter < iHRampAmnt; iRampCounter++)
		{
			pPainter->drawRect (GH_INITIAL_X_POS, iTopPos,
					  			PxlValues.iLength, vHRampWidth[iRampCounter]);
			iTopPos += (vHRampWidth[iRampCounter] + PxlValues.iHRampSpacing);
		}
	}
	else
	{
		for (int iRampCounter = iHRampAmnt - 1; iRampCounter >= 0; iRampCounter--)
		{
			pPainter->drawRect (GH_INITIAL_X_POS, iTopPos,
					  			PxlValues.iLength, vHRampWidth[iRampCounter]);
			iTopPos += (vHRampWidth[iRampCounter] + PxlValues.iHRampSpacing);
		}
	}

	pPainter->setBrush(QBrush(Qt::white));
	Pen.setColor (Qt::black);
	pPainter->setPen (Pen);

	return;
}

void GreenHouse:: SetReflection (bool bValue)
{
	bReflected = bValue;
}

bool GreenHouse:: IsReflected (void)
{
	return bReflected;
}

void GreenHouse::SetWinWidth (int iWidth)
{
	int iCnvrtdVal = 0;

	iWinWidth = iWidth;
	vVRampWidth.clear ();
	vHRampWidth.clear ();

	//iWinWidth stands for maximum available length
	//My idea:
	//	we have length of greenhouse in centimeters
	//	(4800) by real size and we have win width in pixels
	//	we use 75% of available width to print length,
	//	so we put 4800 as iWinWidth and then calculate all the rest
	//	of values according to it
	// It's simple proportion
	//	X = (iWinWidth * Value) / iRealLength

	SetLength (GH_DEFAULT_LENGTH); //order matters, believe me
	SetWidth (GH_DEFAULT_WIDTH);
	SetVertRampSpacing (GH_DEFAULT_VRAMP_SPACING);
	SetHorRampSpacing (GH_DEFAULT_HRAMP_SPACING);

	for (int iIndex = 1; iIndex <= GH_DEFAULT_VRAMP_AMNT; iIndex++)
	{
		switch (iIndex)
		{
			case 1:
				iCnvrtdVal =
							(iWinWidth * GH_DEFAULT_VRAMP_LWIDTH) / RealValues.iLength;
				break;

			case GH_DEFAULT_VRAMP_AMNT:
				iCnvrtdVal =
							(iWinWidth * GH_DEFAULT_VRAMP_RWIDTH) / RealValues.iLength;
				break;

			default:
				iCnvrtdVal =
							(iWinWidth * GH_DEFAULT_VRAMP_WIDTH) / RealValues.iLength;

				break;
		}

		vVRampWidth.push_back (iCnvrtdVal);
	}

	for (int iIndex = 1; iIndex <= GH_DEFAULT_HRAMP_AMNT; iIndex++)
	{
		if ((iIndex == 1) || iIndex == GH_DEFAULT_HRAMP_AMNT)
		{
			iCnvrtdVal =
						(iWinWidth * GH_DEFAULT_HRAMP_BWIDTH) / RealValues.iLength;
		}
		else
		{
			iCnvrtdVal =
						(iWinWidth * GH_DEFAULT_HRAMP_WIDTH) / RealValues.iLength;
		}

		vHRampWidth.push_back (iCnvrtdVal);
	}

}

int GreenHouse::GetHeight (void)
{
 return PxlValues.iWidth;
}

int GreenHouse::GetWidth (void)
{
 return PxlValues.iLength;
}

int GreenHouse::GetVertRampAmnt (void)
{
	return iVRampAmnt;
}

int GreenHouse::GetHorRampAmnt (void)
{
	return iHRampAmnt;
}

int GreenHouse::GetVRampWidth (int iIndex)
{
	return vVRampWidth[iIndex];
}

int GreenHouse::GetHRampWidth (int iIndex)
{
	return vHRampWidth[iIndex];
}

int GreenHouse::GetVRampSpacing (void)
{
	return PxlValues.iVRampSpacing;

}

int GreenHouse::GetHRampSpacing (void)
{
	return PxlValues.iHRampSpacing;

}
