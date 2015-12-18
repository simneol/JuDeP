#include "RequestProduct.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

RequestProduct::RequestProduct(QWidget *parent, User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;

	connect(ui.Request, SIGNAL(clicked()), this, SLOT(write()));	// 확인하고
	connect(ui.RequestClose, SIGNAL(clicked()), this, SLOT(closeRequest()));	// 끈다양
	connect(ui.RequestClose, SIGNAL(clicked()), this, SLOT(closeRequest()));	// 끈다양
}

RequestProduct::~RequestProduct(){ qDebug("~RequestProduct()"); }

void RequestProduct::write()
{
	QVector<QString> column, record;
	QMessageBox msgbox;

	// 제목이나 내용중 하나를 빠뜨리고 썼을때 실행
	if (ui.Requesthead->text() == NULL || ui.Requestcontent->toPlainText() == NULL || ui.RequestType == NULL || ui.RequestSymptom == NULL)
	{
		msgbox.setText("Error:\n Please write title and contents !");
		msgbox.exec();
		this->close();
	}
	// 모든 빈 칸을 채웠을 때 실행
	else
	{
		column.push_back("name");
		column.push_back("component");
		column.push_back("type");
		column.push_back("symptom");
		column.push_back("etc");
		column.push_back("price");
		column.push_back("care");

		record.push_back(user->getId());
		record.push_back(ui.Requesthead->text());
		record.push_back(ui.RequestType->text());
		record.push_back(ui.RequestSymptom->text());
		record.push_back(ui.Requestcontent->toPlainText());
		record.push_back("-1");
		record.push_back("1");

		QSqlQuery *query = FiveOfRulerDB::insert("product", column, record);

		msgbox.setText("Success !");
		msgbox.exec();
		this->close();
	}
}

void RequestProduct::closeRequest()
{
	this->close();

	delete this;
}