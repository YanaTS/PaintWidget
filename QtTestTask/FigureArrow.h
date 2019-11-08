#pragma once
#include "Figure.h"
class FigureArrow :
	public Figure
{
public:
	FigureArrow(const QPoint &arrowStart, const QPoint &arrowEnd, bool isSystem = false);
	~FigureArrow();
	void draw(QPainter &painter)  override;
	QPoint get();
	void set(const QPoint &arrowStart, const QPoint &arrowEnd);
	bool containedInTheContour(const QPoint &pos)  override;
	QPoint getCenter()  override;
	void setCenter(const QPoint &newCenter)  override;
	QPen getPen()  override;
	void setPen(const QPen &newPen)  override;
	QRect getBoundingRect()  override;
	bool isSystem() override;

private:
	QPoint m_arrowStart;
	QPoint m_arrowEnd;
	QPen m_pen;
	bool m_isSystem;
};

