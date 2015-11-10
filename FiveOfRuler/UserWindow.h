#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QtWidgets/QMainWindow>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

#include <QtSql/QSqlDataBase>

#include "ui_UserWindow.h"

class UserWindow : public QMainWindow
{
	Q_OBJECT

public:
	UserWindow(QMainWindow* prevWindow=NULL,QWidget *parent = 0);
	~UserWindow();

private:
	Ui::UserWindow ui;

	QSqlDatabase db;

signals:
	private slots:
		void logout();
};

#endif // USERWINDOW_H
