#include "ToolMoveFrame.h"
#include "RenderContainer.h"

ToolMoveFrame::ToolMoveFrame(): m_active(false){}

ToolMoveFrame::~ToolMoveFrame(){}

void ToolMoveFrame::mouseMove(const QPoint &pos, bool ctrlPressed)
{
	QPoint posQt = RenderContainer::frameTransform->convertToQTCoordinateSystem(pos);
	if(m_active)
	{
		QPoint shift(posQt - m_prevPos);
		QPoint shiftNew;
		shiftNew.setX(RenderContainer::frameTransform->convertDistanceToNewCoordinateSystem(shift.x()));
		shiftNew.setY(RenderContainer::frameTransform->convertDistanceToNewCoordinateSystem(shift.y()));

		RenderContainer::frameTransform->m_additional = m_prevAdditional + shiftNew;
	}
}

void ToolMoveFrame::mousePress(const QPoint &pos, bool ctrlPressed)
{
	m_prevPos = RenderContainer::frameTransform->convertToQTCoordinateSystem(pos);
	m_prevAdditional = RenderContainer::frameTransform->m_additional;
	m_active = true;
}

void ToolMoveFrame::mouseRelease(const QPoint &pos, bool ctrlPressed)
{
	m_active = false;	
}

void ToolMoveFrame::initAction() {}
