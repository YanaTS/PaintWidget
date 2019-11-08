#include "CommandMultipleMove.h"

CommandMultipleMove::CommandMultipleMove(const std::vector<QPoint> &initPoints, const std::vector<QPoint> &finalPoints, const std::vector<std::shared_ptr<Figure>> &figures) :
	m_initPoints(initPoints),
	m_finalPoints(finalPoints),
	m_figures(figures) {}


CommandMultipleMove::~CommandMultipleMove()
{
}

void CommandMultipleMove::undo()
{
	for (int i = 0; i < m_figures.size(); i++)
	{
		m_figures[i]->setCenter(m_initPoints[i]);
	}
}

void CommandMultipleMove::redo()
{
	for (int i = 0; i < m_figures.size(); i++)
	{
		m_figures[i]->setCenter(m_finalPoints[i]);
	}
}
