#include "TechnicianWindow.h"
#include "WindowManager.h"

#include <QtCore/QDebug>

TechnicianWindow::TechnicianWindow(QWidget *parent)
	: QMainWindow(parent)
{		
	ui.setupUi(this);
	connect(ui.action_Logout,SIGNAL(triggered()),this,SLOT(logout()));
}

TechnicianWindow::~TechnicianWindow(){qDebug("~TechnicianWindow()");}

void TechnicianWindow::logout()
{
	WindowManager::openWindow("LoginWindow");
	WindowManager::closeWindow("TechnicianWindow");
}