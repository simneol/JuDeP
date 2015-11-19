#include "LoginWindow.h"
#include "UserWindow.h"
#include "WindowManager.h"

#include <QtCore/QDebug>


UserWindow::UserWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.action_Logout,SIGNAL(triggered()),this,SLOT(logout()));
}

UserWindow::~UserWindow(){qDebug("~UserWindow()");}

void UserWindow::logout()
{
	WindowManager::openWindow("LoginWindow");
	WindowManager::closeWindow("UserWindow");
}