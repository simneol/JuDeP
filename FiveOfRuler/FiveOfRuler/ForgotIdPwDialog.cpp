#include "ForgotIdPwDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>

#include <QtWidgets/QMessageBox>

ForgotIdPwDialog::ForgotIdPwDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	idshow();
	connect(ui.idRadioButton,SIGNAL(clicked()),this,SLOT(idshow()));
	connect(ui.pwRadioButton,SIGNAL(clicked()),this,SLOT(pwshow()));
	connect(ui.findButton,SIGNAL(clicked()),this,SLOT(find()));
}

ForgotIdPwDialog::~ForgotIdPwDialog(){qDebug("~ForgotIdPwDialog()");}

void ForgotIdPwDialog::find()
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
void ForgotIdPwDialog::idshow()
{
	ui.questionLabel->hide();
	ui.questionLineEdit->hide();
}
void ForgotIdPwDialog::pwshow()
{
	ui.questionLabel->show();
	ui.questionLineEdit->show();
}