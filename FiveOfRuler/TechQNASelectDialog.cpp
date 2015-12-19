#include "TechQNASelectDialog.h"
#include "FiveOfRulerDB.h"
#include "TechnicianWindow.h"
#include "WindowManager.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

TechQNASelectDialog::TechQNASelectDialog(QWidget *parent, TechUser* user) : QDialog(parent)
{
	selectNumber = -1;
	ui.setupUi(this);
	this->user = user;

	showData();

	connect(ui.listView_qna, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onClickListItem(const QModelIndex &)));
	connect(ui.btn_Select, SIGNAL(clicked()), this, SLOT(onClickSelectBtn()));
}

TechQNASelectDialog::~TechQNASelectDialog(){ qDebug("~QNASeeDialog()"); }

#pragma region Signal

// 리스트에나온 QNA를 눌렀을 때 내용을 다이어로그로 보여주는 함수
void TechQNASelectDialog::onClickListItem(const QModelIndex &index)
{
	selectNumber = index.row() + 1;
}

void TechQNASelectDialog::onClickSelectBtn()
{
	TechnicianWindow *target = (TechnicianWindow*)WindowManager::getWindow("TechnicianWindow");
	qDebug("SelectButton");
	qDebug("%d", selectNumber);
	target->OpenQuestionReplyDialog(selectNumber);
}

void TechQNASelectDialog::showData()
{
	user = (TechUser *)InstanceOfUserManager.getInfo();
	model = new QStringListModel(this);

	int i;

	QStringList list;
	QString str;

	QSqlQuery *query = FiveOfRulerDB::select("qna", "isReply", "false");

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

	ui.listView_qna->setModel(model);
}

#pragma endregion