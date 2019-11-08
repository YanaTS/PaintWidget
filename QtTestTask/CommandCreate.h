#pragma once
#include "Command.h"
#include "Figure.h"
#include "RenderContainer.h"
class CommandCreate :
	public Command
{
public:
	CommandCreate(std::shared_ptr<Figure> figure);
	~CommandCreate();
	void undo()  override;
	void redo()  override;
private:
	std::shared_ptr<Figure> m_figure;
};

