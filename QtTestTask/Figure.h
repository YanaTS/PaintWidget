#pragma once
#include <QPainter>

class Figure
{
public:
	Figure();
	virtual ~Figure();

	virtual void draw(QPainter &painter) = 0;
	virtual bool containedInTheContour(const QPoint &pos) = 0;
	virtual QPen getPen() = 0;
	virtual void setPen(const QPen &newPen) = 0;
	virtual QPoint getCenter() = 0;
	virtual void setCenter(const QPoint &newCenter) = 0;
	virtual QRect getBoundingRect() = 0;
	virtual bool isSystem() { return false; };
	QPen m_prevPen;
};

