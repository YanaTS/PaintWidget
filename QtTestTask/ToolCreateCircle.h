#pragma once
#include "Tool.h"
#include "FigureCircle.h"
#include "FigureLine.h"
#include <memory>
class ToolCreateCircle :
	public Tool
{
public:
	ToolCreateCircle();
	~ToolCreateCircle();
	void mousePress(const QPoint &point, bool ctrlPressed) override;
	void mouseMove(const QPoint &point, bool ctrlPressed) override;
	void mouseRelease(const QPoint &point, bool ctrlPressed) override;
	void initAction() override;
private:
	std::shared_ptr<FigureCircle> m_circleObject;
	std::shared_ptr<FigureLine> m_rdiusLineFigure;
};

