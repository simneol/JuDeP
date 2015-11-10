#include "LoginWindow.h"
#include "TechnicianWindow.h"

#include <QtCore/QDebug>

#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QMessageBox>

TechnicianWindow::TechnicianWindow(QMainWindow* prevWindow,QWidget *parent)
	: QMainWindow(parent)
{		
	if(prevWindow!=NULL)
		prevWindow->close();
	ui.setupUi(this);
	connect(ui.action_Logout,SIGNAL(triggered()),this,SLOT(logout()));
}

TechnicianWindow::~TechnicianWindow(){qDebug("~TechnicianWindow()");}

void TechnicianWindow::logout()
{
	LoginWindow *loginWindow=new LoginWindow(this);
	loginWindow->show();
}