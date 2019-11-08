#pragma once
#include "Tool.h"
class ToolMoveFrame :
	public Tool
{
public:
	ToolMoveFrame();
	~ToolMoveFrame();
	void mousePress(const QPoint &point, bool ctrlPressed) override;
	void mouseMove(const QPoint &point, bool ctrlPressed) override;
	void mouseRelease(const QPoint &point, bool ctrlPressed) override;
	void initAction() override;

private:
	QPoint m_prevPos;
	QPoint m_prevAdditional;
	bool m_active;
};

