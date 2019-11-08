#include "Transform.h"

Transform::Transform(const QPoint &additional, double zoomFactor, const QPoint & sign):
	m_additional(additional),
	m_zoomFactor(zoomFactor),
	m_sign(sign)
{}

Transform::~Transform(){}

QPoint Transform::convertToNewCoordinateSystem(const QPoint &oldCoordinates)
{
	QPoint newCoordinates;
	newCoordinates.setX((m_sign.x()*oldCoordinates.x() / m_zoomFactor - m_sign.x()*m_additional.x()));
	newCoordinates.setY((m_sign.y()*oldCoordinates.y() / m_zoomFactor - m_sign.y()*m_additional.y()));
	return newCoordinates;
}

QPoint Transform::convertToQTCoordinateSystem(const QPoint &oldCoordinates)
{
	QPoint qtCoordinates;
	qtCoordinates.setX((m_sign.x()*oldCoordinates.x() + m_additional.x())*m_zoomFactor);
	qtCoordinates.setY((m_sign.y()*oldCoordinates.y() + m_additional.y())*m_zoomFactor);
	return qtCoordinates;
}

int Transform::convertDistanceToQTCoordinateSystem(int initDistance)
{
	return initDistance * m_zoomFactor;
}

int Transform::convertDistanceToNewCoordinateSystem(int initDistance)
{
	return initDistance / m_zoomFactor;
}

void Transform::moveFrame(const QPoint &initPos, const QPoint &finPos)
{
	QPoint shift(initPos - finPos);
	m_additional += shift;
}

void Transform::zoom(double scale)
{
	m_zoomFactor *= scale;
}

void Transform::zoom(double scale, const QPoint &keepQtPoint)
{
	m_additional = m_additional - (scale - 1)*keepQtPoint / m_zoomFactor / scale;
	m_zoomFactor *= scale;
}

void Transform::adjustTranslate(const QPoint &qtCoordinates, const QPoint &newCoordinates)
{
	m_additional.setX(qtCoordinates.x() / m_zoomFactor - m_sign.x()*newCoordinates.x());
	m_additional.setY(qtCoordinates.y() / m_zoomFactor - m_sign.y()*newCoordinates.y());
}