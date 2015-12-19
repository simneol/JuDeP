#include "LoginWindow.h"
#include "FiveOfRulerDB.h"
#include "User.h"
#include "TechUser.h"
#include "UserInstanceManager.h"
#include "WindowManager.h"

#include "RegisterDialog.h"
#include "ForgotIdPwDialog.h"

#include <QtCore/QDebug>

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	// Qt Desinger로 구성한 Ui들을 구성하는 함수
	ui.setupUi(this);

	/* 각 ui요소들을 SLOT함수들과 연결 */
	connect(ui.btn_Login,SIGNAL(clicked()),this,SLOT(slotLogin()));

	/* 리턴(엔터)키 누를 시 로그인 */ 
	connect(ui.lineEdit_Pw,SIGNAL(returnPressed()),this,SLOT(slotLogin()));
	connect(ui.lineEdit_Id,SIGNAL(returnPressed()),this,SLOT(slotLogin()));

	connect(ui.btn_Register,SIGNAL(clicked()),this,SLOT(slotOpenRegisterDialog()));
	connect(ui.btn_ForgotIdPw,SIGNAL(clicked()),this,SLOT(slotOpenForgotIdPwDialog()));

	connect(ui.action_Quit,SIGNAL(triggered()),this,SLOT(close()));
}

LoginWindow::~LoginWindow(){qDebug("~LoginWindow()");}

void LoginWindow::slotLogin(void)
{
	QSqlQuery *query;
	bool isUser=true;
	// user table에서 우선 id로 조사
	query=FiveOfRulerDB::select("user","id", ui.lineEdit_Id->text());
	// 쿼리가 유효하지 않을경우, technician table에서 조사
	if(!query->isValid())
	{
		query=FiveOfRulerDB::select("technician","id",ui.lineEdit_Id->text());
		isUser=false;
	}

	// 비밀번호가 일치해야하며, 유저가 쓴 비밀번호의 길이가 1 이상이어야 통과
	if(query != NULL 
		&& query->value(1).toString() == ui.lineEdit_Pw->text()
		&& ui.lineEdit_Pw->text().length() > 0)
	{
		qDebug("password correct");
		if(isUser)
		{
			// 접속한 사용자의 정보(id)를 새로 열릴 창에 전달
			User *user=new User();
			user->setId(ui.lineEdit_Id->text());
			InstanceOfUserManager.setInfo(user);

			WindowManager::slotOpenWindow("UserWindow",(Info*)user);
		}
		// Technician User
		else if(!isUser)
		{
			TechUser *user=new TechUser();
			user->setId(ui.lineEdit_Id->text());
			InstanceOfUserManager.setInfo(user);
			user->setType(query->value(8).toBool());

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

void LoginWindow::slotOpenRegisterDialog(void)
{
	OpenDialog("RegisterDialog");
}

void LoginWindow::slotOpenForgotIdPwDialog(void)
{
	OpenDialog("ForgotIdPwDialog");
}

/* 인자값에 따라 알맞은 창 열기, 한 번에 1개의 창만 열리도록 */
#pragma region DialogControl

void LoginWindow::OpenDialog(QString str)
{
	QDialog *target = NULL;
	target = dialogs.value(str);
	if(target == NULL)
	{
		qDebug("Open-New at LoginWindow");
		if(str == "RegisterDialog")
			target = new RegisterDialog();
		else if(str == "ForgotIdPwDialog")
			target = new ForgotIdPwDialog();
		dialogs.insert(str,target);
		target->show();
		target->hasFocus();
	}
	else
	{
		qDebug("Open-AlreadyHave at LoginWindow");
		target->show();
		target->hasFocus();
	}
}
#pragma endregion