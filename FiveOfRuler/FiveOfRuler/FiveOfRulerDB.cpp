#include "FiveOfRulerDB.h"
#include "DatabaseInfo.h"

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
	qDebug().noquote()<<"SELECT * from "+table+"_table where "+column+"=\'"+record+"\'";
	query->prepare("SELECT * from "+table+"_table where "+column+"=\'"+record+"\'");
	if(!query->exec())
	{
		qDebug() << query->lastError();
		return NULL;
	}
	query->next();
	return query;
}

QSqlQuery* FiveOfRulerDB::insert(QString table,QVector<QString> column,QVector<QString> record)
{
	if(column.length()!=record.length())
	{
		qDebug()<<"column cannot match valid record !";
		return NULL;
	}
	QString totalStmt="INSERT INTO "+table+"_table (";
	for(int i=0;i<column.length();i++)
	{
		totalStmt+=column[i];
		if(i<column.length()-1)
			totalStmt+=", ";
	}
	totalStmt+=") VALUES (\'";
	for(int i=0;i<record.length();i++)
	{
		totalStmt+=record[i];
		if(i<record.length()-1)
			totalStmt+="\', \'";
	}
	totalStmt+="\')";
	qDebug().noquote()<<totalStmt;
	query->prepare(totalStmt);
	if(!query->exec())
	{
		qDebug() << query->lastError();
		return NULL;
	}
	query->next();
	return query;
}

QSqlQuery* FiveOfRulerDB::update(QString table,QVector<QString> column,QVector<QString> record,QString primaryKey,QString conditionKey)
{
	//record2개이상이면 애러
	if(column.length()!=record.length())
	{
		qDebug()<<"column cannot match valid record !";
		return NULL;
	}
	for(int i=0;i<record.size();i++)
		if(!checkValid(record[i]))
			return NULL;
	QString totalStmt="UPDATE "+table+"_table SET ";
	for(int i=0;i<column.length();i++)
	{
		totalStmt+=column[i];
		totalStmt+=" = ";
		totalStmt+="\'"+record[i]+"\'";
		if(i<column.length()-1)
			totalStmt+=", ";
	}
	totalStmt+=" WHERE ";
	totalStmt+=primaryKey;
	totalStmt+=" = ";
	totalStmt+="\'"+conditionKey+"\'";
	qDebug().noquote()<<totalStmt;
	query->prepare(totalStmt);
	if(!query->exec())
	{
		qDebug() << query->lastError();
		return NULL;
	}
	query->next();
	return query;
}