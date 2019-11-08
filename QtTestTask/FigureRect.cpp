#include "FigureRect.h"
#include "RenderContainer.h"

FigureRect::FigureRect(const QRect &rect):
	m_rect(rect),
	m_pen(RenderContainer::pen){}

FigureRect::~FigureRect(){}

void FigureRect::draw(QPainter &painter)
{
	QPoint topLeftInQtCoordinates = RenderContainer::frameTransform->convertToQTCoordinateSystem(m_rect.topLeft());
	QPoint bottomRightInQtCoordinates = RenderContainer::frameTransform->convertToQTCoordinateSystem(m_rect.bottomRight());
	QRect newRect(topLeftInQtCoordinates, bottomRightInQtCoordinates);
	painter.setPen(m_pen);
	painter.drawRect(newRect);
}

QRect FigureRect::get()
{
	return m_rect;
}
void FigureRect::set(QRect rect)
{
	m_rect = rect;
}

QPoint FigureRect::getCenter()
{
	return m_rect.center();
}
void FigureRect::setCenter(const QPoint &newCenter)
{
	m_rect = QRect(newCenter.x() - m_rect.width()/2, newCenter.y() - m_rect.height()/2, m_rect.width(), m_rect.height());
}

QPen FigureRect::getPen()
{
	return m_pen;
}
void FigureRect::setPen(const QPen &newPen)
{
	m_pen = newPen;
}

QRect FigureRect::getBoundingRect()
{
	return m_rect;
}

bool FigureRect::containedInTheContour(const QPoint &pos)
{
	int delta = RenderContainer::frameTransform->convertDistanceToNewCoordinateSystem(2 * m_pen.width());

	if (((pos.x() >= m_rect.left() - delta) && pos.x() <= m_rect.left() + delta)
	||  ((pos.x() <= m_rect.right() + delta) && pos.x() >= m_rect.right() - delta))
	{
		return (pos.y() > m_rect.top() - delta) && (pos.y() < m_rect.bottom() + delta);
	}
	else if (((pos.y() >= m_rect.bottom() - delta) && (pos.y() <= m_rect.bottom() + delta))
		|| ((pos.y() >= m_rect.top() - delta) && (pos.y() <= m_rect.top() + delta)))
	{
		return (pos.x() < m_rect.right() && pos.x() > m_rect.left());
	}

	return false;
}

