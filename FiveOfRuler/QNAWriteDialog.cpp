#include "QNAWriteDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

QNAWriteDialog::QNAWriteDialog(QWidget *parent,User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user=user;

	connect(ui.sendconfirm, SIGNAL(clicked()), this, SLOT(write()));	// Ȯ���ϰ�
	connect(ui.sendconfirm, SIGNAL(clicked()), this, SLOT(closeQNA()));	// ���پ�
	connect(ui.sendcansel, SIGNAL(clicked()), this, SLOT(closeQNA()));	// ���پ�
}

QNAWriteDialog::~QNAWriteDialog(){qDebug("~QNAWriteDialog()");}

void QNAWriteDialog::write()
{
	QVector<QPair<QString, QString> > data;
	QMessageBox msgbox;

	// �����̳� ������ �ϳ��� ���߸��� ������ ����
	if (ui.head->text() == NULL || ui.content->toPlainText() == NULL)
	{
		msgbox.setText("Error:\n Please write title and contents !");
		msgbox.exec();
		this->close();
	}
	// ��� �� ĭ�� ä���� �� ����
	else
	{
		data.push_back(qMakePair<QString, QString>("writer", user->getId()));
		data.push_back(qMakePair<QString, QString>("title", ui.head->text()));
		data.push_back(qMakePair<QString, QString>("content", ui.content->toPlainText()));

		if (FiveOfRulerDB::insert("qna", data) != NULL)
			msgbox.setText(" Registration Complete ! ");
		else
			msgbox.setText(" Registration Fail ! ");

		msgbox.setText("Success !");
		msgbox.exec();
		this->close();
	}
}

void QNAWriteDialog::closeQNA()
{
	this->close();

	delete this;
}
