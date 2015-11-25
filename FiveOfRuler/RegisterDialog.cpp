#include "RegisterDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

RegisterDialog::RegisterDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.registerButton,SIGNAL(clicked()),this,SLOT(signup()));
}

RegisterDialog::~RegisterDialog(){qDebug("~RegisterDialog()");}

void RegisterDialog::signup()
{
	QVector<QString> column;
	column.push_back("id");
	column.push_back("pw");
	column.push_back("email");
	column.push_back("question");
	column.push_back("answer");

	QVector<QString> record;
	record.push_back(ui.idLineEdit->text());
	record.push_back(ui.pwLineEdit->text());
	record.push_back(ui.emailLineEdit->text());
	record.push_back(QString::number((ui.questionComboBox->currentIndex())));
	record.push_back(ui.answerLineEdit->text());

	QMessageBox msgBox;
	if(FiveOfRulerDB::insert("user",column,record)!=NULL)
		msgBox.setText(" Registration Complete ! ");
	else
		msgBox.setText(" Registration Fail ! ");
	msgBox.exec();
	this->close();
}