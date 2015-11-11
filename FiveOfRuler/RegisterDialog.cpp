#include "RegisterDialog.h"

#include <QtCore/QDebug>

#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

#include <QtWidgets/QMessageBox>

RegisterDialog::RegisterDialog(QSqlDatabase db,QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->db=db;
	connect(ui.registerButton,SIGNAL(clicked()),this,SLOT(signup()));
}

RegisterDialog::~RegisterDialog(){qDebug("~RegisterDialog()");}

void RegisterDialog::signup()
{
	QSqlQuery query;

	qDebug()<<"INSERT INTO user_table (id, pw, name, address, email) VALUES (\'"\
		+ui.idLineEdit->text()+"\', \'"+ui.pwLineEdit->text()+"\', \'"+ui.nameLineEdit->text()+"\', \'"\
		+ui.addressLineEdit->text()+"\', \'"+ui.emailLineEdit->text()+"\')";
	/* Prepared Statement ÀÌ¿כ */
	query.prepare("INSERT INTO user_table (id, pw, name, address, email) VALUES (\'"\
		+ui.idLineEdit->text()+"\', \'"+ui.pwLineEdit->text()+"\', \'"+ui.nameLineEdit->text()+"\', \'"\
		+ui.addressLineEdit->text()+"\', \'"+ui.emailLineEdit->text()+"\')");
	if( !query.exec() )
		qDebug() << query.lastError();
	else
	{
		QMessageBox msgBox;
		msgBox.setText(" Registration Complete ! ");
		msgBox.exec();
		this->close();
	}
}