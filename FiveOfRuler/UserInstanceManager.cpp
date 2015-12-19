#include "UserInstanceManager.h"

#pragma region Interface

// 유저의 값을 반환하는 메서드이다.
Info* UserInstanceManager::setInfo(Info* info)
{
	this->info = info;

	return this->info;
}

// 유저의 정보를 반환하는 메서드이다.
Info* UserInstanceManager::getInfo()
{
	return this->info;
}

#pragma endregion