#include "WindowManager.h"

LoginWindow *WindowManager::loginWindow;
UserWindow *WindowManager::userWindow;
TechnicianWindow *WindowManager::technicianWindow;

WindowManager::WindowManager(){qDebug("WindowManager()");}

WindowManager::~WindowManager(){qDebug("~WindowManager()");}

void WindowManager::slotOpenWindow(QString windowName,Info* info)
{
	if(windowName.compare("LoginWindow")==0)
	{
		if(loginWindow==NULL)
			loginWindow=new LoginWindow();
		loginWindow->show();
	}
	else if(windowName.compare("UserWindow")==0)
	{
		if(userWindow==NULL)
			userWindow=new UserWindow(0,info);
		userWindow->show();
	}
	else if(windowName.compare("TechnicianWindow")==0)
	{
		if(technicianWindow==NULL)
			technicianWindow=new TechnicianWindow();
		technicianWindow->show();
	}
}

void WindowManager::slotCloseWindow(QString windowName)
{
	if(windowName.compare("LoginWindow")==0)
	{
		loginWindow->close();
	}
	else if(windowName.compare("UserWindow")==0)
	{
		userWindow->close();
	}
	else if(windowName.compare("TechnicianWindow")==0)
	{
		technicianWindow->close();
	}
}