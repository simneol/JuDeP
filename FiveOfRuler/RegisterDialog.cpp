#include "RegisterDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

RegisterDialog::RegisterDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.registerButton,SIGNAL(clicked()),this,SLOT(slotSignup()));
	connect(ui.idDuplicationCheck,SIGNAL(clicked()),this,SLOT(slotCheckIdDuplication()));

	connect(ui.idLineEdit,SIGNAL(textChanged(QString)),this,SLOT(slotInitDuplication()));
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
	QMessageBox msgBox;
	QSqlQuery *query=FiveOfRulerDB::select("user","id",ui.idLineEdit->text());
	if(!query->isValid())
		query=FiveOfRulerDB::select("technician","id",ui.idLineEdit->text());
	if(query->isValid())
	{
		msgBox.setText("This ID is already exist !! \n Please use another ID !");
		is_idDuplicated=true;
	}
	else
	{
		msgBox.setText("This ID can be used !");
		is_idDuplicated=false;
	}
	msgBox.exec();
}

void RegisterDialog::slotInitDuplication()
{
	is_idDuplicated=true;
}