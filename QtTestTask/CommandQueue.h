#pragma once

#include "Command.h"
#include <vector>
#include <QRect>


class CommandQueue
{
public:
	static std::vector <std::shared_ptr<Command>> redoCommand;
	static std::vector <std::shared_ptr<Command>> undoCommand;
};