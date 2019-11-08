#pragma once
#include "Command.h"
#include "Figure.h"
#include <memory>

class CommandDelete :
	public Command
{
public:
	CommandDelete(std::shared_ptr<Figure> figure);
	~CommandDelete();
	void undo()  override;
	void redo()  override;
private:
	std::shared_ptr<Figure> m_figure;
};

