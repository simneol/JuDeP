#include "RegisterProductInformation.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

RegisterProductInformation::RegisterProductInformation(QWidget *parent, User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;

	connect(ui.registerCheck, SIGNAL(clicked()), this, SLOT(write()));	// 확인하고
	connect(ui.registerCheck, SIGNAL(clicked()), this, SLOT(closeRegister()));	// 끈다양
	connect(ui.registerCancel, SIGNAL(clicked()), this, SLOT(closeRegister()));	// 끈다양
}

RegisterProductInformation::~RegisterProductInformation(){ qDebug("~QNAWriteDialog()"); }

void RegisterProductInformation::write()
{
	QVector<QPair<QString, QString> > data;
	QMessageBox msgbox;

	// 제목이나 내용중 하나를 빠뜨리고 썼을때 실행
	if (ui.productInformation->text() == NULL)
	{
		msgbox.setText("Error:\n Please write name  !");
		msgbox.exec();
		this->close();
	}
	// 모든 빈 칸을 채웠을 때 실행
	else
	{
		data.push_back(qMakePair<QString, QString>("User_Table_Id", user->getId()));
		data.push_back(qMakePair<QString, QString>("component", ui.productInformation->text()));

		if (FiveOfRulerDB::insert("product", data) != NULL)
			msgbox.setText(" Registration Complete ! ");
		else
			msgbox.setText(" Registration Fail ! ");

		msgbox.setText("Success !");
		msgbox.exec();
		this->close();
	}
}

void RegisterProductInformation::closeRegister()
{
	this->close();

	delete this;
}
