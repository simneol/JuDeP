#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QtWidgets/QMainWindow>

#include "LoginManager.h"
#include "ui_LoginWindow.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT
public:
	LoginWindow(QWidget *parent = 0);
	~LoginWindow();

private:
	Ui::LoginWindow ui;	// UIÆÄÀÏ
	LoginManager loginManager;

signals:
	void slotLoginSignal(QString id, QString pw, bool isUser);
	private slots:
		void slotEmitLoginSignal();
};
#endif // LOGINWINDOW_H
