#include "UserInstanceManager.h"

#pragma region Interface

// ������ ���� ��ȯ�ϴ� �޼����̴�.
Info* UserInstanceManager::setInfo(Info* info)
{
	this->info = info;

	return this->info;
}

// ������ ������ ��ȯ�ϴ� �޼����̴�.
Info* UserInstanceManager::getInfo()
{
	return this->info;
}

#pragma endregion