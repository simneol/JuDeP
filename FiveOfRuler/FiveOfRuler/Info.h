#ifndef INFO_H
#define INFO_H
#include <QtCore/QString>
using namespace std;
class Info
{
private:
	QString id;
public:
	void setId(QString id){this->id=id;}
	QString getId(){return id;}
};
#endif