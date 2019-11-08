#pragma once
#include "Tool.h"
#include "FigureLine.h"
#include <memory>
class ToolCreateLine :
	public Tool
{
public:
	ToolCreateLine();
	~ToolCreateLine();
	void mousePress(const QPoint &point, bool ctrlPressed) override;
	void mouseMove(const QPoint &point, bool ctrlPressed) override;
	void mouseRelease(const QPoint &point, bool ctrlPressed) override;
	void initAction() override;
private:
	std::shared_ptr<FigureLine> m_lineObject;

};

