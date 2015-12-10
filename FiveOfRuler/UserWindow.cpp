#include "UserWindow.h"
#include "WindowManager.h"

#include <QtCore/QDebug>


UserWindow::UserWindow(QWidget *parent,Info* userInfo)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	userManager=new UserManager(userInfo);
	connect(ui.action_Logout,SIGNAL(triggered()),userManager,SLOT(logout()));
	connect(ui.logout,SIGNAL(clicked()),userManager,SLOT(logout()));
	connect(ui.QnA,SIGNAL(clicked()),userManager,SLOT(openQNAWriteDialog()));
	connect(ui.SeeQnA, SIGNAL(clicked()), userManager, SLOT(openQNASeeDialog()));
}

UserWindow::~UserWindow(){qDebug("~UserWindow()");}