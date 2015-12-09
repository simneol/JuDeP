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