#include "PaintWidget.h"
#include <QMouseEvent>
#include <QCoreApplication>
#include <memory> 
#include "FigureArrow.h"

std::vector <std::shared_ptr<Figure>> RenderContainer::objectsOnFrame;
std::vector <std::shared_ptr<Command>> CommandQueue::redoCommand;
std::vector <std::shared_ptr<Command>> CommandQueue::undoCommand;
std::vector <std::shared_ptr<Figure>> RenderContainer::selectedObjects;
std::shared_ptr<Transform> RenderContainer::frameTransform;
QPen RenderContainer::pen;

PaintWidget::PaintWidget(QWidget *parent)
	: QWidget(parent),
	activeTool(nullptr)
{
	ui.setupUi(this);
	RenderContainer::frameTransform = std::make_shared<Transform>(this->ui.drawWidget->pos() + QPoint(this->ui.drawWidget->width() / 2, this->ui.drawWidget->height() / 2), 1.0, QPoint(1, -1));

	auto axisX = std::make_shared<FigureArrow>(QPoint(0,0), QPoint(70, 0), true);
	auto axisY = std::make_shared<FigureArrow>(QPoint(0, 0), QPoint(0, 70), true);

	axisX->setPen(QPen(Qt::red, RenderContainer::normalLineWidth));
	axisY->setPen(QPen(Qt::green, RenderContainer::normalLineWidth));

	RenderContainer::objectsOnFrame.push_back(axisX);
	RenderContainer::objectsOnFrame.push_back(axisY);

	RenderContainer::pen = QPen(Qt::black, RenderContainer::normalLineWidth);
}

PaintWidget::~PaintWidget(){}

void PaintWidget::mousePressEvent(QMouseEvent *e)
{
	if (activeTool)
	{
		QPoint newPos = RenderContainer::frameTransform->convertToNewCoordinateSystem(e->pos());
		bool ctrlPressed = QApplication::keyboardModifiers().testFlag(Qt::ControlModifier);
		activeTool->mousePress(newPos, ctrlPressed);
	}
}

void PaintWidget::mouseMoveEvent(QMouseEvent *e)
{
	if (activeTool)
	{
		QPoint newPos = RenderContainer::frameTransform->convertToNewCoordinateSystem(e->pos());
		bool ctrlPressed = QApplication::keyboardModifiers().testFlag(Qt::ControlModifier);
		activeTool->mouseMove(newPos, ctrlPressed);
	}
	update();
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *e)
{
	if (activeTool)
	{
		QPoint newPos = RenderContainer::frameTransform->convertToNewCoordinateSystem(e->pos());
		bool ctrlPressed = QApplication::keyboardModifiers().testFlag(Qt::ControlModifier);
		activeTool->mouseRelease(newPos, ctrlPressed);
	}
	update();
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
	painter.begin(this);
	painter.setClipRect(QRect(ui.drawWidget->pos(), ui.drawWidget->size()));

	for (int i = 0; i < RenderContainer::objectsOnFrame.size(); i++)
	{
		painter.setPen(RenderContainer::objectsOnFrame[i]->getPen());
		RenderContainer::objectsOnFrame[i]->draw(painter);
	}
	painter.end();
}

void PaintWidget::on_btnRect_clicked()
{
	activeTool = &toolCreateRect;
	activeTool->initAction();
	update();
}

void PaintWidget::on_btnLine_clicked()
{
	activeTool = &toolCreateLine;
	activeTool->initAction();
	update();
}

void PaintWidget::on_btnCircle_clicked()
{
	activeTool = &toolCreateCircle;
	activeTool->initAction();
	update();
}

void PaintWidget::on_btnSelect_clicked()
{
	activeTool = &toolSelectObject;
	activeTool->initAction();
	update();
}

void PaintWidget::on_btnMove_clicked()
{
	activeTool = &toolMoveObject;
	activeTool->initAction();
	update();
}

