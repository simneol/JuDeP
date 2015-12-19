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
	// Qt Desinger�� ������ Ui���� �����ϴ� �Լ�
	ui.setupUi(this);

	/* �� ui��ҵ��� SLOT�Լ���� ���� */
	connect(ui.btn_Login,SIGNAL(clicked()),this,SLOT(slotLogin()));

	/* ����(����)Ű ���� �� �α��� */ 
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
	// user table���� �켱 id�� ����
	query=FiveOfRulerDB::select("user","id", ui.lineEdit_Id->text());
	// ������ ��ȿ���� �������, technician table���� ����
	if(!query->isValid())
	{
		query=FiveOfRulerDB::select("technician","id",ui.lineEdit_Id->text());
		isUser=false;
	}

	// ��й�ȣ�� ��ġ�ؾ��ϸ�, ������ �� ��й�ȣ�� ���̰� 1 �̻��̾�� ���
	if(query != NULL 
		&& query->value(1).toString() == ui.lineEdit_Pw->text()
		&& ui.lineEdit_Pw->text().length() > 0)
	{
		qDebug("password correct");
		if(isUser)
		{
			// ������ ������� ����(id)�� ���� ���� â�� ����
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

/* ���ڰ��� ���� �˸��� â ����, �� ���� 1���� â�� �������� */
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