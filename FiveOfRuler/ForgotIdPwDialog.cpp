#include "ForgotIdPwDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>

#include <QtWidgets/QMessageBox>

ForgotIdPwDialog::ForgotIdPwDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	slotIdshow();
	connect(ui.idRadioButton,SIGNAL(clicked()),this,SLOT(slotIdshow()));
	connect(ui.pwRadioButton,SIGNAL(clicked()),this,SLOT(slotPwshow()));
	connect(ui.findButton,SIGNAL(clicked()),this,SLOT(slotFind()));
}

ForgotIdPwDialog::~ForgotIdPwDialog(){qDebug("~ForgotIdPwDialog()");}

void ForgotIdPwDialog::slotFind()
{
	if(ui.idRadioButton->isChecked())
	{
		QSqlQuery *query;
		if(ui.userButton->isChecked())
		{
			query=FiveOfRulerDB::select("user","email",ui.emailLineEdit->text());
			QMessageBox msgbox;
			msgbox.setText("Your ID : "+query->value(0).toString());
			msgbox.exec();
			this->close();
		}
		else
		{
			query=FiveOfRulerDB::select("technician","email",ui.emailLineEdit->text());

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
void ForgotIdPwDialog::slotIdshow()
{
	ui.questionLabel->hide();
	ui.questionLineEdit->hide();
}
void ForgotIdPwDialog::slotPwshow()
{
	ui.questionLabel->show();
	ui.questionLineEdit->show();
}