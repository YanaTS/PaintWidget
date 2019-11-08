#include "DrawObject.h"

DrawObject::DrawObject(QObject *parent):
	QObject(parent), QGraphicsItem()
{}

DrawObject::~DrawObject(){}

QRectF DrawObject::boundingRect() const
{
	return QRectF(-mRect.left(), -mRect.top(), mRect.width(), mRect.height());
}

void DrawObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	
	if (mousePressed) {
		 
		drawStarted = true;

		painter->setPen(Qt::black);
		painter->setBrush(Qt::transparent);
		painter->drawRect(-mRect.left(), -mRect.top(), mRect.width(), mRect.height());
	}
	else if (drawStarted) {
		
		painter->setPen(Qt::black);
		painter->setBrush(Qt::transparent);
		painter->drawRect(-mRect.left(), -mRect.top(), mRect.width(), mRect.height());
	}		
	Q_UNUSED(option);
	Q_UNUSED(widget);
}

void DrawObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{	
	if (event->type() == QEvent::MouseMove)
	{
		mRect.setBottomRight(event->pos());
	}	
}

void DrawObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	mousePressed = true;
	mRect.setTopLeft(event->pos());
	mRect.setBottomRight(event->pos());	
}

void DrawObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	mousePressed = false;
	update();
}
