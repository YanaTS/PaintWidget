#pragma once
#include "Tool.h"

class ToolDeleteObject :
	public Tool
{
public:
	ToolDeleteObject();
	~ToolDeleteObject();
	void mousePress(const QPoint &point, bool ctrlPressed) override;
	void mouseMove(const QPoint &point, bool ctrlPressed) override;
	void mouseRelease(const QPoint &point, bool ctrlPressed) override;
	void initAction() override;
};

