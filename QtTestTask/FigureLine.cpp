#include "FigureLine.h"
#include "qvector2d.h"
#include "RenderContainer.h"

FigureLine::FigureLine(const QLine &line):
	m_line(line),
	m_pen(RenderContainer::pen),
	m_center((m_line.p2() - m_line.p1())*0.5){}

FigureLine::~FigureLine(){}

void FigureLine::draw(QPainter &painter)
{
	QPoint p1 = RenderContainer::frameTransform->convertToQTCoordinateSystem(m_line.p1());
	QPoint p2 = RenderContainer::frameTransform->convertToQTCoordinateSystem(m_line.p2());
	QLine newLine(p1, p2);
	painter.drawLine(newLine);
}

QLine FigureLine::get()
{
	return m_line;
}
void FigureLine::set(const QLine &line)
{
	m_line = line;
}
QPoint FigureLine::getCenter()
{
	return (m_line.p1() + m_line.p2())*0.5;
}
void FigureLine::setCenter(const QPoint &newCenter)
{
	QPoint p1 = newCenter - (m_line.p2() - m_line.p1())*0.5;
	QPoint p2 = newCenter + (m_line.p2() - m_line.p1())*0.5;
	m_line.setLine(p1.x(), p1.y(), p2.x(), p2.y());
}
QPen FigureLine::getPen()
{
	return m_pen;
}
void FigureLine::setPen(const QPen &newPen)
{
	m_pen = newPen;
}

QRect FigureLine::getBoundingRect()
{
	return QRect(m_line.p1(), m_line.p2()).normalized();
}

bool FigureLine::containedInTheContour(const QPoint &pos)
{	
	QPoint p = m_line.p2() - m_line.p1();
	QVector2D line(p);
	QVector2D unitVectorOfLine = line.normalized();
	QVector2D difference ( m_line.p1() - pos);
	QVector2D perpendicularToTheLineFromPos = difference - ((difference.x()*unitVectorOfLine.x() + difference.y()*unitVectorOfLine.y())*unitVectorOfLine);

	int delta = RenderContainer::frameTransform->convertDistanceToNewCoordinateSystem(2 * m_pen.width());

	return abs(perpendicularToTheLineFromPos.length()) < delta;
}
