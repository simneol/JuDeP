#include "UserManager.h"
#include "FiveOfRulerDB.h"
#include "WindowManager.h"

#include <QtCore/QDebug>

// ���ֿ� 2014112022
// �뵵 : �����Ŵ����� �⺻���� ó���� ���ִ� �������̴�.
UserManager::UserManager(Info* userInfo)
{
	user=(User*)userInfo;
	qnaWriteDialog=NULL;
	qnaSeeDialog = NULL;
}

// �뵵 : ���� �Ŵ����� ���� �����ϰ� ���� �� ������ ó���� �ϴ� �Ҹ����̴�.
UserManager::~UserManager(){qDebug("~UserManager");}

// �뵵 : �ڽ��� ���� ��ȯ�ϴ� �������� �޼����̴�.
User* UserManager::getUser(){return user;}

// �뵵 : �α׾ƿ��� ȭ���� �����ִ� �޼����̴�.
void UserManager::logout()
{
	WindowManager::slotOpenWindow("LoginWindow");
	WindowManager::slotCloseWindow("UserWindow");
}

// �뵵 : Qna�� ���⸦ �ϴ� â�� �ҷ��ִ� �޼����̴�.
void UserManager::openQNAWriteDialog()
{
	qnaWriteDialog=new QNAWriteDialog(0,user);
	qnaWriteDialog->show();
}

// �뵵 : Qna�� ���� �о���̴� â�� �ҷ��ִ� �޼����̴�.
void UserManager::openQNASeeDialog()
{
	qnaSeeDialog = new QlistWindow(0, user);
	qnaSeeDialog->show();
}

// �뵵 : ������ ����� ���� â�� �ҷ��ִ� �޼����̴�.
void UserManager::openRequestDialog()
{
	requestDialog = new RequestProduct(0, user);
	requestDialog->show();
}

// �뵵 : ������ ����� �ϴ� â�� �ҷ��ִ� �޼ҵ��̴�.
void UserManager::openRequestShowDialog()
{
	reauestShowDialog = new RequestShow(0, user);
	reauestShowDialog->show();
}

// �뵵 : �޽����� ó���ϴ� â�� �ҷ��ִ� �޼ҵ��̴�.
void UserManager::openMessageDialog()
{
	message = new Message(0, user);
	message->show();
}

// �뵵 : ������ ������ϴ� â�� �ҷ��ִ� �޼����̴�.
void UserManager::openRegisterProductInformation()
{
	registerProduc = new RegisterProductInformation(0, user);
	registerProduc->show();
}

UserWindow::~UserWindow(){ qDebug("~UserWindow()"); }