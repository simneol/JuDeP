#include "QNAWriteDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

QNAWriteDialog::QNAWriteDialog(QWidget *parent,User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user=user;
	connect(ui.btn_sendcansel,SIGNAL(accepted()),this,SLOT(slotWrite()));
}

QNAWriteDialog::~QNAWriteDialog(){qDebug("~QNAWriteDialog()");}

void QNAWriteDialog::slotWrite()
{
	QVector<QPair<QString,QString> > data;
	data.push_back(qMakePair<QString,QString>("writer",user->getId()));
	data.push_back(qMakePair<QString,QString>("title",ui.textEdit_title->text()));
	data.push_back(qMakePair<QString,QString>("content",ui.textEdit_Write->toPlainText()));

	QSqlQuery *query=FiveOfRulerDB::insert("qna",data);
	QMessageBox msgbox;
	msgbox.setText("Success !");
	msgbox.exec();
	this->close();
}