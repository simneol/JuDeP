#ifndef FIVEOFRULER_H
#define FIVEOFRULER_H
/* DB에 직접 접근하여 다른 클래스에서 원하는 자료를 얻어서 전달해주는 클래스 (Controller) */
#include <QtCore/QVector>
#include <QtCore/QPair>

#include <QtSql/QSqlDataBase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QtCore/QDebug>

class FiveOfRulerDB
{
private:
	/* 프로그램 최초 실행시, DB와 연결 후에 클래스마다 재 연결할 필요가 없도록*/
	/* 전역으로 사용하기 위해 멤버 변수 및 함수들을 static으로 선언 */
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