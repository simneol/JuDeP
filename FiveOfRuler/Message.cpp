#include "Message.h"
#include "FiveOfRulerDB.h"

#include <Windows.h>

#include "WindowManager.h"

#include <QtCore/QDebug>

#include <QtWidgets/QMessageBox>

// ���ֿ� 2014112022
// �뵵 : �޽����� ���� �⺻���� ���ǿ� �ñ׳��� �޾� ó���ϴ� �������̴�.
Message::Message(QWidget *parent, User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;

	connect(ui.sendMessage, SIGNAL(clicked()), this, SLOT(writeMessage()));	// Ȯ���ϰ�
	connect(ui.closeMessage, SIGNAL(clicked()), this, SLOT(closeMessage()));	// ���پ�
	connect(ui.outputMessage, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onClickListItem(const QModelIndex &)));
	connect(ui.refereshMessage, SIGNAL(clicked()), this, SLOT(newWindow()));	// ���پ�
}

Message::~Message(){ qDebug("~QNAWriteDialog()"); }

void Message::writeMessage()
{
	QMessageBox msgbox;

	// �����̳� ������ �ϳ��� ���߸��� ������ ����
	if (ui.inputMessage->toPlainText() == NULL || ui.inputMessageTitle->text() == NULL || ui.receiverMessage->text() == NULL)
	{
		msgbox.setText("Error:\n Please write title and contents !");
		msgbox.exec();
		this->close();
	}
	// ��� �� ĭ�� ä���� �� ����
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

// �뵵 : ����Ʈ������ ������ ������ �� ������ ���̾�α׷� �����ִ� �Լ�
void Message::onClickListItem(const QModelIndex &index)
{
	QSqlQuery *query1 = FiveOfRulerDB::select("message", "index", index.data().toString());

	QMessageBox::information(this, "Message", "Sender: " + query1->value(1).toString()
		+ "\n" + "Title : " + query1->value(3).toString()
		+ "\n\n" + "Message :\n " + query1->value(4).toString()
		+ "\n\n" + "Receiver : " + query1->value(2).toString());
}

// �뵵 : ���ΰ�ħ�ϴ� �Լ�
void Message::newWindow()
{
	this->showData();
}

// �뵵 : �������� �����͸� ����ϴ� �Լ�
void Message::showData()
{
	model = new QStringListModel(this);

	int i;

	QStringList list;
	QString str;

	QSqlQuery *query = FiveOfRulerDB::select("message", "sender_id", user->getId());

	//qnaWriteDialog = NULL;

	while (query->next());

	// UserWindow �󿡼� �ڽ��� ��ǰ�� �ø� ������ �����ش�.
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