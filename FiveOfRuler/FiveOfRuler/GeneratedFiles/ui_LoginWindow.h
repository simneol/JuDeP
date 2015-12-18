/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QAction *action_Quit;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout;
    QRadioButton *userRadioButton;
    QRadioButton *technicianRadioButton;
    QGridLayout *midLayout;
    QPushButton *registerButton;
    QPushButton *loginButton;
    QLabel *pwLabel;
    QLineEdit *pwLineEdit;
    QLineEdit *idLineEdit;
    QLabel *idLabel;
    QHBoxLayout *botlayout;
    QPushButton *forgotIdPwButton;
    QMenuBar *menubar;
    QMenu *menu_Menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(394, 252);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginWindow->sizePolicy().hasHeightForWidth());
        LoginWindow->setSizePolicy(sizePolicy);
        LoginWindow->setWindowOpacity(1);
        action_Quit = new QAction(LoginWindow);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(16, 16, 361, 171));
        mainLayout = new QVBoxLayout(verticalLayoutWidget);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        topLayout = new QHBoxLayout();
        topLayout->setObjectName(QStringLiteral("topLayout"));
        userRadioButton = new QRadioButton(verticalLayoutWidget);
        userRadioButton->setObjectName(QStringLiteral("userRadioButton"));
        userRadioButton->setChecked(true);

        topLayout->addWidget(userRadioButton);

        technicianRadioButton = new QRadioButton(verticalLayoutWidget);
        technicianRadioButton->setObjectName(QStringLiteral("technicianRadioButton"));

        topLayout->addWidget(technicianRadioButton);


        mainLayout->addLayout(topLayout);

        midLayout = new QGridLayout();
        midLayout->setObjectName(QStringLiteral("midLayout"));
        registerButton = new QPushButton(verticalLayoutWidget);
        registerButton->setObjectName(QStringLiteral("registerButton"));

        midLayout->addWidget(registerButton, 1, 2, 1, 1);

        loginButton = new QPushButton(verticalLayoutWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        midLayout->addWidget(loginButton, 0, 2, 1, 1);

        pwLabel = new QLabel(verticalLayoutWidget);
        pwLabel->setObjectName(QStringLiteral("pwLabel"));
        QFont font;
        font.setPointSize(11);
        pwLabel->setFont(font);

        midLayout->addWidget(pwLabel, 1, 0, 1, 1);

        pwLineEdit = new QLineEdit(verticalLayoutWidget);
        pwLineEdit->setObjectName(QStringLiteral("pwLineEdit"));
        pwLineEdit->setFont(font);
        pwLineEdit->setEchoMode(QLineEdit::Password);

        midLayout->addWidget(pwLineEdit, 1, 1, 1, 1);

        idLineEdit = new QLineEdit(verticalLayoutWidget);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));
        idLineEdit->setFont(font);

        midLayout->addWidget(idLineEdit, 0, 1, 1, 1);

        idLabel = new QLabel(verticalLayoutWidget);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        idLabel->setFont(font);

        midLayout->addWidget(idLabel, 0, 0, 1, 1);


        mainLayout->addLayout(midLayout);

        botlayout = new QHBoxLayout();
        botlayout->setObjectName(QStringLiteral("botlayout"));
        forgotIdPwButton = new QPushButton(verticalLayoutWidget);
        forgotIdPwButton->setObjectName(QStringLiteral("forgotIdPwButton"));

        botlayout->addWidget(forgotIdPwButton);


        mainLayout->addLayout(botlayout);

        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 394, 21));
        menu_Menu = new QMenu(menubar);
        menu_Menu->setObjectName(QStringLiteral("menu_Menu"));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        LoginWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(idLineEdit, pwLineEdit);
        QWidget::setTabOrder(pwLineEdit, loginButton);
        QWidget::setTabOrder(loginButton, registerButton);
        QWidget::setTabOrder(registerButton, userRadioButton);
        QWidget::setTabOrder(userRadioButton, technicianRadioButton);
        QWidget::setTabOrder(technicianRadioButton, forgotIdPwButton);

        menubar->addAction(menu_Menu->menuAction());
        menu_Menu->addAction(action_Quit);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "FiveOfRuler", 0));
        action_Quit->setText(QApplication::translate("LoginWindow", "&Quit", 0));
        userRadioButton->setText(QApplication::translate("LoginWindow", "User", 0));
        technicianRadioButton->setText(QApplication::translate("LoginWindow", "Technician", 0));
        registerButton->setText(QApplication::translate("LoginWindow", "Register", 0));
        loginButton->setText(QApplication::translate("LoginWindow", "Login", 0));
        pwLabel->setText(QApplication::translate("LoginWindow", " Your PW ", 0));
        idLabel->setText(QApplication::translate("LoginWindow", " Your ID ", 0));
        forgotIdPwButton->setText(QApplication::translate("LoginWindow", "Forgot ID/PW", 0));
        menu_Menu->setTitle(QApplication::translate("LoginWindow", "&Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
