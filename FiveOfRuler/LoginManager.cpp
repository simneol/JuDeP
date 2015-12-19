#include "LoginManager.h"
#include "WindowManager.h"
#include "FiveOfRulerDB.h"
#include "QuestionReplyDialog.h"
#include "UserInstanceManager.h"
#include "TechUser.h"

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
		Info* info;
		qDebug("password correct");
		if(isUser)
		{
			info = new User();
			User* user = (User *)info;
			user->setId(id);
			InstanceOfUserManager.setInfo(info);

			WindowManager::slotOpenWindow("UserWindow",info);
		}
		// Technician User
		else if(isUser == false)
		{
			info = new TechUser();
			TechUser* user = (TechUser *)info;
			user->setId(id);
			user->setType(query->value(8).toBool());
			InstanceOfUserManager.setInfo(info);

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