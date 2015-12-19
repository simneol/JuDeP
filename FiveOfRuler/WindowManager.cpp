#include "WindowManager.h"

LoginWindow *WindowManager::loginWindow;
UserWindow *WindowManager::userWindow;
TechnicianWindow *WindowManager::technicianWindow;

WindowManager::WindowManager(){qDebug("WindowManager()");}

WindowManager::~WindowManager(){qDebug("~WindowManager()");}
// 인자 값에 따라, 창을 여는 함수
void WindowManager::slotOpenWindow(QString windowName,Info* info)
{
	if(windowName.compare("LoginWindow")==0)
	{
		// 창 객체가 여러개 생성되지 않도록 방지
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

// 창 객체를 반환하는 함수
QMainWindow* WindowManager::getWindow(QString windowName)
{
	if(windowName.compare("LoginWindow")==0)
	{
		return loginWindow;
	}
	else if(windowName.compare("UserWindow")==0)
	{
		return userWindow;
	}
	else if(windowName.compare("TechnicianWindow")==0)
	{
		return technicianWindow;
	}
}

// 창 객체를 닫는 함수
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