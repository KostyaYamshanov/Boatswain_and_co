#include "ghpainter.h"

GreenHouse :: GreenHouse (QWidget *parent) : QWidget (parent)
{
	SetWidth (GH_DEFAULT_WIDTH);
	SetLength (GH_DEFAULT_LENGTH);
 	SetVertRampWidth (GH_DEFAULT_VRAMP_WIDTH);
    SetVertRampType (GH_DEFAULT_VRAMP_TYPE);
    SetVertRampSpacing (GH_DEFAULT_VRAMP_SPACING);
    SetHorRampAmount (GH_DEFAULT_HRAMP_AMNT);
    SetHorRampWidth (GH_DEFAULT_HRAMP_WIDTH);
    SetHorRampSpacing (GH_DEFAULT_HRAMP_SPACING);
};

void GreenHouse :: SetWidth (int iWidth)
{
	iGHwidth = iWidth;
	qDebug ("SetWidth %d\n", iGHwidth);
	return;
};

void GreenHouse :: SetLength (int iLength)
{
	iGHLength = iLength;
	qDebug ("SetLength %d\n", iGHLength);
	return;
};

void GreenHouse :: SetVertRampWidth (int iWidth)
{
	iVRampWidth = iWidth;
	qDebug ("SetVertRampWidth %d\n", iVRampWidth);
	return;
};

void GreenHouse :: SetVertRampAmount (int iAmonut)
{
	int iVRampSpacing;

	iVRampAmnt = iAmonut;

	qDebug ("SetVertRampAmount %d\n", iVRampAmnt);
	if ( iVRampAmnt == 1)
	{
		qDebug ("mid ramp \n");
		// middle ramp, spacing is division of greenhouse width by 2
		iVRampSpacing = iGHwidth / 2 - iVRampWidth / 2;
		qDebug ("dividing width %d by 2 results in %d subtracting rampwidtn %d /2 results in %d\n", iGHwidth, iGHwidth / 2, iVRampWidth, iVRampSpacing);
		SetVertRampSpacing (iVRampSpacing);
	}
	return;
};

void GreenHouse :: SetVertRampType (int iType)
{
	iVRampType = iType;
	qDebug ("SetVertRampType %d\n", iVRampType);

	switch (iType)
	{
		case 1:
			qDebug ("case 1\n");
    		SetVertRampAmount (GH_DEFAULT_VRAMP_AMNT);
			break;
		default:
			qDebug ("case 2\n");
    		SetVertRampAmount (GH_DEFAULT_VRAMP_AMNT);
			break;
	}
	return;
};

void GreenHouse :: SetVertRampSpacing (int iSpacing)
{
	iVRampSpacing = iSpacing;
	qDebug ("SetVertRampSpacing %d\n", iVRampSpacing);
	return;
};

void GreenHouse :: SetHorRampAmount (int iAmonut)
{
	int iHRampSpacing;

	iHRampAmnt = iAmonut;
	qDebug ("SetHorRampAmount %d\n", iHRampAmnt);

	if ( iHRampAmnt == 1)
	{
		// middle ramp, spacing is division of greenhouse width by 2
		iHRampSpacing = iGHLength / 2 - iHRampWidth / 2;
		SetHorRampSpacing (iHRampSpacing);
	}
	return;
};

void GreenHouse :: SetHorRampWidth (int iWidth)
{
	iHRampWidth = iWidth;
	qDebug ("SetHorRampWidth %d\n", iHRampWidth);
	return;
};

void GreenHouse :: SetHorRampType (int iType)
{
	iHRampType = iType;

	qDebug ("SetHorRampType %d\n", iHRampType);
	switch (iType)
	{
		case 1:
    		SetHorRampAmount (GH_DEFAULT_HRAMP_AMNT);
			break;
		default:
    		SetHorRampAmount (GH_DEFAULT_HRAMP_AMNT);
			break;
	}
	return;
};

void GreenHouse :: SetHorRampSpacing (int iSpacing)
{
	iHRampSpacing = iSpacing;
	qDebug ("SetHorRampSpacing %d\n", iHRampSpacing);
	return;
};


void GreenHouse :: paintEvent (QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter Painter (this);

	QPen Pen(Qt::black, 2, Qt::SolidLine);
   
    Painter.setPen (Pen);

    PrintBorders (&Painter);
    PrintVRamp (&Painter);
    PrintHRamp (&Painter);

    return;
}

void GreenHouse :: PrintBorders (QPainter *pPainter)
{
	pPainter->drawRect (GH_INITIAL_X_POS, GH_INITIAL_Y_POS,
					    iGHwidth, iGHLength);
	return;
}

void GreenHouse :: PrintVRamp (QPainter *pPainter)
{
	int iLeftPos, iRightPos;
	int iHalfWidth;

	iHalfWidth = iVRampWidth / 2;

	iLeftPos = GH_INITIAL_X_POS;
	iRightPos = iLeftPos + iHalfWidth;

	for (int iRampCounter = 0; iRampCounter < iVRampAmnt; iRampCounter++)
	{
		iLeftPos += iVRampSpacing;
		iRightPos = iLeftPos + iHalfWidth;
		pPainter->drawLine (iLeftPos, GH_INITIAL_Y_POS,
				  iLeftPos, iGHLength + GH_INITIAL_Y_POS);	
		pPainter->drawLine (iRightPos, GH_INITIAL_Y_POS,
				  iRightPos, iGHLength + GH_INITIAL_Y_POS);	
	}
	return;
}

void GreenHouse :: PrintHRamp (QPainter *pPainter)
{
	int iTopPos, iBotPos;
	int iHalfWidth;

	iHalfWidth = iHRampWidth / 2;
	iTopPos = GH_INITIAL_X_POS;

	for (int iRampCounter = 0; iRampCounter < iVRampAmnt; iRampCounter++)
	{
		iTopPos += iHRampSpacing;
		iBotPos = iTopPos + iHalfWidth;
		pPainter->drawLine (GH_INITIAL_X_POS, iTopPos,
				  iGHwidth + GH_INITIAL_X_POS, iTopPos);	
		pPainter->drawLine (GH_INITIAL_X_POS, iBotPos,
				  iGHwidth + GH_INITIAL_X_POS, iBotPos);	
	}

	return;
}
