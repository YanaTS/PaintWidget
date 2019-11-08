#pragma once
#include <QMouseEvent>
#include <QSize>
class Tool
{
public:
	Tool();
	virtual ~Tool();

	virtual void mousePress(const QPoint &point, bool ctrlPressed) = 0;
	virtual void mouseMove(const QPoint &point, bool ctrlPressed) = 0;
	virtual void mouseRelease(const QPoint &point, bool ctrlPressed) = 0;
	virtual void initAction() = 0;

	void deselectAll();
};