void PaintWidget::on_btnDelete_clicked()
{
	activeTool = &toolDeleteObject;
	activeTool->initAction();
	update();
}
void PaintWidget::on_btnUndo_clicked()
{
	activeTool = nullptr;

	if (!CommandQueue::undoCommand.empty())
	{
		CommandQueue::undoCommand.back()->undo();
		CommandQueue::redoCommand.push_back(CommandQueue::undoCommand.back());
		CommandQueue::undoCommand.pop_back();
		update();
	}
}
void PaintWidget::on_btnRedo_clicked()
{
	activeTool = nullptr;

	if (!CommandQueue::redoCommand.empty())
	{
		CommandQueue::redoCommand.back()->redo();
		CommandQueue::undoCommand.push_back(CommandQueue::redoCommand.back());
		CommandQueue::redoCommand.pop_back();
		update();
	}
}

void PaintWidget::on_btnZoomIn_clicked()
{
	activeTool = nullptr;

	double k = 1.2;
	QPoint frameCenter(this->ui.drawWidget->width()/2, this->ui.drawWidget->height()/2);
	frameCenter += this->ui.drawWidget->pos();
	RenderContainer::frameTransform->zoom(k, frameCenter);
	update();
}

void PaintWidget::on_btnZoomOut_clicked()
{
	activeTool = nullptr;

	double k = 1.0 / 1.2;
	QPoint frameCenter(this->ui.drawWidget->width()/2, this->ui.drawWidget->height()/2);
	frameCenter += this->ui.drawWidget->pos();
	RenderContainer::frameTransform->zoom(k, frameCenter);
	update();
}

void PaintWidget::on_btnZoomAll_clicked()
{
	activeTool = nullptr;

	if (!RenderContainer::objectsOnFrame.empty())
	{
		int offset = RenderContainer::frameTransform->convertDistanceToNewCoordinateSystem(5);
		bool found = false;
		QRect boundingRect;
		for (int i = 0; i < RenderContainer::objectsOnFrame.size(); i++)
		{
			if (!RenderContainer::objectsOnFrame[i]->isSystem())
			{
				QRect current = RenderContainer::objectsOnFrame[i]->getBoundingRect();
				if (!found)
				{
					boundingRect = current;
					found = true;
				}
				else
				{
					boundingRect = boundingRect.united(current);
				}
			}
		}

		if (found)
		{
			boundingRect = QRect(boundingRect.topLeft() - QPoint(offset, offset) / 2, boundingRect.size() + QSize(offset, offset));

			int qtWidth = RenderContainer::frameTransform->convertDistanceToQTCoordinateSystem(boundingRect.width());
			int qtHeight = RenderContainer::frameTransform->convertDistanceToQTCoordinateSystem(boundingRect.height());

			double widthScale = ((double)this->ui.drawWidget->width()) / qtWidth;
			double heightScale = ((double)this->ui.drawWidget->height()) / qtHeight;
			double scale = std::min(widthScale, heightScale);
			RenderContainer::frameTransform->zoom(scale);

			QPoint frameCenter(this->ui.drawWidget->width() / 2, this->ui.drawWidget->height() / 2);
			frameCenter += this->ui.drawWidget->pos();
			QPoint newCenter = boundingRect.center();
			RenderContainer::frameTransform->adjustTranslate(frameCenter, newCenter);

			update();
		}
	}
}

void PaintWidget::on_btnMoveFrame_clicked()
{
	activeTool = &toolMoveFrame;
	activeTool->initAction();
	update();
}

void PaintWidget::on_redColorBtn_clicked()
{
	QColor color("red");
	setPenColor(color);
	update();	
}

void PaintWidget::on_greenColorBtn_clicked()
{
	QColor color("green");
	setPenColor(color);
	update();
}

void PaintWidget::on_blueColorBtn_clicked()
{
	QColor color("blue");
	setPenColor(color);
	update();
}

void PaintWidget::on_blackColorBtn_clicked()
{
	QColor color("black");
	setPenColor(color);

	update();
}

void PaintWidget::setPenColor(const QColor &color)
{
	RenderContainer::pen.setColor(color);
	ui.activeColorBtn->setStyleSheet("background-color: " + color.name());
	for (int i = 0; i < RenderContainer::selectedObjects.size(); i++)
	{
		RenderContainer::selectedObjects[i]->setPen(QPen(RenderContainer::pen.color(), RenderContainer::selectedLineWidth));
	}
}