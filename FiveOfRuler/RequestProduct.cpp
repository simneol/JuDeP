#include "RequestProduct.h"
#include "FiveOfRulerDB.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

// 문주원 2014112022
// 용도 : 제품의 수리를 맡기게 되는 메서드이다.
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

// 용도 : 제품의 기본적인 정보를 저장하여 사용하게되는 메서드이다.
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

// 용도 : 열려진 창을 닫는 메서드이다.
void RequestProduct::closeRequest()
{
	this->close();

	delete this;
}

// 용도 : 버튼이 눌렸을 때 실행하는 메서드이다.
void RequestProduct::on_pushButton_clicked()
{
	QMessageBox::information(this, "Item Selection", ui.nameComboBox->currentText());
}

// 용도 : 콤보박스에 값을 저장하는 메서드이다. 콤보박스에는 사용자가 등록한 제품만 등록할 수 있으므로 콤보박스를 사용하는 메서드이다.
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