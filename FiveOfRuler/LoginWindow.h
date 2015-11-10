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
	/* 기타 요소 */
	Ui::LoginWindow ui;	// UI파일
	QSqlDatabase db;	// DB 연동

	/* 멤버 함수 */
	bool checkValid(QString id);
signals:
	void loginSuccess();

	private slots:
		void login();
		void createUserWindow();
};
#endif // LOGINWINDOW_H
