/***************************************
/ �ۼ��� : �ڼ���
/ Ŭ���� : UserInstanceManager
/ ��  �� : Application���� ����ϴ� User������ ����ִ� �����̳� Ŭ����
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
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : setInfo
	/ ��  �� : Application���� ����� User������ Set�Ѵ�.
	/***************************************/
	Info* setInfo(Info* info);

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : getInfo
	/ ��  �� : Application���� ����� User������ Get�Ѵ�.
	/***************************************/
	Info* getInfo();

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : ������
	/ ��  �� : ��ü�� �����Ѵ�.
	/***************************************/
	UserInstanceManager() { }

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : �Ҹ���
	/ ��  �� : ��ü�� �����Ѵ�.
	/***************************************/
	virtual ~UserInstanceManager() {}
private:
	
	Info* info;
};

// UserInstanceManagerŬ������ ������ ��ü�� �޾ƿ��� ���� �Լ�ȣ���� ����ؼ� ����ϱ� ���� ����
#define InstanceOfUserManager UserInstanceManager::getInstance()

#endif