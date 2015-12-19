/***************************************
/ 작성자 : 박성수
/ 클래스 : UserInstanceManager
/ 용  도 : Application에서 사용하는 User정보를 담고있는 컨테이너 클래스
/***************************************/
#ifndef USERINSTANCEMANAGER_H
#define USERINSTANCEMANAGER_H

#include "Info.h"
#include "TemplateSingleton.h"
#include <QtCore/QObject>

class UserInstanceManager :
	public TemplateSingleton<UserInstanceManager>
{
public:
	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : setInfo
	/ 용  도 : Application에서 사용할 User정보를 Set한다.
	/***************************************/
	Info* setInfo(Info* info);

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : getInfo
	/ 용  도 : Application에서 사용할 User정보를 Get한다.
	/***************************************/
	Info* getInfo();

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 생성자
	/ 용  도 : 객체를 생성한다.
	/***************************************/
	UserInstanceManager() { }

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 소멸자
	/ 용  도 : 객체를 제거한다.
	/***************************************/
	virtual ~UserInstanceManager() {}
private:
	
	Info* info;
};

// UserInstanceManager클래스의 유일한 객체를 받아오기 위한 함수호출을 축약해서 사용하기 위한 정의
#define InstanceOfUserManager UserInstanceManager::getInstance()

#endif