#include "LoginManager.h"
#include "WindowManager.h"
#include "FiveOfRulerDB.h"

#include <QtSql/QSqlQuery>
#include <QtWidgets/QMessageBox>

LoginManager::LoginManager()
{
	registerDialog=NULL;
	forgotIdPwDialog=NULL;
}

LoginManager::~LoginManager(){}

void LoginManager::login(QString id, QString pw, bool isUser)
{
	QSqlQuery *query;
	if(isUser)
		query=FiveOfRulerDB::select("user","id",id);
	else
		query=FiveOfRulerDB::select("technician","id",id);

	if(query->value(2).toString()==pw&&pw.length()>0)
	{
		qDebug("password correct");
		if(isUser)
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
void LoginManager::openRegisterDialog()
{
	if(registerDialog==NULL)
	{
		registerDialog=new RegisterDialog;
		registerDialog->show();
	}
	else
		registerDialog->hasFocus();
}
void LoginManager::openForgotIdPwDialog()
{
	if(forgotIdPwDialog==NULL)
	{
		forgotIdPwDialog=new ForgotIdPwDialog;
		forgotIdPwDialog->show();
	}
	else
		forgotIdPwDialog->setFocus();
}