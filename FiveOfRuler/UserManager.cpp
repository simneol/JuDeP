#include "UserManager.h"
#include "WindowManager.h"

#include <QtCore/QDebug>
UserManager::UserManager(Info* userInfo)
{
	user=(User*)userInfo;
	qnaWriteDialog=NULL;
	qnaSeeDialog = NULL;
}
UserManager::~UserManager(){qDebug("~UserManager");}

User* UserManager::getUser(){return user;}

void UserManager::logout()
{
	WindowManager::openWindow("LoginWindow");
	WindowManager::closeWindow("UserWindow");
}

void UserManager::openQNAWriteDialog()
{
	if(qnaWriteDialog==NULL)
		qnaWriteDialog=new QNAWriteDialog(0,user);
	qnaWriteDialog->show();
}

void UserManager::openQNASeeDialog()
{
	qnaSeeDialog = new QlistWindow(0, user);
	qnaSeeDialog->show();
}