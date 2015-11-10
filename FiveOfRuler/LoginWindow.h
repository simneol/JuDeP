#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QtWidgets/QMainWindow>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

#include <QtSql/QSqlDataBase>

#include "ui_LoginWindow.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT
public:
	LoginWindow(QWidget *parent = 0);
	~LoginWindow();

private:
	/* ��Ÿ ��� */
	Ui::LoginWindow ui;	// UI����
	QSqlDatabase db;	// DB ����

	/* ��� �Լ� */
	bool checkValid(QString id);
signals:
	void loginSuccess();

	private slots:
		void login();
		void createUserWindow();
};
#endif // LOGINWINDOW_H
