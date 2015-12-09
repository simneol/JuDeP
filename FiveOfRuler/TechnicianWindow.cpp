#include "TechnicianWindow.h"
#include "WindowManager.h"

#include <QtCore/QDebug>

TechnicianWindow::TechnicianWindow(QWidget *parent)
	: QMainWindow(parent)
{		
	ui.setupUi(this);
	connect(ui.action_Logout,SIGNAL(triggered()),this,SLOT(slotLogout()));
}

TechnicianWindow::~TechnicianWindow(){qDebug("~TechnicianWindow()");}

void TechnicianWindow::slotLogout()
{
	WindowManager::slotOpenWindow("LoginWindow");
	WindowManager::slotCloseWindow("TechnicianWindow");
}