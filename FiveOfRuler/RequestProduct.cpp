#include "RequestProduct.h"
#include "FiveOfRulerDB.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

RequestProduct::RequestProduct(QWidget *parent, User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;
	pushCombobox();

	connect(ui.Request, SIGNAL(clicked()), this, SLOT(write()));	// 확인하고
	connect(ui.RequestClose, SIGNAL(clicked()), this, SLOT(closeRequest()));	// 끈다양
	connect(ui.RequestClose, SIGNAL(clicked()), this, SLOT(closeRequest()));	// 끈다양
	connect(ui.nameComboBox, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

RequestProduct::~RequestProduct(){ qDebug("~RequestProduct()"); }

void RequestProduct::write()
{
	QVector<QPair<QString, QString> > data;
	QMessageBox msgbox;

	// 제목이나 내용중 하나를 빠뜨리고 썼을때 실행
	if (ui.Requestcontent->toPlainText() == NULL || ui.RequestType == NULL || ui.RequestSymptom == NULL)
	{
		msgbox.setText("Error:\n Please write title and contents !");
		msgbox.exec();
		this->close();
	}
	// 모든 빈 칸을 채웠을 때 실행
	else
	{
		data.push_back(qMakePair<QString, QString>("name", user->getId()));
		data.push_back(qMakePair<QString, QString>("component", ui.nameComboBox->currentText()));
		data.push_back(qMakePair<QString, QString>("type", ui.RequestType->text()));
		data.push_back(qMakePair<QString, QString>("symptom", ui.RequestSymptom->text()));
		data.push_back(qMakePair<QString, QString>("etc", ui.Requestcontent->toPlainText()));
		data.push_back(qMakePair<QString, QString>("price", "-1"));
		data.push_back(qMakePair<QString, QString>("care", "1"));

		if (FiveOfRulerDB::insert("product", data) != NULL)
			msgbox.setText(" Registration Complete ! ");
		else
			msgbox.setText(" Registration Fail ! ");

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

void RequestProduct::on_pushButton_clicked()
{
	QMessageBox::information(this, "Item Selection", ui.nameComboBox->currentText());
}


void RequestProduct::pushCombobox()
{
	QSqlQuery *query = FiveOfRulerDB::select("product", "User_Table_Id", user->getId());

	if(query->isValid())
		ui.nameComboBox->addItem(query->value(6).toString());

	while (query->next())
	{
		ui.nameComboBox->addItem(query->value(6).toString());
	}
}