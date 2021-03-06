#include "QNAWriteDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

// 문주원 2014112022
// 용도 : Qna의 기본적인 정보들과 시그널에대한 처리를하는 생성자이다.
QNAWriteDialog::QNAWriteDialog(QWidget *parent,User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user=user;

	connect(ui.sendconfirm, SIGNAL(clicked()), this, SLOT(write()));	// 확인하고
	connect(ui.sendconfirm, SIGNAL(clicked()), this, SLOT(closeQNA()));	// 끈다양
	connect(ui.sendcansel, SIGNAL(clicked()), this, SLOT(closeQNA()));	// 끈다양
}

// 용도 : 이 객체를 종료하는 소멸자이다.
QNAWriteDialog::~QNAWriteDialog(){qDebug("~QNAWriteDialog()");}

void QNAWriteDialog::write()
{
	QMessageBox msgbox;

	// 제목이나 내용중 하나를 빠뜨리고 썼을때 실행
	if (ui.head->text() == NULL || ui.content->toPlainText() == NULL)
	{
		msgbox.setText("Error:\n Please write title and contents !");
		msgbox.exec();
		this->close();
	}
	// 모든 빈 칸을 채웠을 때 실행
	else
	{
		QVector<QPair<QString,QString> > data;
		data.push_back(qMakePair<QString,QString>("writer",user->getId()));
		data.push_back(qMakePair<QString,QString>("title",ui.head->text()));
		data.push_back(qMakePair<QString,QString>("content",ui.content->toPlainText()));

		QSqlQuery *query = FiveOfRulerDB::insert("qna", data);

		msgbox.setText("Success !");
		msgbox.exec();
		this->close();
	}
}

// 용도 : Qna의 창을 닫기위한 메서드이다.
void QNAWriteDialog::closeQNA()
{
	this->close();

	delete this;
}
