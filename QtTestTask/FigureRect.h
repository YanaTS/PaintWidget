#pragma once
#include "Figure.h"
class FigureRect :
	public Figure
{
public:
	FigureRect(const QRect &rect);
	~FigureRect();
	void draw(QPainter &painter) override;
	bool containedInTheContour(const QPoint &pos) override;
	QRect get();
	void set(QRect rect);	
	QPoint getCenter() override;
	void setCenter(const QPoint &newCenter) override;
	QPen getPen() override;
	void setPen(const QPen &newPen) override;
	QRect getBoundingRect() override;
private:
	QRect m_rect;
	QPen m_pen;
};

