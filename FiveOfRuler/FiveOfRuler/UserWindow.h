#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QtWidgets/QMainWindow>

#include "User.h"
#include "UserManager.h"
#include "ui_UserWindow.h"

class UserWindow : public QMainWindow
{
	Q_OBJECT

public:
	UserWindow(QWidget *parent = 0,Info* userInfo=NULL);
	~UserWindow();

private:
	Ui::UserWindow ui;
	UserManager *userManager;

signals:
	private slots:
};

#endif // USERWINDOW_H
