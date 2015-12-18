#ifndef FIVEOFRULER_H
#define FIVEOFRULER_H

#include <QtCore/QVector>

#include <QtSql/QSqlDataBase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QtCore/QDebug>

class FiveOfRulerDB
{
private:
	static QSqlDatabase db;
	static QSqlQuery *query;

	static bool checkValid(QString id);
public:
	FiveOfRulerDB();
	~FiveOfRulerDB();
	bool open();
	static QSqlQuery* select(QString table,QString column,QString record);
	static QSqlQuery* insert(QString table,QVector<QString> column,QVector<QString> record);
	static QSqlQuery* update(QString table,QVector<QString> column,QVector<QString> record,QString primaryKey,QString conditionKey);
};
#endif