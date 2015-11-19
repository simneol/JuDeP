#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QtWidgets/QMainWindow>

#include "ui_LoginWindow.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT
public:
	LoginWindow(QWidget *parent = 0);
	~LoginWindow();

private:
	Ui::LoginWindow ui;	// UIÆÄÀÏ

signals:
	private slots:
		void login();
		void createRegisterDialog();
		void createForgotIdPwDialog();
};
#endif // LOGINWINDOW_H
