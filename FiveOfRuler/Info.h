#ifndef INFO_H
#define INFO_H
// user와 technician의 공통정보를 담고 있는 클래스
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