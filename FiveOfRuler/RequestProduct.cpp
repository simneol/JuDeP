#include "RequestProduct.h"
#include "FiveOfRulerDB.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

// ���ֿ� 2014112022
// �뵵 : ��ǰ�� ������ �ñ�� �Ǵ� �޼����̴�.
RequestProduct::RequestProduct(QWidget *parent, User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;
	pushCombobox();

	connect(ui.Request, SIGNAL(clicked()), this, SLOT(write()));	// Ȯ���ϰ�
	connect(ui.RequestClose, SIGNAL(clicked()), this, SLOT(closeRequest()));	// ���پ�
	connect(ui.RequestClose, SIGNAL(clicked()), this, SLOT(closeRequest()));	// ���پ�
	connect(ui.nameComboBox, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

RequestProduct::~RequestProduct(){ qDebug("~RequestProduct()"); }

// �뵵 : ��ǰ�� �⺻���� ������ �����Ͽ� ����ϰԵǴ� �޼����̴�.
void RequestProduct::write()
{
	QVector<QPair<QString, QString> > data;
	QMessageBox msgbox;

	// �����̳� ������ �ϳ��� ���߸��� ������ ����
	if (ui.Requestcontent->toPlainText() == NULL || ui.RequestType == NULL || ui.RequestSymptom == NULL)
	{
		msgbox.setText("Error:\n Please write title and contents !");
		msgbox.exec();
		this->close();
	}
	// ��� �� ĭ�� ä���� �� ����
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

// �뵵 : ������ â�� �ݴ� �޼����̴�.
void RequestProduct::closeRequest()
{
	this->close();

	delete this;
}

// �뵵 : ��ư�� ������ �� �����ϴ� �޼����̴�.
void RequestProduct::on_pushButton_clicked()
{
	QMessageBox::information(this, "Item Selection", ui.nameComboBox->currentText());
}

// �뵵 : �޺��ڽ��� ���� �����ϴ� �޼����̴�. �޺��ڽ����� ����ڰ� ����� ��ǰ�� ����� �� �����Ƿ� �޺��ڽ��� ����ϴ� �޼����̴�.
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