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
	// qDebug ("painting sector x:%d, y:%d, width:%d, height:%d", oSector.LeftX (), oSector.TopY (), oSector.Width (), oSector.Height ());
	Painter.drawRect (oSector.LeftX (), oSector.TopY (),
				      oSector.Width (), oSector.Height ());

	return;
}

void SectorWidget:: SetSector (std:: vector <Sector> *pVector, int iIndex)
{
	oSector = pVector->at(iIndex);
	this->repaint ();
}

int Sector:: Width (void)
{
	return (RightX () - LeftX ());
}

int Sector:: Height (void)
{
	return (BotY () - TopY ());
}
