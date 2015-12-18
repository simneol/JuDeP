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
		QVector<QPair<QString,QString> > data;
		data.push_back(qMakePair<QString,QString>("name",user->getId()));
		data.push_back(qMakePair<QString,QString>("component",ui.Requesthead->text()));
		data.push_back(qMakePair<QString,QString>("type",ui.RequestType->text()));
		data.push_back(qMakePair<QString,QString>("symptom",ui.RequestSymptom->text()));
		data.push_back(qMakePair<QString,QString>("etc",ui.Requestcontent->toPlainText()));
		data.push_back(qMakePair<QString,QString>("price","-1"));
		data.push_back(qMakePair<QString,QString>("care","1"));

		QSqlQuery *query = FiveOfRulerDB::insert("product", data);

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