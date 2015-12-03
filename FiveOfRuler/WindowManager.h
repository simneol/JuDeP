#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "LoginWindow.h"
#include "UserWindow.h"
#include "TechnicianWindow.h"

#include <QtCore/QObject>
#include <QtWidgets/QMainWindow>

class WindowManager : public QObject
{
	Q_OBJECT
private:
	static LoginWindow *loginWindow;
	static UserWindow *userWindow;
	static TechnicianWindow *technicianWindow;
public:
	WindowManager();
	~WindowManager();
	static void openWindow(QString windowName,Info* info=NULL);
	static void closeWindow(QString windowName);
signals:
	private slots:
};
#endif