#pragma once
#include "Figure.h"
class FigureLine :
	public Figure
{
public:
	FigureLine(const QLine &line);
	~FigureLine();
	void draw(QPainter &painter) override;
	QLine get();
	void set(const QLine &line);
	bool containedInTheContour(const QPoint &pos) override;
	QPoint getCenter() override;
	void setCenter(const QPoint &newCenter) override;
	QPen getPen() override;
	void setPen(const QPen &newPen) override;
	QRect getBoundingRect() override;
private:
	QLine m_line;
	QPoint m_center;
	QPen m_pen;
};

