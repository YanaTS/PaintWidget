/********************************************************************************
** Form generated from reading UI file 'QtTestTask.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTESTTASK_H
#define UI_QTTESTTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtTestTaskClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtTestTaskClass)
    {
        if (QtTestTaskClass->objectName().isEmpty())
            QtTestTaskClass->setObjectName(QStringLiteral("QtTestTaskClass"));
        QtTestTaskClass->resize(600, 400);
        menuBar = new QMenuBar(QtTestTaskClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtTestTaskClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtTestTaskClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtTestTaskClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtTestTaskClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtTestTaskClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtTestTaskClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtTestTaskClass->setStatusBar(statusBar);

        retranslateUi(QtTestTaskClass);

        QMetaObject::connectSlotsByName(QtTestTaskClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtTestTaskClass)
    {
        QtTestTaskClass->setWindowTitle(QApplication::translate("QtTestTaskClass", "QtTestTask", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtTestTaskClass: public Ui_QtTestTaskClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTESTTASK_H
