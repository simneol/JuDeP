/***************************************
/ 작성자 : 박성수
/ 클래스 : TechUser
/ 용  도 : TechUser는 user와는 다르게 등급이 있음 
/***************************************/
#ifndef TECH_USER_H
#define TECH_USER_H

#include "Info.h"

class TechUser : public Info
{
private:
	bool isSenior;
public:
	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 생성자
	/ 용  도 : 객체를 생성한다.
	/***************************************/
	TechUser()
	{
		isSenior = false;
	}
	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 소멸자
	/ 용  도 : 객체를 제거한다.
	/***************************************/
	virtual ~TechUser(){}

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : setType
	/ 용  도 : 계급을 set하는 setter
	/***************************************/
	void setType(bool isSenior) {this->isSenior = isSenior;}

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : getType
	/ 용  도 : 계급을 반환하는 getter
	/***************************************/
	bool getType() { return isSenior; }
};
#endif