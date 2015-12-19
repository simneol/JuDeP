/********************************
* FiveOfRulerDB 클래스
*  - 기능 : DB에 직접 접근하여 다른 클래스에서 원하는 자료를 얻어서 전달해주는 클래스
*  - 작성자 : 정민혁
*********************************/
#include "FiveOfRulerDB.h"
#include "DatabaseInfo.h"

/* Static 변수 선언 */
QSqlDatabase FiveOfRulerDB::db;
QSqlQuery *FiveOfRulerDB::query;

// DB 정보 설정
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

// DB연결. 성공 시 true 반환
bool FiveOfRulerDB::open()
{
	qDebug("Try DB Open");
	db.open();
	if(!db.isOpen())
		return false;
	query=new QSqlQuery(db);
	return true;
}

// 받은 문자열에 대해 유효성 검사 (SQL Injection 대비)
bool FiveOfRulerDB::checkValid(QString str)
{
	/* SQL Query문에 주로 사용되는 문자열을 포함할 수 없도록 함 */
	if(str.contains("'")||str.contains("--")||str.contains("/")||str.contains(";")||str.contains("*"))
	{
		qDebug("String includes something wrong character!");
		return false;
	}
	return true;
}

// SQL의 select문을 대신하여 결과 Query를 반환해주는 함수
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

// SQL의 insert문을 대신하여 결과 Query를 반환해주는 함수
// 삽입할 데이터는 column과 record를 pair한 변수들의 vector로 받는다.
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
	// INSERT INTO TABLE_table ( COLUMN1, COLUMN2, COLUMN3 ) VALUES ('
	for(int i=0;i<data.length();i++)
	{
		totalStmt+=data[i].second;
		if(i<data.length()-1)
			totalStmt+="\', \'";
	}
	totalStmt+="\')";
	// INSERT INTO TABLE_table ( COLUMN1, COLUMN2, COLUMN3 ) VALUES ('RECORD1', 'RECORD2', 'RECORD3')
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

// SQL의 update문을 대신하여 결과 Query를 반환해주는 함수
// 갱신할 데이터는 column과 record를 pair한 변수들의 vector로 받는다.
// 이 때, 첫번째 pair는 갱신할 레코드에 대한 검색 정보이다(column, record)
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
	// UPDATE TABLE_table SET COLUMN1 = 'RECORD1', COLUMN2 = 'RECORD2'
	totalStmt+=" WHERE ";
	totalStmt+=data[0].first;
	totalStmt+=" = ";
	totalStmt+="\'"+data[0].second+"\'";
	// UPDATE TABLE_table SET COLUMN2 = 'RECORD2', COLUMN3 = 'RECORD3' WHERE COLUMN1 = 'RECORD1'
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