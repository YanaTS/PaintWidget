#include "FigureCircle.h"
#include "qvector2d.h"
#include "RenderContainer.h"


FigureCircle::FigureCircle(const QPoint &circleCenter, int circleRadius):
	m_circleCenter(circleCenter),
	m_circleRadius(circleRadius),
	m_pen(RenderContainer::pen){}

FigureCircle::~FigureCircle(){}

void FigureCircle::draw(QPainter &painter)
{
	int radiusInQtCoordinates = RenderContainer::frameTransform->convertDistanceToQTCoordinateSystem(m_circleRadius);
	QPoint centerInQtCoordinates = RenderContainer::frameTransform->convertToQTCoordinateSystem(m_circleCenter);
	painter.drawEllipse(centerInQtCoordinates, radiusInQtCoordinates, radiusInQtCoordinates);
}

QPoint FigureCircle::getCenter()
{
	return m_circleCenter;
}
void FigureCircle::setCenter(const QPoint &center)
{
	m_circleCenter = center;
}
int FigureCircle::getRadius()
{
	return m_circleRadius;
}
void FigureCircle::setRadius(int radius)
{
	m_circleRadius = radius;
}
QPen FigureCircle::getPen()
{
	return m_pen;
}
void FigureCircle::setPen(const QPen &newPen)
{
	m_pen = newPen;
}

bool FigureCircle::containedInTheContour(const QPoint &pos)
{
	int delta = RenderContainer::frameTransform->convertDistanceToNewCoordinateSystem(2 * m_pen.width());
	QVector2D vectorFromCenterToPos(pos - m_circleCenter); 
	double distanceFromCenterToPos = vectorFromCenterToPos.length();

	return abs(distanceFromCenterToPos - m_circleRadius) < delta;
}

QRect FigureCircle::getBoundingRect()
{
	return QRect(m_circleCenter - QPoint(m_circleRadius, m_circleRadius), QSize(m_circleRadius, m_circleRadius) * 2);
}