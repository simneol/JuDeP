#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QtWidgets/QMainWindow>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

#include <QtSql/QSqlDataBase>

#include "ui_fiveofruler.h"

class UserWindow : public QMainWindow
{
	Q_OBJECT

public:
	UserWindow(QMainWindow* prevWindow=NULL,QWidget *parent = 0);
	~UserWindow();

private:
	Ui::FiveOfRulerClass ui;

	QSqlDatabase db;

	QPushButton *loginButton;
	QLabel *idLabel,*pwLabel;
	QLineEdit *idLineEdit,*pwLineEdit;

signals:
	private slots:
};

#endif // USERWINDOW_H
