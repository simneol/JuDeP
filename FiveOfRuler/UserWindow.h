#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QtWidgets/QMainWindow>

#include "ui_UserWindow.h"

class UserWindow : public QMainWindow
{
	Q_OBJECT

public:
	UserWindow(QWidget *parent = 0);
	~UserWindow();

private:
	Ui::UserWindow ui;

signals:
	private slots:
		void logout();
};

#endif // USERWINDOW_H
