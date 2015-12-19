/***************************************
/ 작성자 : 박성수
/ 클래스 : UserInstanceManager
/ 용  도 : Application에서 사용하는 User정보를 담고있는 컨테이너 클래스
/***************************************/
#include "UserInstanceManager.h"

#pragma region Interface

Info* UserInstanceManager::setInfo(Info* info)
{
	this->info = info;

	return this->info;
}
Info* UserInstanceManager::getInfo()
{
	return this->info;
}

#pragma endregion