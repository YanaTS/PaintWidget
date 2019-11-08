#include "CommandCreate.h"

CommandCreate::CommandCreate(std::shared_ptr<Figure> figure): m_figure(figure){}

CommandCreate::~CommandCreate(){}

void CommandCreate::undo()
{
	auto &vec = RenderContainer::objectsOnFrame;
	vec.erase(std::remove(vec.begin(), vec.end(), m_figure), vec.end());	
}

void CommandCreate::redo()
{
	RenderContainer::objectsOnFrame.push_back(m_figure);	
}
