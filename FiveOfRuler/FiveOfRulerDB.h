/********************************
* FiveOfRulerDB 클래스
*  - 기능 : DB에 직접 접근하여 다른 클래스에서 원하는 자료를 얻어서 전달해주는 클래스
*  - 작성자 : 정민혁
*********************************/
#ifndef FIVEOFRULER_H
#define FIVEOFRULER_H

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

	/********************************
	* checkValid 함수
	* - 기능 : 받은 문자열에 SQL Injection의 여지가 있는 문자열이 있나
	*			유효성을 검사하여 검사결과를 true/false로 반환한다.
	* - 작성자 : 정민혁
	*********************************/
	static bool checkValid(QString id);
public:
	/********************************
	* FiveOfRuler 생성자 함수
	* - 기능 : DB의 연결정보를 초기화하는 생성자
	* - 작성자 : 정민혁
	*********************************/
	FiveOfRulerDB();

	/********************************
	* FiveOfRuler 소멸자 함수
	* - 기능 : 클래스의 소멸 여부를 Debug창에 출력
	* - 작성자 : 정민혁
	*********************************/
	~FiveOfRulerDB();

	/********************************
	* open 함수
	* - 기능 : 생성자에서 기입된 DB연결 정보를 토대로 DB에 연결을 시도하는 클래스
	*			연결 실패시 false 반환
	* - 작성자 : 정민혁
	*********************************/
	bool open();

	/********************************
	* select 함수
	* - 기능 : 인자값을 기반으로 DB에 select 쿼리문을 실행한다.
	*			실행 결과 나온 쿼리를 반환한다.
	* - 작성자 : 정민혁
	*********************************/
	static QSqlQuery* select(QString table,QString column,QString record);
	static QSqlQuery* insert(QString table,QVector<QPair<QString,QString> > data);
	static QSqlQuery* update(QString table,QVector<QPair<QString,QString> > data);
};
#endif