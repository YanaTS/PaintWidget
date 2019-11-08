#include "CommandMove.h"

CommandMove::CommandMove(const QPoint &initPoint, const QPoint &finalPoint, std::shared_ptr<Figure> figure):
	m_initPoint(initPoint),
	m_finalPoint(finalPoint),
	m_figure(figure) {}


CommandMove::~CommandMove(){}

void CommandMove::undo()
{
	m_figure->setCenter(m_initPoint);
}

void CommandMove::redo()
{
	m_figure->setCenter(m_finalPoint);
}
