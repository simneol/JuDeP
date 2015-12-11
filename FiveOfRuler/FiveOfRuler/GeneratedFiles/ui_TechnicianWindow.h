/********************************************************************************
** Form generated from reading UI file 'TechnicianWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TECHNICIANWINDOW_H
#define UI_TECHNICIANWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TechnicianWindow
{
public:
    QAction *action_Logout;
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *RegiterProduct;
    QPushButton *RepairStatusrenew;
    QPushButton *message;
    QPushButton *productSearch;
    QPushButton *QnA;
    QPushButton *logout;
    QPushButton *Withdrawal;
    QPushButton *compoSearch;
    QMenuBar *menubar;
    QMenu *menu_Menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TechnicianWindow)
    {
        if (TechnicianWindow->objectName().isEmpty())
            TechnicianWindow->setObjectName(QStringLiteral("TechnicianWindow"));
        TechnicianWindow->resize(357, 389);
        action_Logout = new QAction(TechnicianWindow);
        action_Logout->setObjectName(QStringLiteral("action_Logout"));
        centralwidget = new QWidget(TechnicianWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 30, 111, 21));
        RegiterProduct = new QPushButton(centralwidget);
        RegiterProduct->setObjectName(QStringLiteral("RegiterProduct"));
        RegiterProduct->setGeometry(QRect(30, 170, 91, 23));
        RepairStatusrenew = new QPushButton(centralwidget);
        RepairStatusrenew->setObjectName(QStringLiteral("RepairStatusrenew"));
        RepairStatusrenew->setGeometry(QRect(30, 230, 151, 23));
        message = new QPushButton(centralwidget);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(30, 110, 91, 23));
        productSearch = new QPushButton(centralwidget);
        productSearch->setObjectName(QStringLiteral("productSearch"));
        productSearch->setGeometry(QRect(30, 200, 151, 23));
        QnA = new QPushButton(centralwidget);
        QnA->setObjectName(QStringLiteral("QnA"));
        QnA->setGeometry(QRect(30, 140, 91, 23));
        logout = new QPushButton(centralwidget);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(30, 290, 91, 23));
        Withdrawal = new QPushButton(centralwidget);
        Withdrawal->setObjectName(QStringLiteral("Withdrawal"));
        Withdrawal->setGeometry(QRect(30, 320, 91, 23));
        compoSearch = new QPushButton(centralwidget);
        compoSearch->setObjectName(QStringLiteral("compoSearch"));
        compoSearch->setGeometry(QRect(30, 260, 151, 23));
        TechnicianWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TechnicianWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 357, 21));
        menu_Menu = new QMenu(menubar);
        menu_Menu->setObjectName(QStringLiteral("menu_Menu"));
        TechnicianWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TechnicianWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TechnicianWindow->setStatusBar(statusbar);

        menubar->addAction(menu_Menu->menuAction());
        menu_Menu->addAction(action_Logout);

        retranslateUi(TechnicianWindow);

        QMetaObject::connectSlotsByName(TechnicianWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TechnicianWindow)
    {
        TechnicianWindow->setWindowTitle(QApplication::translate("TechnicianWindow", "MainWindow", 0));
        action_Logout->setText(QApplication::translate("TechnicianWindow", "&Logout", 0));
        label->setText(QApplication::translate("TechnicianWindow", "Technician", 0));
        RegiterProduct->setText(QApplication::translate("TechnicianWindow", "RegiterProduct", 0));
        RepairStatusrenew->setText(QApplication::translate("TechnicianWindow", "RepairStatus Renew", 0));
        message->setText(QApplication::translate("TechnicianWindow", "Message", 0));
        productSearch->setText(QApplication::translate("TechnicianWindow", "Product Search", 0));
        QnA->setText(QApplication::translate("TechnicianWindow", "QnA", 0));
        logout->setText(QApplication::translate("TechnicianWindow", "Logout", 0));
        Withdrawal->setText(QApplication::translate("TechnicianWindow", "Withdrawal", 0));
        compoSearch->setText(QApplication::translate("TechnicianWindow", "Component Search", 0));
        menu_Menu->setTitle(QApplication::translate("TechnicianWindow", "&Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class TechnicianWindow: public Ui_TechnicianWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TECHNICIANWINDOW_H
