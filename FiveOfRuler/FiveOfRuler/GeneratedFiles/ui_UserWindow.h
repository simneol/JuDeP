/********************************************************************************
** Form generated from reading UI file 'UserWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

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

class Ui_UserWindow
{
public:
    QAction *action_Logout;
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *RegiterProduct;
    QPushButton *RepairStatus;
    QPushButton *message;
    QPushButton *RequestRepair;
    QPushButton *QnA;
    QPushButton *logout;
    QPushButton *Withdrawal;
    QMenuBar *menubar;
    QMenu *menu_Menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QStringLiteral("UserWindow"));
        UserWindow->resize(357, 389);
        action_Logout = new QAction(UserWindow);
        action_Logout->setObjectName(QStringLiteral("action_Logout"));
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 30, 111, 21));
        RegiterProduct = new QPushButton(centralwidget);
        RegiterProduct->setObjectName(QStringLiteral("RegiterProduct"));
        RegiterProduct->setGeometry(QRect(30, 170, 91, 23));
        RepairStatus = new QPushButton(centralwidget);
        RepairStatus->setObjectName(QStringLiteral("RepairStatus"));
        RepairStatus->setGeometry(QRect(30, 230, 91, 23));
        message = new QPushButton(centralwidget);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(30, 110, 91, 23));
        RequestRepair = new QPushButton(centralwidget);
        RequestRepair->setObjectName(QStringLiteral("RequestRepair"));
        RequestRepair->setGeometry(QRect(30, 200, 91, 23));
        QnA = new QPushButton(centralwidget);
        QnA->setObjectName(QStringLiteral("QnA"));
        QnA->setGeometry(QRect(30, 140, 91, 23));
        logout = new QPushButton(centralwidget);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(30, 260, 91, 23));
        Withdrawal = new QPushButton(centralwidget);
        Withdrawal->setObjectName(QStringLiteral("Withdrawal"));
        Withdrawal->setGeometry(QRect(30, 290, 91, 23));
        UserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 357, 21));
        menu_Menu = new QMenu(menubar);
        menu_Menu->setObjectName(QStringLiteral("menu_Menu"));
        UserWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(UserWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UserWindow->setStatusBar(statusbar);

        menubar->addAction(menu_Menu->menuAction());
        menu_Menu->addAction(action_Logout);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QApplication::translate("UserWindow", "MainWindow", 0));
        action_Logout->setText(QApplication::translate("UserWindow", "&Logout", 0));
        label->setText(QApplication::translate("UserWindow", "User", 0));
        RegiterProduct->setText(QApplication::translate("UserWindow", "RegiterProduct", 0));
        RepairStatus->setText(QApplication::translate("UserWindow", "RepairStatus", 0));
        message->setText(QApplication::translate("UserWindow", "Message", 0));
        RequestRepair->setText(QApplication::translate("UserWindow", "RequestRepair", 0));
        QnA->setText(QApplication::translate("UserWindow", "QnA", 0));
        logout->setText(QApplication::translate("UserWindow", "Logout", 0));
        Withdrawal->setText(QApplication::translate("UserWindow", "Withdrawal", 0));
        menu_Menu->setTitle(QApplication::translate("UserWindow", "&Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
