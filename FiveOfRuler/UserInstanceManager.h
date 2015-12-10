#ifndef USERINSTANCEMANAGER_H
#define USERINSTANCEMANAGER_H

#include "Info.h"
#include "TemplateSingleton.h"
#include <QtCore/QObject>

class UserInstanceManager :
	public TemplateSingleton<UserInstanceManager>
{
public:
	Info* setInfo(Info* info);
	Info* getInfo();
	UserInstanceManager() { }
	virtual ~UserInstanceManager() {}
private:
	
	Info* info;
};

#define InstanceOfUserManager UserInstanceManager::getInstance()

#endif