#include "WindowManager.h"

LoginWindow *WindowManager::loginWindow;
UserWindow *WindowManager::userWindow;
TechnicianWindow *WindowManager::technicianWindow;

WindowManager::WindowManager(){qDebug("WindowManager()");}

WindowManager::~WindowManager(){qDebug("~WindowManager()");}

void WindowManager::openWindow(QString windowName)
{
	if(windowName.compare("LoginWindow")==0&&loginWindow==NULL)
	{
		loginWindow=new LoginWindow;
		loginWindow->show();
	}
	else if(windowName.compare("UserWindow")==0&&userWindow==NULL)
	{
		userWindow=new UserWindow;
		userWindow->show();
	}
	else if(windowName.compare("TechnicianWindow")==0&&technicianWindow==NULL)
	{
		technicianWindow=new TechnicianWindow;
		technicianWindow->show();
	}
}

void WindowManager::closeWindow(QString windowName)
{
	if(windowName.compare("LoginWindow")==0&&loginWindow!=NULL)
		delete loginWindow;
	else if(windowName.compare("UserWindow")==0&&userWindow!=NULL)
		delete userWindow;
	else if(windowName.compare("TechnicianWindow")==0&&technicianWindow!=NULL)
		delete technicianWindow;
}