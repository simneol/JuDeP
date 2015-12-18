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
	/* SQL Injection ¿¹¹æÀ» À§ÇØ, id À¯È¿¼º °Ë»ç */
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

QSqlQuery* FiveOfRulerDB::insert(QString table,QVector<QPair<QString,QString> > data)
{
	QString totalStmt="INSERT INTO "+table+"_table (";
	for(int i=0;i<data.length();i++)
	{
		totalStmt+=data[i].first;
		if(i<data.length()-1)
			totalStmt+=", ";
	}
	totalStmt+=") VALUES (\'";
	for(int i=0;i<data.length();i++)
	{
		totalStmt+=data[i].second;
		if(i<data.length()-1)
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

QSqlQuery* FiveOfRulerDB::update(QString table,QVector<QPair<QString,QString> >data)
{
	for(int i=0;i<data.size();i++)
		if(!checkValid(data[i].first) || !checkValid(data[i].second))
			return NULL;
	QString totalStmt="UPDATE "+table+"_table SET ";
	for(int i=1;i<data.length();i++)
	{
		totalStmt+=data[i].first;
		totalStmt+=" = ";
		totalStmt+="\'"+data[i].second+"\'";
		if(i<data.length()-1)
			totalStmt+=", ";
	}
	totalStmt+=" WHERE ";
	totalStmt+=data[0].first;
	totalStmt+=" = ";
	totalStmt+="\'"+data[1].second+"\'";
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