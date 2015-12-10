#include "LoginManager.h"
#include "WindowManager.h"
#include "FiveOfRulerDB.h"
#include "QuestionReplyDialog.h"
#include "UserInstanceManager.h"

#include <QtSql/QSqlQuery>
#include <QtWidgets/QMessageBox>

LoginManager::LoginManager()
{
	registerDialog=NULL;
	forgotIdPwDialog=NULL;
}

LoginManager::~LoginManager(){}

void LoginManager::slotLogin(QString id, QString pw, bool isUser)
{
	QSqlQuery *query;
	if(isUser)
		query=FiveOfRulerDB::select("user","id", id);
	else
		query=FiveOfRulerDB::select("technician","id",id);

	if(query != NULL 
		&& query->value(1).toString() == pw
		&& pw.length() > 0)
	{
		qDebug("password correct");
		if(isUser)
		{
			User *user=new User();
			user->setId(id);
			InstanceOfUserManager.setInfo(user);

			WindowManager::slotOpenWindow("UserWindow",(Info*)user);
		}
		// Technician User
		else if(isUser == false)
		{

			WindowManager::slotOpenWindow("TechnicianWindow");
		}
		WindowManager::slotCloseWindow("LoginWindow");
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText(" Please Check Your ID/PW ");
		msgBox.exec();
	}
}
void LoginManager::slotOpenRegisterDialog()
{
	if(registerDialog==NULL)
	{
		registerDialog=new RegisterDialog;
		registerDialog->show();
	}
	else
		registerDialog->hasFocus();
}
void LoginManager::slotOpenForgotIdPwDialog()
{
	if(forgotIdPwDialog==NULL)
	{
		forgotIdPwDialog=new ForgotIdPwDialog;
		forgotIdPwDialog->show();
	}
	else
		forgotIdPwDialog->setFocus();
}