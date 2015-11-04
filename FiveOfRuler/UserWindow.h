#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QtWidgets/QMainWindow>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

#include <QtSql/QSqlDataBase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

#include "ui_fiveofruler.h"

class UserWindow : public QMainWindow
{
	Q_OBJECT

public:
	UserWindow(QWidget *parent = 0);
	~UserWindow();

private:
	Ui::FiveOfRulerClass ui;

	QSqlDatabase db;

	QPushButton *loginButton;
	QLabel *idLabel,*pwLabel;
	QLineEdit *idLineEdit,*pwLineEdit;

	QTextEdit *te;

signals:
	private slots:
};

#endif // USERWINDOW_H
