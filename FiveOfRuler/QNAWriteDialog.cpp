#include "QNAWriteDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

QNAWriteDialog::QNAWriteDialog(QWidget *parent,User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user=user;

	connect(ui.sendconfirm, SIGNAL(clicked()), this, SLOT(write()));	// 확인하고
	connect(ui.sendconfirm, SIGNAL(clicked()), this, SLOT(closeQNA()));	// 끈다양
	connect(ui.sendcansel, SIGNAL(clicked()), this, SLOT(closeQNA()));	// 끈다양
}

QNAWriteDialog::~QNAWriteDialog(){qDebug("~QNAWriteDialog()");}

void QNAWriteDialog::write()
{
	QVector<QString> column,record;
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
		column.push_back("writer");
		column.push_back("title");
		column.push_back("content");

		record.push_back(user->getId());
		record.push_back(ui.head->text());
		record.push_back(ui.content->toPlainText());

		QSqlQuery *query = FiveOfRulerDB::insert("qna", column, record);

		msgbox.setText("Success !");
		msgbox.exec();
		this->close();
	}
}

void QNAWriteDialog::closeQNA()
{
	this->close();

	delete this;
}
