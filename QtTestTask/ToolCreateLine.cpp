#include "ToolCreateLine.h"
#include "RenderContainer.h"
#include "CommandCreate.h"
#include "CommandQueue.h"

ToolCreateLine::ToolCreateLine(): m_lineObject(nullptr){}

ToolCreateLine::~ToolCreateLine(){}

void ToolCreateLine::mousePress(const QPoint &pos, bool ctrlPressed)
{
	QLine line = QLine(pos, pos);
	m_lineObject = std::make_shared<FigureLine>(line);
	m_lineObject->setPen(RenderContainer::pen);
	RenderContainer::objectsOnFrame.push_back(m_lineObject);
}
void ToolCreateLine::mouseMove(const QPoint &pos, bool ctrlPressed)
{
	if (m_lineObject)
	{
		QLine line = m_lineObject->get();
		line.setP2(pos);
		m_lineObject->set(line);
	}
}
void ToolCreateLine::mouseRelease(const QPoint &pos, bool ctrlPressed)
{
	CommandQueue::undoCommand.push_back(std::make_shared<CommandCreate>(m_lineObject));
	m_lineObject = nullptr;
}

void ToolCreateLine::initAction()
{
	deselectAll();
}
