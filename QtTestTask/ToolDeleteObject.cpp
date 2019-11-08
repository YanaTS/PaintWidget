#include "ToolDeleteObject.h"
#include "RenderContainer.h"
#include "CommandDelete.h"
#include "CommandMultipleDelete.h"
#include "CommandQueue.h"

ToolDeleteObject::ToolDeleteObject() {}

ToolDeleteObject::~ToolDeleteObject() {}

void ToolDeleteObject::initAction()
{
	if (!RenderContainer::selectedObjects.empty())
	{
		std::shared_ptr<Command> command;
		if (RenderContainer::selectedObjects.size() == 1)
		{
			command = std::make_shared<CommandDelete>(RenderContainer::selectedObjects[0]);
		}
		else
		{
			command = std::make_shared<CommandMultipleDelete>(RenderContainer::selectedObjects);
		}
		command->redo();
		CommandQueue::undoCommand.push_back(command);
	}
}

void ToolDeleteObject::mousePress(const QPoint &pos, bool ctrlPressed) {}

void ToolDeleteObject::mouseMove(const QPoint &pos, bool ctrlPressed) {}

void ToolDeleteObject::mouseRelease(const QPoint &pos, bool ctrlPressed) {}