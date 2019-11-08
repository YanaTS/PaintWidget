#pragma once
#include <QPoint>
class Transform
{
public:
	Transform(const QPoint &additional, double zoomFactor, const QPoint &sign);
	~Transform();
	QPoint convertToNewCoordinateSystem(const QPoint &oldCoordinates);
	QPoint convertToQTCoordinateSystem(const QPoint &oldCoordinates);
	int convertDistanceToQTCoordinateSystem(int initDistance);
	int convertDistanceToNewCoordinateSystem(int initDistance);
	void moveFrame(const QPoint &initPos, const QPoint &finPos);
	void zoom(double scale);
	void zoom(double scale, const QPoint &keepQtPoint);
	void adjustTranslate(const QPoint &qtCoordinates, const QPoint &newCoordinates);
	QPoint m_additional;
	double m_zoomFactor;
	QPoint m_sign;
};

