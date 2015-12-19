#include "QlistWindow.h"
#include "FiveOfRulerDB.h"
#include <Windows.h>

#include "WindowManager.h"

// 리스트의 생성자
QlistWindow::QlistWindow(QWidget *parent, User *user) :
QDialog(parent)
{
	ui.setupUi(this);

	userStatic = user;

	showData();

	connectSignal(user);
}

// 리스트의 정보를 정리하는 소멸자이다.
QlistWindow::~QlistWindow()
{
}

// 시그널을 구분하는 메서드이다.
void QlistWindow::connectSignal(User *user)
{
	connect(ui.listView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onClickListItem(const QModelIndex &)));
	connect(ui.QnA1, SIGNAL(clicked()), this, SLOT(openQNAWriteDialog()));
	connect(ui.close, SIGNAL(clicked()), this, SLOT(closeWindow()));
	connect(ui.NewWindowLable, SIGNAL(clicked()), this, SLOT(newWindow()));
}

// 리스트에나온 QNA를 눌렀을 때 내용을 다이어로그로 보여주는 함수
void QlistWindow::onClickListItem(const QModelIndex &index)
{
	QSqlQuery *query1 = FiveOfRulerDB::select("qna", "postIndex", index.data().toString());

	QMessageBox::information(this, "QNA", "QNA: \n" + query1->value(3).toString()
		+ "\n\n" + "Re: \n");
}

// 글쓰기 버튼을 눌렀을시 QNA창을 열어주는 실행하는 함수
void QlistWindow::openQNAWriteDialog()
{
	qnaWriteDialog = new QNAWriteDialog(0, userStatic);
	qnaWriteDialog->show();
}

// 닫기버튼을 눌렀을시 실행하는 함수
void QlistWindow::closeWindow()
{
	this->close();

	delete this;
}

// 새로고침하는 함수
void QlistWindow::newWindow()
{
	showData();
}

// 역순으로 데이터를 출력하는 함수
void QlistWindow::showData()
{
	model = new QStringListModel(this);

	int i;

	QStringList list;
	QString str;

	QSqlQuery *query = FiveOfRulerDB::select("qna", "writer", userStatic->getId());

	qnaWriteDialog = NULL;

	while (query->next());

	while (query->previous())
	{
		for (int j = 0; j < 3; j++)
		{
			if (!j)
				str = query->value(j).toString();
			else
				str += query->value(j).toString();

			if (j != 2)
				str += "  \tl ";
		}
		list << str;
	}
	model->setStringList(list);

	ui.listView->setModel(model);
}