#pragma once

#include <QPainter>
#include <QPen>
#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QString>
#include "debtrace.h"
#include "ghpainter.h"

class Sector
{
private:
	int Xmin;
	int Xmax;
	int Ymin;
	int Ymax;

public:
	Sector (void);
	void LeftX (int X_min);
	int LeftX (void);
	void RightX (int X_max);
	int RightX (void);
	void TopY (int Y_min);
	int TopY (void);
	void BotY (int Y_max);
	int BotY (void);
	int Width (void);
	int Height (void);
};

class SectorWidget : public QWidget
{
private:
	Sector oSector;
	bool bPressEvent;
	QString sSpecie;
	QString sPlantVar;
	QString sEmpty = "Empty";
	int iAmount;
	int iPlaceWidth;
	int iPlaceHeight;

public:
	SectorWidget (QWidget *parent = nullptr);
	void SetSector (std:: vector <Sector> *pVector, int iIndex);
	void SetSectorSpecie (QString sNewSpecie);
	void SetSectorPlantVar (QString sNewPlantVar);
	QString GetSectorSpecie (void);
	QString GetSectorPlantVar (void);
	QString GetComboName (void);
	int Width (void);
	int Height (void);
	void SetPressEvent (bool bNewEvent);
protected:
	void paintEvent (QPaintEvent *event);
};
