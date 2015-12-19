#include "QNASeeDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

// 문주원 2014112022
// 용도 : Qna를 보여주는 역할을하는 생성자이다.
QNASeeDialog::QNASeeDialog(QWidget *parent, User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;
}

// 용도 : Qna의 객체를 없애는 소멸자이다.
QNASeeDialog::~QNASeeDialog(){ qDebug("~QNASeeDialog()"); }

// 용도 : Qna의 정보를 쓰는 메서드이다.
void QNASeeDialog::write()
{
	QString column, record;

	//QSqlQuery *query = FiveOfRulerDB::select("qna", column, record);
}

// 용도 : Qna창을 닫는 메서드이다.
void QNASeeDialog::closeQNA()
{
	this->close();
}