#ifndef TECH_USER_H
#define TECH_USER_H

#include "Info.h"

class TechUser : public Info
{
private:
	bool isSenior;
public:
	TechUser()
	{
		isSenior = false;
	}
	virtual ~TechUser(){}
	void setType(bool isSenior) {this->isSenior = isSenior;}
	bool getType() { return isSenior; }
};
#endif