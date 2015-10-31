/********************************************************************************
** Form generated from reading UI file 'fiveofruler.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIVEOFRULER_H
#define UI_FIVEOFRULER_H

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

class Ui_FiveOfRulerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FiveOfRulerClass)
    {
        if (FiveOfRulerClass->objectName().isEmpty())
            FiveOfRulerClass->setObjectName(QStringLiteral("FiveOfRulerClass"));
        FiveOfRulerClass->resize(600, 400);
        menuBar = new QMenuBar(FiveOfRulerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        FiveOfRulerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FiveOfRulerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FiveOfRulerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(FiveOfRulerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FiveOfRulerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FiveOfRulerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FiveOfRulerClass->setStatusBar(statusBar);

        retranslateUi(FiveOfRulerClass);

        QMetaObject::connectSlotsByName(FiveOfRulerClass);
    } // setupUi

    void retranslateUi(QMainWindow *FiveOfRulerClass)
    {
        FiveOfRulerClass->setWindowTitle(QApplication::translate("FiveOfRulerClass", "FiveOfRuler", 0));
    } // retranslateUi

};

namespace Ui {
    class FiveOfRulerClass: public Ui_FiveOfRulerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIVEOFRULER_H
