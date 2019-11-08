#pragma once
#include "Tool.h"
class ToolSelectObject :
	public Tool
{
public:
	ToolSelectObject();
	~ToolSelectObject();
	void mousePress(const QPoint &point, bool ctrlPressed) override;
	void mouseMove(const QPoint &point, bool ctrlPressed) override;
	void mouseRelease(const QPoint &point, bool ctrlPressed) override;
	void initAction() override;
};

