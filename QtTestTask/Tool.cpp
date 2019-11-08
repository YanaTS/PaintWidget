#include "Tool.h"
#include "RenderContainer.h"
#include <QPoint>

Tool::Tool(){}

Tool::~Tool(){}

void Tool::deselectAll()
{
	for (int i = 0; i < RenderContainer::selectedObjects.size(); i++)
	{
		std::shared_ptr<Figure> selectedObj = RenderContainer::selectedObjects[i];
		selectedObj->setPen(QPen(selectedObj->getPen().color(), RenderContainer::normalLineWidth));
	}
	RenderContainer::selectedObjects.clear();
}