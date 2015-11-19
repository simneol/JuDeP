#include "ForgotIdPwDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>

#include <QtSql/QSqlQuery>

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
	QSqlQuery *query;

//	qDebug()<<"INSERT INTO user_table (id, pw, name, address, email) VALUES (\'"\
//		+ui.idLineEdit->text()+"\', \'"+ui.pwLineEdit->text()+"\', \'"+ui.nameLineEdit->text()+"\', \'"\
//		+ui.addressLineEdit->text()+"\', \'"+ui.emailLineEdit->text()+"\')";
	/* Prepared Statement ÀÌ¿כ */
//	query.prepare("INSERT INTO user_table (id, pw, name, address, email) VALUES (\'"\
//		+ui.idLineEdit->text()+"\', \'"+ui.pwLineEdit->text()+"\', \'"+ui.nameLineEdit->text()+"\', \'"\
//		+ui.addressLineEdit->text()+"\', \'"+ui.emailLineEdit->text()+"\')");
//	if( !query.exec() )
//		qDebug() << query.lastError();
//	else
//	{
//		QMessageBox msgBox;
//		msgBox.setText(" Registration Complete ! ");
//		msgBox.exec();
//		this->close();
//	}

	if(ui.idRadioButton->isChecked())
	{
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