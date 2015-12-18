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
	connect(ui.RegiterProduct, SIGNAL(clicked()), userManager, SLOT(openRequestProduct()));
	connect(ui.SeeQnA, SIGNAL(clicked()), userManager, SLOT(openQNASeeDialog()));

	connect(ui.RequestRepair, SIGNAL(clicked()), userManager, SLOT(openRequestShow()));
}

UserWindow::~UserWindow(){qDebug("~UserWindow()");}