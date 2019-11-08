#pragma once
#include "Command.h"
#include "Figure.h"
#include <memory>

class CommandMultipleDelete :
	public Command
{
public:
	CommandMultipleDelete(const std::vector<std::shared_ptr<Figure>> &figures);
	~CommandMultipleDelete();
	void undo()  override;
	void redo()  override;
private:
	std::vector<std::shared_ptr<Figure>> m_figures;
};

