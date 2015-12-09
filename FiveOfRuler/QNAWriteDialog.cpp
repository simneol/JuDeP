#include "QNAWriteDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

QNAWriteDialog::QNAWriteDialog(QWidget *parent,User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user=user;
	connect(ui.sendconfirm, SIGNAL(clicked()), this, SLOT(write()));	// È®ÀÎÇÏ°í
	connect(ui.sendconfirm, SIGNAL(clicked()), this, SLOT(closeQNA()));	// ²ö´Ù¾ç

	connect(ui.sendcansel, SIGNAL(clicked()), this, SLOT(closeQNA()));	// ²ö´Ù¾ç
}

QNAWriteDialog::~QNAWriteDialog(){qDebug("~QNAWriteDialog()");}

void QNAWriteDialog::write()
{
	QVector<QString> column,record;
	column.push_back("writer");
	column.push_back("title");
	column.push_back("content");

	record.push_back(user->getId());
	record.push_back(ui.head->text());
	record.push_back(ui.content->toPlainText());
	
	QSqlQuery *query=FiveOfRulerDB::insert("qna",column,record);
	QMessageBox msgbox;
	msgbox.setText("Success !");
	msgbox.exec();
	this->close();
}

void QNAWriteDialog::closeQNA()
{
	this->close();
}