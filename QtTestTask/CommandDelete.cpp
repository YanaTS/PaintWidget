#include "CommandDelete.h"
#include "RenderContainer.h"

CommandDelete::CommandDelete(std::shared_ptr<Figure> figure): m_figure(figure){}

CommandDelete::~CommandDelete(){}

void CommandDelete::undo()
{
	RenderContainer::objectsOnFrame.push_back(m_figure);
}		

void CommandDelete::redo()
{
	auto &vec = RenderContainer::objectsOnFrame;
	vec.erase(std::remove(vec.begin(), vec.end(), m_figure), vec.end());
}
