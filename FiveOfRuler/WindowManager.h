#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "LoginWindow.h"
#include "UserWindow.h"
#include "TechnicianWindow.h"

#include <QtWidgets/QMainWindow>

class WindowManager
{
private:
	static LoginWindow *loginWindow;
	static UserWindow *userWindow;
	static TechnicianWindow *technicianWindow;
public:
	WindowManager();
	~WindowManager();
	static void openWindow(QString windowName);
	static void closeWindow(QString windowName);
};
#endif