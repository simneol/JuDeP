#include "RegisterDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

RegisterDialog::RegisterDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	is_idDuplicated=true;

	connect(ui.registerButton,SIGNAL(clicked()),this,SLOT(slotSignup()));
	connect(ui.idDuplicationCheck,SIGNAL(clicked()),this,SLOT(slotCheckIdDuplication()));
}

RegisterDialog::~RegisterDialog(){qDebug("~RegisterDialog()");}

void RegisterDialog::slotSignup()
{
	if(is_idDuplicated)
	{
		QMessageBox msgbox;
		msgbox.setText("Please check duplication !");
		msgbox.exec();
		return;
	}
	QVector<QPair<QString,QString> > data;
	data.push_back(qMakePair<QString,QString>("id",ui.idLineEdit->text()));
	data.push_back(qMakePair<QString,QString>("pw",ui.pwLineEdit->text()));
	data.push_back(qMakePair<QString,QString>("email",ui.emailLineEdit->text()));
	data.push_back(qMakePair<QString,QString>("question",QString::number((ui.questionComboBox->currentIndex()))));
	data.push_back(qMakePair<QString,QString>("answer",ui.answerLineEdit->text()));

	QMessageBox msgBox;
	if(FiveOfRulerDB::insert("user",data)!=NULL)
		msgBox.setText(" Registration Complete ! ");
	else
		msgBox.setText(" Registration Fail ! ");
	msgBox.exec();
	this->close();
}

void RegisterDialog::slotCheckIdDuplication()
{
	QSqlQuery *query=FiveOfRulerDB::select("user","id",ui.idLineEdit->text());
	if(query->value(0).toString().compare(ui.idLineEdit->text())!=0)
		is_idDuplicated=false;
	else
		is_idDuplicated=true;
}