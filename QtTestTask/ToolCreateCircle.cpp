#include "ToolCreateCircle.h"
#include "RenderContainer.h"
#include "CommandCreate.h"
#include "CommandQueue.h"
ToolCreateCircle::ToolCreateCircle(): m_circleObject(nullptr){}

ToolCreateCircle::~ToolCreateCircle(){}

void ToolCreateCircle::mousePress(const QPoint &pos, bool ctrlPressed)
{
	QPoint center = pos;
	int radius = 0;
	m_circleObject = std::make_shared<FigureCircle>(center, radius);
	RenderContainer::objectsOnFrame.push_back(m_circleObject);

	QLine radiusLine(center, center);
	m_rdiusLineFigure = std::make_shared<FigureLine>(radiusLine);
	m_rdiusLineFigure->setPen(RenderContainer::pen);
	RenderContainer::objectsOnFrame.push_back(m_rdiusLineFigure);
}
void ToolCreateCircle::mouseMove(const QPoint &pos, bool ctrlPressed)
{
	if (m_circleObject)
	{		
		int radius = sqrt(pow(m_circleObject->getCenter().x() - pos.x(),2) + pow(m_circleObject->getCenter().y() - pos.y(), RenderContainer::normalLineWidth));
		m_circleObject->setRadius(radius);

		QLine radiusLine(m_circleObject->getCenter(), pos);
		m_rdiusLineFigure->set(radiusLine);

	}
}
void ToolCreateCircle::mouseRelease(const QPoint &pos, bool ctrlPressed)
{
	CommandQueue::undoCommand.push_back(std::make_shared<CommandCreate>(m_circleObject));
	m_circleObject = nullptr;

	auto &vec = RenderContainer::objectsOnFrame;
	vec.erase(std::remove(vec.begin(), vec.end(), m_rdiusLineFigure), vec.end());
}

void ToolCreateCircle::initAction()
{
	deselectAll();
}
