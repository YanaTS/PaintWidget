#pragma once
#include "qobject.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <memory>
#include "Tool.h"
#include "FigureLine.h"
class ToolMoveObject :
	public Tool
{	
public:
	explicit ToolMoveObject();
	~ToolMoveObject();
	void mousePress(const QPoint &point, bool ctrlPressed) override;
	void mouseMove(const QPoint &point, bool ctrlPressed) override;
	void mouseRelease(const QPoint &point, bool ctrlPressed) override;
	void initAction() override;

private:
	QPoint m_prevPos;
	std::vector<QPoint> m_prevCeneters;
	std::vector<std::shared_ptr<FigureLine>> m_shiftLineFigures;
};

