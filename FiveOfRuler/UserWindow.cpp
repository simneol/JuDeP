#include "LoginWindow.h"
#include "UserWindow.h"

#include <QtCore/QDebug>

#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QMessageBox>

UserWindow::UserWindow(QMainWindow* prevWindow,QWidget *parent)
	: QMainWindow(parent)
{
	if(prevWindow!=NULL)
		prevWindow->close();
	ui.setupUi(this);
	connect(ui.action_Logout,SIGNAL(triggered()),this,SLOT(logout()));
}

UserWindow::~UserWindow(){qDebug("~UserWindow()");}

void UserWindow::logout()
{
	LoginWindow *loginWindow=new LoginWindow(this);
	loginWindow->show();
}