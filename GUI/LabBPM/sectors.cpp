#include "sectors.h"
#include "getpath.h"

Sector::Sector (void)
{
	Xmin = 0;
	Xmax = 0;
	Ymin = 0;
	Ymax = 0;
};

void Sector::LeftX (int X_min)
{
	Xmin = X_min;
	return;
}

int Sector::LeftX (void)
{
	return Xmin;
}

void Sector::RightX (int X_max)
{
	Xmax = X_max;
	return;
}

int Sector::RightX (void)
{
	return Xmax;
}

void Sector::TopY (int Y_min)
{
	Ymin = Y_min;
	return;
}

int Sector::TopY (void)
{
	return Ymin;
}

void Sector::BotY (int Y_max)
{
	Ymax = Y_max;
	return;
}

int Sector::BotY (void)
{
	return Ymax;
}

SectorWidget::SectorWidget (QWidget *parent) : QWidget (parent)
{
}

void SectorWidget::paintEvent (QPaintEvent *event)
{

	QPainter Painter (this);

	QPen Pen(Qt::green, 2, Qt::SolidLine);

	Painter.setPen (Pen);
	Painter.setBrush (QBrush (Qt::green));
	Painter.drawRect (0, 0,
				      oSector.Width (), oSector.Height ());

	return;
}

void SectorWidget:: SetSector (std:: vector <Sector> *pVector, int iIndex)
{
	Sector oNewSector = pVector->at(iIndex);

	oSector.LeftX (oNewSector.LeftX ());
	oSector.RightX (oNewSector.RightX ());
	oSector.TopY (oNewSector.TopY ());
	oSector.BotY (oNewSector.BotY ());

	this->repaint ();
}

int Sector:: Width (void)
{
	return (RightX () - LeftX ());
}

int SectorWidget:: Width (void)
{
	return (oSector.RightX () - oSector.LeftX ());
}

int Sector:: Height (void)
{
	return (BotY () - TopY ());
}

int SectorWidget:: Height (void)
{
	return (oSector.BotY () - oSector.TopY ());
}
