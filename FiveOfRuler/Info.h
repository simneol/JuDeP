/********************************
* Info 클래스
*  - 기능 : user와 technician이 공통적으로 갖고있는 정보를 담는 클래스
*  - 작성자 : 정민혁
*********************************/
#ifndef INFO_H
#define INFO_H

#include <QtCore/QString>
using namespace std;
class Info
{
private:
	QString id;
public:
	Info(){}
	virtual ~Info(){}
	void setId(QString id){this->id=id;}
	QString getId(){return id;}
};

#endif