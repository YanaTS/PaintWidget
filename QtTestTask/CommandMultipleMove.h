#pragma once
#include "Command.h"
#include "Figure.h"
#include <QPoint>
#include <memory>


class CommandMultipleMove :
	public Command
{
public:
	CommandMultipleMove(const std::vector<QPoint> &initPoint, const std::vector<QPoint> &finalPoint, const std::vector<std::shared_ptr<Figure>> &figure);
	~CommandMultipleMove();
	void undo()  override;
	void redo()  override;
private:
	std::vector<QPoint> m_initPoints;
	std::vector<QPoint> m_finalPoints;
	std::vector<std::shared_ptr<Figure>> m_figures;
};

