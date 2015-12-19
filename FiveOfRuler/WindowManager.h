#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H
/* 각 Window들의 객체를 갖고, window를 열고 닫을 수 있도록 하는 클래스 */
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
	static void slotOpenWindow(QString windowName,Info* info=NULL);
	static void slotCloseWindow(QString windowName);
	static QMainWindow* getWindow(QString windowName);
signals:
	private slots:
};
#endif