#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtCore/QEvent>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

#include <QtSql/QSqlDataBase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

#include "ui_fiveofruler.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = 0);
	~LoginWindow();

private:
	Ui::FiveOfRulerClass ui;

	QSqlDatabase db;

	QPushButton *loginButton;
	QLabel *idLabel,*pwLabel;
	QLineEdit *idLineEdit,*pwLineEdit;

	QTextEdit *te;

	bool checkValid(QString id);
signals:
	void loginSuccess();
	private slots:
		void login();
};

class WaitWindow : public QMainWindow
{
	Q_OBJECT
public:
	WaitWindow(QWidget *parent = 0);
	~WaitWindow();
private:
	Ui::FiveOfRulerClass ui;
	QLabel *waitLabel;

};
#endif // LOGINWINDOW_H
