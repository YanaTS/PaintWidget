#pragma once
#include "Command.h"
#include "Figure.h"
#include <QPoint>
#include <memory>


class CommandMove :
	public Command
{
public:
	CommandMove(const QPoint &initPoint, const QPoint & finalPoint, std::shared_ptr<Figure> figure);
	~CommandMove();
	void undo()  override;
	void redo()  override;
private:
	QPoint m_initPoint;
	QPoint m_finalPoint;
	std::shared_ptr<Figure> m_figure;
};

