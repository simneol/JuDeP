#include "ForgotIdPwDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>

#include <QtWidgets/QMessageBox>

ForgotIdPwDialog::ForgotIdPwDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	slotIdshow();
	connect(ui.radio_Id,SIGNAL(clicked()),this,SLOT(slotIdshow()));
	connect(ui.radio_Pw,SIGNAL(clicked()),this,SLOT(slotPwshow()));
	connect(ui.btn_Find,SIGNAL(clicked()),this,SLOT(slotFind()));
}

ForgotIdPwDialog::~ForgotIdPwDialog(){qDebug("~ForgotIdPwDialog()");}

void ForgotIdPwDialog::slotFind()
{
	QMessageBox msgbox;
	QSqlQuery *query;

	if(ui.btn_User->isChecked())
	{
		query=FiveOfRulerDB::select("user","email",ui.lineEdit_Email->text());
	}
	else
	{
		query=FiveOfRulerDB::select("technician","email",ui.lineEdit_Email->text());
	}

	if(ui.radio_Id->isChecked())
	{
		if(query->isValid())
			msgbox.setText("Your ID : "+query->value(0).toString());
		else
			msgbox.setText("Cannot find your ID!");
	}
	else
	{
		if(query->isValid())
			msgbox.setText("Your PW : "+query->value(1).toString());
		else
			msgbox.setText("Cannot find your PW!");
	}
	msgbox.exec();
	this->close();

}
void ForgotIdPwDialog::slotIdshow()
{
	ui.label_Question->hide();
	ui.lineEdit_Question->hide();
}
void ForgotIdPwDialog::slotPwshow()
{
	ui.label_Question->show();
	ui.lineEdit_Question->show();
}