#include "FiveOfRulerDB.h"
#include "DatabaseInfo.h"

#include <QtSql/QSqlError>

QSqlDatabase FiveOfRulerDB::db;
QSqlQuery *FiveOfRulerDB::query;

FiveOfRulerDB::FiveOfRulerDB()
{
	db=QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(DB_HOSTNAME);
	db.setPort(DB_PORT);
	db.setDatabaseName(DB_DATABASENAME);
	db.setUserName(DB_USERNAME);
	db.setPassword(DB_PASSWORD);
}

FiveOfRulerDB::~FiveOfRulerDB(){qDebug("~FiveOfRulerDB");}

bool FiveOfRulerDB::open()
{
	qDebug("Try DB Open");
	db.open();
	if(!db.isOpen())
		return false;
	query=new QSqlQuery(db);
	return true;
}

bool FiveOfRulerDB::checkValid(QString str)
{
	/* SQL Injection 예방을 위해, id 유효성 검사 */
	if(str.contains("'")||str.contains("--")||str.contains("/")||str.contains(";")||str.contains("*"))
	{
		qDebug("String includes something wrong character!");
		return false;
	}
	return true;
}

QSqlQuery* FiveOfRulerDB::select(QString table,QString column,QString record)
{
	qDebug().noquote()<<"SELECT * from "+table+"_table where id=\'"+record+"\'";
	query->prepare("SELECT * from "+table+"_table where id=\'"+record+"\'");
	if(!query->exec())
	{
		qDebug() << query->lastError();
		return NULL;
	}
	query->next();
	return query;
}