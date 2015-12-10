#include "QNAWriteDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

QNAWriteDialog::QNAWriteDialog(QWidget *parent,User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user=user;
<<<<<<< HEAD
	connect(ui.sendconfirm, SIGNAL(clicked()), this, SLOT(write()));	// È®ÀÎÇÏ°í
	connect(ui.sendconfirm, SIGNAL(clicked()), this, SLOT(closeQNA()));	// ²ö´Ù¾ç

	connect(ui.sendcansel, SIGNAL(clicked()), this, SLOT(closeQNA()));	// ²ö´Ù¾ç
=======
	connect(ui.sendcansel,SIGNAL(accepted()),this,SLOT(slotWrite()));
>>>>>>> e29bd90e46d2066a7cbe797db1c35e67b25ac23e
}

QNAWriteDialog::~QNAWriteDialog(){qDebug("~QNAWriteDialog()");}

void QNAWriteDialog::slotWrite()
{
	QVector<QPair<QString,QString> > data;
	data.push_back(qMakePair<QString,QString>("writer",user->getId()));
	data.push_back(qMakePair<QString,QString>("title",ui.head->text()));
	data.push_back(qMakePair<QString,QString>("content",ui.content->toPlainText()));

	QSqlQuery *query=FiveOfRulerDB::insert("qna",data);
	QMessageBox msgbox;
	msgbox.setText("Success !");
	msgbox.exec();
	this->close();
}

void QNAWriteDialog::closeQNA()
{
	this->close();
}