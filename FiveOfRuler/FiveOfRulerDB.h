#ifndef FIVEOFRULER_H
#define FIVEOFRULER_H
/* DB�� ���� �����Ͽ� �ٸ� Ŭ�������� ���ϴ� �ڷḦ �� �������ִ� Ŭ���� (Controller) */
#include <QtCore/QVector>
#include <QtCore/QPair>

#include <QtSql/QSqlDataBase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QtCore/QDebug>

class FiveOfRulerDB
{
private:
	/* ���α׷� ���� �����, DB�� ���� �Ŀ� Ŭ�������� �� ������ �ʿ䰡 ������*/
	/* �������� ����ϱ� ���� ��� ���� �� �Լ����� static���� ���� */
	static QSqlDatabase db;
	static QSqlQuery *query;

	static bool checkValid(QString id);
public:
	FiveOfRulerDB();
	~FiveOfRulerDB();
	bool open();
	static QSqlQuery* select(QString table,QString column,QString record);
	static QSqlQuery* insert(QString table,QVector<QPair<QString,QString> > data);
	static QSqlQuery* update(QString table,QVector<QPair<QString,QString> > data);
};
#endif