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
	/* ��Ÿ ��� */
	Ui::FiveOfRulerClass ui;	// ???
	QSqlDatabase db;			// DB ����

	/* GUI ��� */
	QPushButton *loginButton;	// �α��� ��ư
	QLabel *idLabel,*pwLabel;	// ID, PW �ȳ�����
	QLineEdit *idLineEdit,*pwLineEdit;	// ID, PW �Է�â

	/* ��� �Լ� */
	bool checkValid(QString id);
signals:
	void loginSuccess();

	private slots:
		void login();
		void createUserWindow();
};
#endif // LOGINWINDOW_H
