#include "FigureArrow.h"
#include "qvector2d.h"
#include "RenderContainer.h"

FigureArrow::FigureArrow(const QPoint &arrowStart, const QPoint &arrowEnd, bool isSystem):
	m_arrowStart(arrowStart),
	m_arrowEnd(arrowEnd),
	m_isSystem(isSystem){}

FigureArrow::~FigureArrow(){}

void FigureArrow::draw(QPainter &painter)
{
	QPoint p1 = RenderContainer::frameTransform->convertToQTCoordinateSystem(m_arrowStart);
	QPoint p2 = RenderContainer::frameTransform->convertToQTCoordinateSystem(m_arrowEnd);

	QVector2D unitArrowVec;
	unitArrowVec.setX(p2.x() - p1.x());
	unitArrowVec.setY(p2.y() - p1.y());
	unitArrowVec.normalize();
	QVector2D normal;
	normal.setX(unitArrowVec.y());
	normal.setY(-unitArrowVec.x());
	QVector2D projectionWingOnArrowAxis;
	projectionWingOnArrowAxis.setX(p2.x() - unitArrowVec.x()*10.0);
	projectionWingOnArrowAxis.setY(p2.y() - unitArrowVec.y()*10.0);
	QVector2D rightArrowWing = projectionWingOnArrowAxis + normal*5.0;
	QVector2D leftArrowWing = projectionWingOnArrowAxis - normal*5.0;

	QPoint p3(rightArrowWing.x(), rightArrowWing.y());
	QPoint p4(leftArrowWing.x(), leftArrowWing.y());

	QLine arrowAxis(p1, p2);
	QLine arrowRightWing(p2, p3);
	QLine arrowLeftWing(p2, p4);
	
	painter.drawLine(arrowAxis);
	painter.drawLine(arrowRightWing);
	painter.drawLine(arrowLeftWing);
}

QPoint FigureArrow::get()
{
	return m_arrowStart;
}
void FigureArrow::set(const QPoint &arrowStart, const QPoint &arrowEnd)
{
	m_arrowStart = arrowStart;
	m_arrowEnd = arrowEnd;
}
QPoint FigureArrow::getCenter()
{
	return (m_arrowStart + m_arrowEnd)*0.5;
}
void FigureArrow::setCenter(const QPoint &newCenter)
{
	QPoint p1 = newCenter - (m_arrowEnd - m_arrowStart)*0.5;
	QPoint p2 = newCenter + (m_arrowEnd - m_arrowStart)*0.5;
	m_arrowStart = p1;
	m_arrowEnd = p2;
}
QPen FigureArrow::getPen()
{
	return m_pen;
}
void FigureArrow::setPen(const QPen &newPen)
{
	m_pen = newPen;
}

bool FigureArrow::containedInTheContour(const QPoint &pos)
{
	QPoint p = m_arrowEnd - m_arrowStart;
	QVector2D line(p);
	QVector2D unitVectorOfLine = line.normalized();
	QVector2D difference(m_arrowStart - pos);
	QVector2D perpendicularToTheLineFromPos = difference - ((difference.x()*unitVectorOfLine.x() + difference.y()*unitVectorOfLine.y())*unitVectorOfLine);

	int delta = RenderContainer::frameTransform->convertDistanceToNewCoordinateSystem(2 * m_pen.width());

	return abs(perpendicularToTheLineFromPos.length()) < delta;
}

QRect FigureArrow::getBoundingRect()
{
	return QRect(m_arrowStart, m_arrowEnd).normalized();
}

bool FigureArrow::isSystem()
{
	return m_isSystem;
}