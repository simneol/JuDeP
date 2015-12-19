#include "UserManager.h"
#include "FiveOfRulerDB.h"
#include "WindowManager.h"

#include <QtCore/QDebug>

// 유저매니저의 기본적인 처리를 해주는 생성자이다.
UserManager::UserManager(Info* userInfo)
{
	user=(User*)userInfo;
	qnaWriteDialog=NULL;
	qnaSeeDialog = NULL;
}

// 유저 매니저의 값을 해제하고 끝날 때 적절한 처리를 하는 소멸자이다.
UserManager::~UserManager(){qDebug("~UserManager");}

// 자신의 값을 반환하는 포인터형 메서드이다.
User* UserManager::getUser(){return user;}

// 로그아웃의 화면을 보여주는 메서드이다.
void UserManager::logout()
{
	WindowManager::slotOpenWindow("LoginWindow");
	WindowManager::slotCloseWindow("UserWindow");
}

// Qna의 쓰기를 하는 창을 불러주는 메서드이다.
void UserManager::openQNAWriteDialog()
{
	qnaWriteDialog=new QNAWriteDialog(0,user);
	qnaWriteDialog->show();
}

// Qna의 값을 읽어들이는 창을 불러주는 메서드이다.
void UserManager::openQNASeeDialog()
{
	qnaSeeDialog = new QlistWindow(0, user);
	qnaSeeDialog->show();
}

// 물건의 등록을 위한 창을 불러주는 메서드이다.
void UserManager::openRequestDialog()
{
	requestDialog = new RequestProduct(0, user);
	requestDialog->show();
}

// 물건의 등록을 하는 창을 불러주는 메소드이다.
void UserManager::openRequestShowDialog()
{
	reauestShowDialog = new RequestShow(0, user);
	reauestShowDialog->show();
}

// 메시지를 처리하는 창을 불러주는 메소드이다.
void UserManager::openMessageDialog()
{
	message = new Message(0, user);
	message->show();
}

// 물건의 등록을하는 창을 불러주는 메서드이다.
void UserManager::openRegisterProductInformation()
{
	registerProduc = new RegisterProductInformation(0, user);
	registerProduc->show();
}

UserWindow::~UserWindow(){ qDebug("~UserWindow()"); }