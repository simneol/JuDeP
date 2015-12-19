#include "WindowManager.h"

LoginWindow *WindowManager::loginWindow;
UserWindow *WindowManager::userWindow;
TechnicianWindow *WindowManager::technicianWindow;

WindowManager::WindowManager(){qDebug("WindowManager()");}

WindowManager::~WindowManager(){qDebug("~WindowManager()");}
// ���� ���� ����, â�� ���� �Լ�
void WindowManager::slotOpenWindow(QString windowName,Info* info)
{
	if(windowName.compare("LoginWindow")==0)
	{
		// â ��ü�� ������ �������� �ʵ��� ����
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

// â ��ü�� ��ȯ�ϴ� �Լ�
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

// â ��ü�� �ݴ� �Լ�
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