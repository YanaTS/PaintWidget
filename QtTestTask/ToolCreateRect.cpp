#include "ToolCreateRect.h"
#include "RenderContainer.h"
#include "CommandQueue.h"

ToolCreateRect::ToolCreateRect(): m_rectObject(nullptr){}

ToolCreateRect::~ToolCreateRect(){}

void ToolCreateRect::mousePress(const QPoint &pos, bool ctrlPressed)
{
	QRect rect = QRect(pos, pos);
	m_rectObject = std::make_shared<FigureRect>(rect);
	m_rectObject->setPen(RenderContainer::pen);
	RenderContainer::objectsOnFrame.push_back(m_rectObject);	
}
void ToolCreateRect::mouseMove(const QPoint &pos, bool ctrlPressed)
{
	if (m_rectObject)
	{
		QRect rect = m_rectObject->get();
		rect.setBottomRight(pos);
		m_rectObject->set(rect);	
	}
}
void ToolCreateRect::mouseRelease(const QPoint &pos, bool ctrlPressed)
{
	QRect rect = m_rectObject->get();
	m_rectObject->set(rect.normalized());

	CommandQueue::undoCommand.push_back(std::make_shared<CommandCreate>(m_rectObject));
	m_rectObject = nullptr;
}

void ToolCreateRect::initAction()
{
	deselectAll();
}
