#pragma once

#include <QtWidgets/QMainWindow>

namespace Ui {
	class QtTestTask;
}

class QtTestTask : public QMainWindow
{
	Q_OBJECT

public:
	explicit QtTestTask(QWidget *parent = 0);

private:
	Ui::QtTestTask* ui;
};
