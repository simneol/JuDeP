#ifndef FIVEOFRULER_H
#define FIVEOFRULER_H

#include <QtCore/QVector>

#include <QtSql/QSqlDataBase>
#include <QtSql/QSqlQuery>

#include <QtCore/QDebug>

class FiveOfRulerDB
{
private:
	static QSqlDatabase db;
	static QSqlQuery *query;

	bool checkValid(QString id);
public:
	FiveOfRulerDB();
	~FiveOfRulerDB();
	bool open();
	static QSqlQuery* select(QString table,QString column,QString record);
	static QSqlQuery* insert(QString table,QVector<QString> column,QVector<QString> record);
};
#endif