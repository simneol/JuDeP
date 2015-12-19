#include "RequestShow.h"
#include "FiveOfRulerDB.h"
#include <Windows.h>

#include "WindowManager.h"

// 리스트의 생성자
RequestShow::RequestShow(QWidget *parent, User *user) :
QDialog(parent)
{
	ui.setupUi(this);

	userStatic = user;

	showData();

	connectSignal(user);
}

RequestShow::~RequestShow()
{
}

// 시그널을 구분하는 함수 해당되는 시글널에 해당하는 함수를 불러준다.
void RequestShow::connectSignal(User *user)
{
	connect(ui.listView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onClickListItem(const QModelIndex &)));
	connect(ui.RequestClose, SIGNAL(clicked()), this, SLOT(closeWindow()));
	connect(ui.NewWindowRequest, SIGNAL(clicked()), this, SLOT(newWindow()));
}

// 리스트에나온 제품정보를 눌렀을 때 내용을 다이어로그로 보여주는 메서드이다.
void RequestShow::onClickListItem(const QModelIndex &index)
{
	QSqlQuery *query1 = FiveOfRulerDB::select("product", "postIndex", index.data().toString());

	// 제품정보가 1이면 아직 세팅되지 않았다는 의미이다.
	if (query1->value(9).toString() == "1")
		care = "Not set";
	// 제품정보가 0이면 현재 실행되고 있다는 의미이다.
	else if (query1->value(0).toString() == "0")
		care = "Ongoing";
	// 제품정보가 1이나 0이 아니면 제품의 처리가 끝났다는 의미이다.
	else
		care = "Finish";

	if(query1->value(5).toString() == "-1")
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

// 닫기버튼을 눌렀을시 실행하는 메서드이다.
void RequestShow::closeWindow()
{
	this->close();

	delete this;
}

// 새로고침하는 메서드이다.
void RequestShow::newWindow()
{
	showData();
}

// 역순으로 데이터를 출력하는 메서드이다.
void RequestShow::showData()
{
	model = new QStringListModel(this);

	int i;

	QStringList list;
	QString str;

	QSqlQuery *query = FiveOfRulerDB::select("product", "name", userStatic->getId());

	//qnaWriteDialog = NULL;

	// 먼저 쿼리를 제일 끝으로 옮기고 나서 다음 실행을 한다.
	while (query->next());

	//쿼리가 제일 끝으로 옮겨져 있으므로 이 전의 값들을 확인해서 정보들을 받아온다.
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

		str += query->value(6).toString();

		list << str;
	}
	model->setStringList(list);

	ui.listView->setModel(model);
}