#include "ToolMoveObject.h"
#include "RenderContainer.h"
#include "QVector2D"
#include "CommandMove.h"
#include "CommandMultipleMove.h"
#include "CommandQueue.h"
#include "FigureLine.h"
#include <algorithm>

ToolMoveObject::ToolMoveObject(){}

ToolMoveObject::~ToolMoveObject(){}

void ToolMoveObject::mouseMove(const QPoint &pos, bool ctrlPressed)
{
	if (!RenderContainer::selectedObjects.empty())
	{
		QPoint shift(pos - m_prevPos);
		for (int i = 0; i < RenderContainer::selectedObjects.size(); i++)
		{
			QPoint newCenter = m_prevCeneters[i] + shift;
			RenderContainer::selectedObjects[i]->setCenter(newCenter);

			QLine shiftLine(m_prevCeneters[i], newCenter);
			m_shiftLineFigures[i]->set(shiftLine);
		}
	}
}

void ToolMoveObject::mousePress(const QPoint &pos, bool ctrlPressed)
{
	if (!RenderContainer::selectedObjects.empty())
	{
		m_prevPos = pos;

		m_prevCeneters.resize(RenderContainer::selectedObjects.size());
		m_shiftLineFigures.resize(RenderContainer::selectedObjects.size());

		for (int i = 0; i < RenderContainer::selectedObjects.size(); i++)
		{
			std::shared_ptr<Figure> selectedObj = RenderContainer::selectedObjects[i];
			RenderContainer::selectedObjects[i]->m_prevPen = selectedObj->getPen();
			selectedObj->setPen(QPen(Qt::gray, 2, Qt::DashDotLine));

			QPoint prevCeneter = selectedObj->getCenter();
			m_prevCeneters[i] = prevCeneter;

			QLine shiftLine(prevCeneter, prevCeneter);
			std::shared_ptr<FigureLine> shiftLineFigure = std::make_shared<FigureLine>(shiftLine);
			shiftLineFigure->setPen(QPen(Qt::red, RenderContainer::normalLineWidth));
			RenderContainer::objectsOnFrame.push_back(shiftLineFigure);
			m_shiftLineFigures[i] = shiftLineFigure;
		}
	}
}

void ToolMoveObject::mouseRelease(const QPoint &pos, bool ctrlPressed)
{
	if (!RenderContainer::selectedObjects.empty())
	{
		std::shared_ptr<Command> command;
		if (RenderContainer::selectedObjects.size() == 1)
		{
			command = std::make_shared<CommandMove>(m_prevCeneters[0], RenderContainer::selectedObjects[0]->getCenter(), RenderContainer::selectedObjects[0]);
		}
		else
		{
			std::vector<QPoint> newCenters(RenderContainer::selectedObjects.size());
			for (int i = 0; i < RenderContainer::selectedObjects.size(); i++)
			{
				newCenters[i] = RenderContainer::selectedObjects[i]->getCenter();
			}
			command = std::make_shared<CommandMultipleMove>(m_prevCeneters, newCenters, RenderContainer::selectedObjects);
		}
		CommandQueue::undoCommand.push_back(command);

		auto &vec = RenderContainer::objectsOnFrame;
		for (int i = 0; i < m_shiftLineFigures.size(); i++)
		{
			vec.erase(std::remove(vec.begin(), vec.end(), m_shiftLineFigures[i]), vec.end());
		}

		for (int i = 0; i < RenderContainer::selectedObjects.size(); i++)
		{
			RenderContainer::selectedObjects[i]->setPen(RenderContainer::selectedObjects[i]->m_prevPen);
		}
		m_prevCeneters.clear();
		m_shiftLineFigures.clear();
	}	
}

void ToolMoveObject::initAction(){}
