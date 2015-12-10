#include "UserWindow.h"
#include "WindowManager.h"

#include <QtCore/QDebug>


UserWindow::UserWindow(QWidget *parent,Info* userInfo)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	userManager=new UserManager(userInfo);
	connect(ui.action_Logout,SIGNAL(triggered()),userManager,SLOT(logout()));
<<<<<<< HEAD
	connect(ui.logout,SIGNAL(clicked()),userManager,SLOT(logout()));
	connect(ui.QnA,SIGNAL(clicked()),userManager,SLOT(openQNAWriteDialog()));
	connect(ui.SeeQnA, SIGNAL(clicked()), userManager, SLOT(openQNASeeDialog()));
=======
	connect(ui.btn_Logout,SIGNAL(clicked()),userManager,SLOT(logout()));
	connect(ui.btn_QnA,SIGNAL(clicked()),userManager,SLOT(openQNAWriteDialog()));
>>>>>>> e29bd90e46d2066a7cbe797db1c35e67b25ac23e
}

UserWindow::~UserWindow(){qDebug("~UserWindow()");}