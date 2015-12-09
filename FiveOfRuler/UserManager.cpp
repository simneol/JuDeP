#include "UserManager.h"
#include "WindowManager.h"

#include <QtCore/QDebug>
UserManager::UserManager(Info* userInfo)
{
	user=(User*)userInfo;
	qnaWriteDialog=NULL;
}
UserManager::~UserManager(){qDebug("~UserManager");}

User* UserManager::getUser(){return user;}

void UserManager::slotLogout()
{
	WindowManager::slotOpenWindow("LoginWindow");
	WindowManager::slotCloseWindow("UserWindow");
}

void UserManager::slotOpenQNAWriteDialog()
{
	if(qnaWriteDialog==NULL)
		qnaWriteDialog=new QNAWriteDialog(0,user);
	qnaWriteDialog->show();
}