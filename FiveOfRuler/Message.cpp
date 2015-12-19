#include "Message.h"
#include "FiveOfRulerDB.h"

#include <Windows.h>

#include "WindowManager.h"

#include <QtCore/QDebug>

#include <QtWidgets/QMessageBox>

// 문주원 2014112022
// 용도 : 메시지에 관한 기본적인 정의와 시그널을 받아 처리하는 생성자이다.
Message::Message(QWidget *parent, User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;

	connect(ui.sendMessage, SIGNAL(clicked()), this, SLOT(writeMessage()));	// 확인하고
	connect(ui.closeMessage, SIGNAL(clicked()), this, SLOT(closeMessage()));	// 끈다양
	connect(ui.outputMessage, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onClickListItem(const QModelIndex &)));
	connect(ui.refereshMessage, SIGNAL(clicked()), this, SLOT(newWindow()));	// 끈다양
}

Message::~Message(){ qDebug("~QNAWriteDialog()"); }

void Message::writeMessage()
{
	QMessageBox msgbox;

	// 제목이나 내용중 하나를 빠뜨리고 썼을때 실행
	if (ui.inputMessage->toPlainText() == NULL || ui.inputMessageTitle->text() == NULL || ui.receiverMessage->text() == NULL)
	{
		msgbox.setText("Error:\n Please write title and contents !");
		msgbox.exec();
		this->close();
	}
	// 모든 빈 칸을 채웠을 때 실행
	else
	{
		QVector<QPair<QString, QString> > data;
		data.push_back(qMakePair<QString, QString>("sender_id", user->getId()));
		data.push_back(qMakePair<QString, QString>("receiver_id", ui.receiverMessage->text()));
		data.push_back(qMakePair<QString, QString>("title", ui.inputMessageTitle->text()));
		data.push_back(qMakePair<QString, QString>("contents", ui.inputMessage->toPlainText()));

		QSqlQuery *query = FiveOfRulerDB::insert("message", data);

		msgbox.setText("Success !");
		msgbox.exec();

		this->showData();
	}
}

void Message::closeMessage()
{
	this->close();

	delete this;
}

// 용도 : 리스트에나온 정보를 눌렀을 때 내용을 다이어로그로 보여주는 함수
void Message::onClickListItem(const QModelIndex &index)
{
	QSqlQuery *query1 = FiveOfRulerDB::select("message", "index", index.data().toString());

	QMessageBox::information(this, "Message", "Sender: " + query1->value(1).toString()
		+ "\n" + "Title : " + query1->value(3).toString()
		+ "\n\n" + "Message :\n " + query1->value(4).toString()
		+ "\n\n" + "Receiver : " + query1->value(2).toString());
}

// 용도 : 새로고침하는 함수
void Message::newWindow()
{
	this->showData();
}

// 용도 : 역순으로 데이터를 출력하는 함수
void Message::showData()
{
	model = new QStringListModel(this);

	int i;

	QStringList list;
	QString str;

	QSqlQuery *query = FiveOfRulerDB::select("message", "sender_id", user->getId());

	//qnaWriteDialog = NULL;

	while (query->next());

	// UserWindow 상에서 자신이 제품을 올린 정보를 보여준다.
	while (query->previous())
	{
		if (query->value(2).toString() == ui.receiverMessage->text())
		{
			str = query->value(0).toString();
			str += "  \tl ";

			str += query->value(3).toString();

			list << str;
		}
	}
	model->setStringList(list);

	ui.outputMessage->setModel(model);
}