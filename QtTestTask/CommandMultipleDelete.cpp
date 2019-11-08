#include "CommandMultipleDelete.h"
#include "RenderContainer.h"


CommandMultipleDelete::CommandMultipleDelete(const std::vector<std::shared_ptr<Figure>> &figures) : m_figures(figures) {}

CommandMultipleDelete::~CommandMultipleDelete() {}

void CommandMultipleDelete::undo()
{
	for (int i = 0; i < m_figures.size(); i++)
	{
		RenderContainer::objectsOnFrame.push_back(m_figures[i]);
	}
}

void CommandMultipleDelete::redo()
{
	auto &vec = RenderContainer::objectsOnFrame;
	for (int i = 0; i < m_figures.size(); i++)
	{
		vec.erase(std::remove(vec.begin(), vec.end(), m_figures[i]), vec.end());
	}
}