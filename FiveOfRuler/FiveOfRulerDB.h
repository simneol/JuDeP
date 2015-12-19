/********************************
* FiveOfRulerDB Ŭ����
*  - ��� : DB�� ���� �����Ͽ� �ٸ� Ŭ�������� ���ϴ� �ڷḦ �� �������ִ� Ŭ����
*  - �ۼ��� : ������
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
	/* ���α׷� ���� �����, DB�� ���� �Ŀ� Ŭ�������� �� ������ �ʿ䰡 ������*/
	/* �������� ����ϱ� ���� ��� ���� �� �Լ����� static���� ���� */
	static QSqlDatabase db;
	static QSqlQuery *query;

	/********************************
	* checkValid �Լ�
	* - ��� : ���� ���ڿ��� SQL Injection�� ������ �ִ� ���ڿ��� �ֳ�
	*			��ȿ���� �˻��Ͽ� �˻����� true/false�� ��ȯ�Ѵ�.
	* - �ۼ��� : ������
	*********************************/
	static bool checkValid(QString id);
public:
	/********************************
	* FiveOfRuler ������ �Լ�
	* - ��� : DB�� ���������� �ʱ�ȭ�ϴ� ������
	* - �ۼ��� : ������
	*********************************/
	FiveOfRulerDB();

	/********************************
	* FiveOfRuler �Ҹ��� �Լ�
	* - ��� : Ŭ������ �Ҹ� ���θ� Debugâ�� ���
	* - �ۼ��� : ������
	*********************************/
	~FiveOfRulerDB();

	/********************************
	* open �Լ�
	* - ��� : �����ڿ��� ���Ե� DB���� ������ ���� DB�� ������ �õ��ϴ� Ŭ����
	*			���� ���н� false ��ȯ
	* - �ۼ��� : ������
	*********************************/
	bool open();

	/********************************
	* select �Լ�
	* - ��� : ���ڰ��� ������� DB�� select �������� �����Ѵ�.
	*			���� ��� ���� ������ ��ȯ�Ѵ�.
	* - �ۼ��� : ������
	*********************************/
	static QSqlQuery* select(QString table,QString column,QString record);
	static QSqlQuery* insert(QString table,QVector<QPair<QString,QString> > data);
	static QSqlQuery* update(QString table,QVector<QPair<QString,QString> > data);
};
#endif