#ifndef INFO_H
#define INFO_H
// user�� technician�� ���������� ��� �ִ� Ŭ����
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