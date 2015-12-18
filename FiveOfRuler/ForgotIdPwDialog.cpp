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

void ForgotIdPwDialog::find()
{
	if(ui.radio_Id->isChecked())
	{
		QSqlQuery *query;
		if(ui.btn_User->isChecked())
		{
			query=FiveOfRulerDB::select("user","email",ui.lineEdit_Email->text());
			QMessageBox msgbox;
			msgbox.setText("Your ID : "+query->value(0).toString());
			msgbox.exec();
			this->close();
		}
		else
		{
			query=FiveOfRulerDB::select("technician","email",ui.lineEdit_Email->text());

			QMessageBox msgbox;
			msgbox.setText("Your ID : "+query->value(0).toString());
			msgbox.exec();
			this->close();
		}
	}
	else
	{

	}
}
void ForgotIdPwDialog::idshow()
{
	ui.label_Question->hide();
	ui.lineEdit_Question->hide();
}
void ForgotIdPwDialog::pwshow()
{
	ui.label_Question->show();
	ui.lineEdit_Question->show();
}
