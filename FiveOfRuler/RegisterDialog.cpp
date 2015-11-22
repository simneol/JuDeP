#include "RegisterDialog.h"

#include <QtCore/QDebug>

#include <QtSql/QSqlQuery>

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
	QSqlQuery *query;

	qDebug()<<"INSERT INTO user_table (id, pw, name, address, email) VALUES (\'"\
		+ui.idLineEdit->text()+"\', \'"+ui.pwLineEdit->text()+"\', \'"+ui.nameLineEdit->text()+"\', \'"\
		+ui.addressLineEdit->text()+"\', \'"+ui.emailLineEdit->text()+"\')";
	/* Prepared Statement �̿� */
	//	query.prepare("INSERT INTO user_table (id, pw, name, address, email) VALUES (\'"\
	+ui.idLineEdit->text()+"\', \'"+ui.pwLineEdit->text()+"\', \'"+ui.nameLineEdit->text()+"\', \'"\
	+ui.addressLineEdit->text()+"\', \'"+ui.emailLineEdit->text()+"\')");

	QMessageBox msgBox;
	msgBox.setText(" Registration Complete ! ");
	msgBox.exec();
	this->close();
}