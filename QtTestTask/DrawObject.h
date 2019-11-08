#pragma once
#include "qobject.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QGraphicsItem>
class DrawObject :
	public QObject, public QGraphicsItem
{
public:
	DrawObject(QObject *parent = 0);
	~DrawObject();
private:
	QRectF boundingRect() const;
	QRectF mRect;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

	bool mousePressed;
	bool drawStarted;
};

