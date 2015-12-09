#include "QNAWriteDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

QNAWriteDialog::QNAWriteDialog(QWidget *parent,User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user=user;
	connect(ui.sendcansel,SIGNAL(accepted()),this,SLOT(slotWrite()));
}

QNAWriteDialog::~QNAWriteDialog(){qDebug("~QNAWriteDialog()");}

void QNAWriteDialog::slotWrite()
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