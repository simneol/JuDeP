#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "LoginWindow.h"
#include "UserWindow.h"
#include "TechnicianWindow.h"
#include "QNAWriteDialog.h"

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
	static void slotOpenWindow(QString windowName,Info* info=NULL);
	static void slotCloseWindow(QString windowName);
signals:
	private slots:
};
#endif