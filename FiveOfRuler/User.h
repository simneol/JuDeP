#ifndef USER_H
#define USER_H

#include "Info.h"
using namespace std;

// 사용자의 간단한 내용을 계산하는 클래스이다.
class User : public Info
{
private:

public:
	User() {}
	virtual ~User() {}
};
#endif