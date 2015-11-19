#include "LoginWindow.h"
#include "WindowManager.h"

#include "RegisterDialog.h"
#include "ForgotIdPwDialog.h"

#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>

#include <QtWidgets/QMessageBox>

#include <QtSql/QSqlQuery>

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	// Qt Desinger로 구성한 Ui들을 구성하는 함수
	ui.setupUi(this);

	connect(ui.loginButton,SIGNAL(clicked()),this,SLOT(login()));	// 로그인 버튼 누르면, login() 실행
	connect(ui.registerButton,SIGNAL(clicked()),this,SLOT(createRegisterDialog()));
	connect(ui.forgotIdPwButton,SIGNAL(clicked()),this,SLOT(createForgotIdPwDialog()));

	connect(ui.action_Quit,SIGNAL(triggered()),this,SLOT(close()));
}

LoginWindow::~LoginWindow(){qDebug("~LoginWindow()");}

void LoginWindow::login()
{
	QSqlQuery *query;
	if(ui.userRadioButton->isChecked())
		query=FiveOfRulerDB::select("user","id",ui.idLineEdit->text());
	else
		query=FiveOfRulerDB::select("technician","id",ui.idLineEdit->text());

	if(query->value(2).toString()==ui.pwLineEdit->text()&&ui.pwLineEdit->text().length()>0)
	{
		qDebug("password correct");
		if(ui.userRadioButton->isChecked())
			WindowManager::openWindow("UserWindow");
		else
			WindowManager::openWindow("TechnicianWindow");
		WindowManager::closeWindow("LoginWindow");
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText(" Please Check Your ID/PW ");
		msgBox.exec();
	}
}

void LoginWindow::createRegisterDialog()
{
	RegisterDialog *registerDialog=new RegisterDialog;
	registerDialog->show();
}

void LoginWindow::createForgotIdPwDialog()
{
	ForgotIdPwDialog *forgotIdPwDialog=new ForgotIdPwDialog;
	forgotIdPwDialog->show();
}