#pragma once
#include "Tool.h"
#include "FigureRect.h"
#include "CommandCreate.h"

class ToolCreateRect :
	public Tool
{
public:
	ToolCreateRect();
	~ToolCreateRect();
	void mousePress(const QPoint &point, bool ctrlPressed) override;
	void mouseMove(const QPoint &point, bool ctrlPressed) override;
	void mouseRelease(const QPoint &point, bool ctrlPressed) override;
	void initAction() override;
private:
	std::shared_ptr<FigureRect> m_rectObject;
};

