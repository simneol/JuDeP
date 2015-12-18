#include "TechQNASelectDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

TechQNASelectDialog::TechQNASelectDialog(QWidget *parent, User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;
}

TechQNASelectDialog::~TechQNASelectDialog(){ qDebug("~QNASeeDialog()"); }

void TechQNASelectDialog::write()
{
	QString column, record;

	//QSqlQuery *query = FiveOfRulerDB::select("qna", column, record);
}

void TechQNASelectDialog::closeQNA()
{
	this->close();
}