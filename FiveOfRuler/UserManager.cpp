#include "UserManager.h"
#include "FiveOfRulerDB.h"
#include "WindowManager.h"

#include <QtCore/QDebug>

// �����Ŵ����� �⺻���� ó���� ���ִ� �������̴�.
UserManager::UserManager(Info* userInfo)
{
	user=(User*)userInfo;
	qnaWriteDialog=NULL;
	qnaSeeDialog = NULL;
}

// ���� �Ŵ����� ���� �����ϰ� ���� �� ������ ó���� �ϴ� �Ҹ����̴�.
UserManager::~UserManager(){qDebug("~UserManager");}

// �ڽ��� ���� ��ȯ�ϴ� �������� �޼����̴�.
User* UserManager::getUser(){return user;}

// �α׾ƿ��� ȭ���� �����ִ� �޼����̴�.
void UserManager::logout()
{
	WindowManager::slotOpenWindow("LoginWindow");
	WindowManager::slotCloseWindow("UserWindow");
}

// Qna�� ���⸦ �ϴ� â�� �ҷ��ִ� �޼����̴�.
void UserManager::openQNAWriteDialog()
{
	qnaWriteDialog=new QNAWriteDialog(0,user);
	qnaWriteDialog->show();
}

// Qna�� ���� �о���̴� â�� �ҷ��ִ� �޼����̴�.
void UserManager::openQNASeeDialog()
{
	qnaSeeDialog = new QlistWindow(0, user);
	qnaSeeDialog->show();
}

// ������ ����� ���� â�� �ҷ��ִ� �޼����̴�.
void UserManager::openRequestDialog()
{
	requestDialog = new RequestProduct(0, user);
	requestDialog->show();
}

// ������ ����� �ϴ� â�� �ҷ��ִ� �޼ҵ��̴�.
void UserManager::openRequestShowDialog()
{
	reauestShowDialog = new RequestShow(0, user);
	reauestShowDialog->show();
}

// �޽����� ó���ϴ� â�� �ҷ��ִ� �޼ҵ��̴�.
void UserManager::openMessageDialog()
{
	message = new Message(0, user);
	message->show();
}

// ������ ������ϴ� â�� �ҷ��ִ� �޼����̴�.
void UserManager::openRegisterProductInformation()
{
	registerProduc = new RegisterProductInformation(0, user);
	registerProduc->show();
}

UserWindow::~UserWindow(){ qDebug("~UserWindow()"); }