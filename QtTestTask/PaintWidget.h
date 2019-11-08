#pragma once

#include <QWidget>
#include "ui_PaintWidget.h"
#include <qpainter.h>

#include <vector>

#include"ToolMoveObject.h"
#include "ToolMoveFrame.h"
#include "ToolCreateRect.h"
#include "ToolCreateLine.h"
#include "ToolCreateCircle.h"
#include "Tool.h"
#include "RenderContainer.h"
#include "ToolDeleteObject.h"
#include "ToolSelectObject.h"
#include "CommandQueue.h"
#include "Transform.h"


class PaintWidget : public QWidget
{
	Q_OBJECT

public:
	PaintWidget(QWidget *parent = Q_NULLPTR);
	~PaintWidget();

private slots:
	void on_btnRect_clicked();
	void on_btnLine_clicked();
	void on_btnCircle_clicked();
	void on_btnMove_clicked();
	void on_btnSelect_clicked();
	void on_btnDelete_clicked();
	void on_btnUndo_clicked();
	void on_btnRedo_clicked();
	void on_btnZoomIn_clicked();
	void on_btnZoomOut_clicked();
	void on_btnZoomAll_clicked();
	void on_btnMoveFrame_clicked();
	void on_redColorBtn_clicked();
	void on_greenColorBtn_clicked();
	void on_blueColorBtn_clicked();
	void on_blackColorBtn_clicked();

	
private:
	Ui::PaintWidget ui;

	void setPenColor(const QColor & color);

	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void paintEvent(QPaintEvent *event);

	QPainter painter;
	std::vector<QRect> allRects;
	Tool *activeTool;

	ToolCreateRect toolCreateRect;
	ToolCreateLine toolCreateLine;
	ToolCreateCircle toolCreateCircle;
	ToolSelectObject toolSelectObject;
	ToolMoveObject toolMoveObject;
	ToolDeleteObject toolDeleteObject;
	ToolMoveFrame toolMoveFrame;
};
