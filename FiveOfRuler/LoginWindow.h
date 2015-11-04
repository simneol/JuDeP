#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QtWidgets/QMainWindow>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

#include <QtSql/QSqlDataBase>

#include "ui_fiveofruler.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT
public:
	LoginWindow(QWidget *parent = 0);
	~LoginWindow();

private:
	/* 기타 요소 */
	Ui::FiveOfRulerClass ui;	// ???
	QSqlDatabase db;			// DB 연동

	/* GUI 요소 */
	QPushButton *loginButton;	// 로그인 버튼
	QLabel *idLabel,*pwLabel;	// ID, PW 안내글자
	QLineEdit *idLineEdit,*pwLineEdit;	// ID, PW 입력창

	/* 멤버 함수 */
	bool checkValid(QString id);
signals:
	void loginSuccess();

	private slots:
		void login();
		void createUserWindow();
};
#endif // LOGINWINDOW_H
