#include "QlistWindow.h"
#include "FiveOfRulerDB.h"
#include <Windows.h>

#include "WindowManager.h"

// ���ֿ� 2014112022
// �뵵 : ����Ʈ�� ������
QlistWindow::QlistWindow(QWidget *parent, User *user) :
QDialog(parent)
{
	ui.setupUi(this);

	userStatic = user;

	showData();

	connectSignal(user);
}

// �뵵 : ����Ʈ�� ������ �����ϴ� �Ҹ����̴�.
QlistWindow::~QlistWindow()
{
}

// �뵵 : �ñ׳��� �����ϴ� �޼����̴�.
void QlistWindow::connectSignal(User *user)
{
	connect(ui.listView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onClickListItem(const QModelIndex &)));
	connect(ui.QnA1, SIGNAL(clicked()), this, SLOT(openQNAWriteDialog()));
	connect(ui.close, SIGNAL(clicked()), this, SLOT(closeWindow()));
	connect(ui.NewWindowLable, SIGNAL(clicked()), this, SLOT(newWindow()));
}

// �뵵 : ����Ʈ������ QNA�� ������ �� ������ ���̾�α׷� �����ִ� �Լ�
void QlistWindow::onClickListItem(const QModelIndex &index)
{
	QSqlQuery *query1 = FiveOfRulerDB::select("qna", "postIndex", index.data().toString());

	QMessageBox::information(this, "QNA", "QNA: \n" + query1->value(3).toString()
		+ "\n\n" + "Re: \n");
}

// �뵵 : �۾��� ��ư�� �������� QNAâ�� �����ִ� �����ϴ� �Լ�
void QlistWindow::openQNAWriteDialog()
{
	qnaWriteDialog = new QNAWriteDialog(0, userStatic);
	qnaWriteDialog->show();
}

// �뵵 : �ݱ��ư�� �������� �����ϴ� �Լ�
void QlistWindow::closeWindow()
{
	this->close();

	delete this;
}

// �뵵 : ���ΰ�ħ�ϴ� �Լ�
void QlistWindow::newWindow()
{
	showData();
}

// �뵵 : �������� �����͸� ����ϴ� �Լ�
void QlistWindow::showData()
{
	model = new QStringListModel(this);

	int i;

	QStringList list;
	QString str;

	QSqlQuery *query = FiveOfRulerDB::select("qna", "writer", userStatic->getId());

	qnaWriteDialog = NULL;

	// �����͸� �ֱ� �������� �ڷʷ� �����־�� �ϹǷ�
	// ���� �ڷ� �����δ�.
	while (query->next());

	// ���� ���ʺ��� �����͸� ����Ͽ� �ֱ� �������� �����Ͱ� ��µǰ� �Ѵ�.
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