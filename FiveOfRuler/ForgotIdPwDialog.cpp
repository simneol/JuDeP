#include "ForgotIdPwDialog.h"

#include <QtCore/QDebug>

#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

#include <QtWidgets/QMessageBox>

ForgotIdPwDialog::ForgotIdPwDialog(QSqlDatabase db,QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->db=db;
	idshow();
	connect(ui.idRadioButton,SIGNAL(clicked()),this,SLOT(idshow()));
	connect(ui.pwRadioButton,SIGNAL(clicked()),this,SLOT(pwshow()));
	connect(ui.findButton,SIGNAL(clicked()),this,SLOT(find()));
}

ForgotIdPwDialog::~ForgotIdPwDialog(){qDebug("~ForgotIdPwDialog()");}

void ForgotIdPwDialog::find()
{
	QSqlQuery query;

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
			qDebug()<<"SELECT * FROM user_table where email=\'"+ui.emailLineEdit->text()+"\'";
			query.prepare("SELECT * FROM user_table where email=\'"+ui.emailLineEdit->text()+"\'");

			if( !query.exec() )
				qDebug() << query.lastError();
			else
			{
				query.next();
				QMessageBox msgbox;
				msgbox.setText("Your ID : "+query.value(0).toString());
				msgbox.exec();
				this->close();
			}
		}
		else
		{
			qDebug()<<"SELECT * FROM technician_table where email=\'"+ui.emailLineEdit->text()+"\'";
			query.prepare("SELECT * FROM technician_table where email=\'"+ui.emailLineEdit->text()+"\'");

			if( !query.exec() )
				qDebug() << query.lastError();
			else
			{
				query.next();
				QMessageBox msgbox;
				msgbox.setText("Your ID : "+query.value(0).toString());
				msgbox.exec();
				this->close();
			}
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