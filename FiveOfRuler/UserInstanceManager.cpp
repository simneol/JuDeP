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