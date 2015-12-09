#include "UserWindow.h"
#include "WindowManager.h"

#include <QtCore/QDebug>


UserWindow::UserWindow(QWidget *parent,Info* userInfo)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	userManager=new UserManager(userInfo);
	connect(ui.action_Logout,SIGNAL(triggered()),userManager,SLOT(logout()));
	connect(ui.btn_Logout,SIGNAL(clicked()),userManager,SLOT(logout()));
	connect(ui.btn_QnA,SIGNAL(clicked()),userManager,SLOT(openQNAWriteDialog()));
}

UserWindow::~UserWindow(){qDebug("~UserWindow()");}