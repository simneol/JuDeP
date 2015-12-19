#include "UserWindow.h"
#include "FiveOfRulerDB.h"
#include "WindowManager.h"

#include <QtCore/QDebug>


UserWindow::UserWindow(QWidget *parent,Info* userInfo)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	userStatic = (User *)userInfo;
	userManager=new UserManager(userInfo);

	showData();

	connect(ui.action_Logout,SIGNAL(triggered()),userManager,SLOT(logout()));
	connect(ui.logout,SIGNAL(clicked()),userManager,SLOT(logout()));
	connect(ui.QnA,SIGNAL(clicked()),userManager,SLOT(openQNAWriteDialog()));
	connect(ui.RegiterProduct, SIGNAL(clicked()), userManager, SLOT(openRequestDialog()));
	connect(ui.SeeQnA, SIGNAL(clicked()), userManager, SLOT(openQNASeeDialog()));
	connect(ui.RegisterProductInformation, SIGNAL(clicked()), userManager, SLOT(openRegisterProductInformation()));

	connect(ui.listView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onClickListItem(const QModelIndex &)));
	connect(ui.NewWindowRequest, SIGNAL(clicked()), this, SLOT(newWindow()));
}

// ����Ʈ������ QNA�� ������ �� ������ ���̾�α׷� �����ִ� �Լ�
void UserWindow::onClickListItem(const QModelIndex &index)
{
	QSqlQuery *query1 = FiveOfRulerDB::select("product", "postIndex", index.data().toString());

	if (query1->value(9).toString() == "1")
		care = "Not set";
	else if (query1->value(0).toString() == "0")
		care = "Ongoing";
	else
		care = "Finish";

	if (query1->value(5).toString() == "-1")
		price = "Not decide";
	else
		price = query1->value(5).toString();

	QMessageBox::information(this, "Request Product", "Title : " + query1->value(6).toString()
		+ "\n" + "Care : " + care
		+ "\n" + "Symptom : " + query1->value(8).toString()
		+ "\n" + "Price : " + price
		+ "\n" + "Etc: \n" + query1->value(11).toString()
		+ "\n\n" + "Re: \n");
}

// ���ΰ�ħ�ϴ� �Լ�
void UserWindow::newWindow()
{
	showData();
}

// �������� �����͸� ����ϴ� �Լ�
void UserWindow::showData()
{
	model = new QStringListModel(this);

	int i;

	QStringList list;
	QString str;

	QSqlQuery *query = FiveOfRulerDB::select("product", "name", userStatic->getId());

	//qnaWriteDialog = NULL;

	while (query->next());

	while (query->previous())
	{
		str = query->value(12).toString();
		str += "  \tl ";

		if (query->value(9).toString() == "1")
			str += "Not set \tl ";
		else if (query->value(0).toString() == "0")
			str += "Ongoing \tl ";
		else
			str += "Finish    \tl ";

		str += query->value(8).toString();

		list << str;
	}
	model->setStringList(list);

	ui.listView->setModel(model);
}