#pragma once
#include "Figure.h"
class FigureCircle :
	public Figure
{
public:
	FigureCircle(const QPoint &circleCenter, int circleRadius);
	~FigureCircle();
	void draw(QPainter &painter)  override;
	QPoint getCenter()  override;
	int getRadius();
	void setRadius(int radius);
	void setCenter(const QPoint &center)  override;
	bool containedInTheContour(const QPoint &pos)  override;
	QPen getPen()  override;
	void setPen(const QPen &newPen)  override;
	QRect getBoundingRect()  override;
private:
	QPoint m_circleCenter;
	int m_circleRadius;
	QPen m_pen;
};

