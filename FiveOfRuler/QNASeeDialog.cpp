#include "QNASeeDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

QNASeeDialog::QNASeeDialog(QWidget *parent, User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;
}

QNASeeDialog::~QNASeeDialog(){ qDebug("~QNASeeDialog()"); }

void QNASeeDialog::write()
{
	QString column, record;

	//QSqlQuery *query = FiveOfRulerDB::select("qna", column, record);
}

void QNASeeDialog::closeQNA()
{
	this->close();
}