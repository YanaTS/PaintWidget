#include "ToolSelectObject.h"
#include "RenderContainer.h"


ToolSelectObject::ToolSelectObject(){}

ToolSelectObject::~ToolSelectObject(){}

void ToolSelectObject::mouseMove(const QPoint &pos, bool ctrlPressed){}

void ToolSelectObject::mousePress(const QPoint &pos, bool ctrlPressed)
{
	if (!ctrlPressed)
	{
		deselectAll();
	}

	for (int i = 0; i < RenderContainer::objectsOnFrame.size(); i++)
	{
		if (!RenderContainer::objectsOnFrame[i]->isSystem() &&
			RenderContainer::objectsOnFrame[i]->containedInTheContour(pos))
		{
			std::shared_ptr<Figure> selectedObj = RenderContainer::objectsOnFrame[i];
			selectedObj->setPen(QPen(selectedObj->getPen().color(), RenderContainer::selectedLineWidth));
			RenderContainer::selectedObjects.push_back(selectedObj);
			return;
		}
	}
}

void ToolSelectObject::mouseRelease(const QPoint &pos, bool ctrlPressed){}

void ToolSelectObject::initAction() {}
