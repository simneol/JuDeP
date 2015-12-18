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
	QVector<QString> column,record;
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
		column.push_back("writer");
		column.push_back("title");
		column.push_back("content");

		record.push_back(user->getId());
		record.push_back(ui.head->text());
		record.push_back(ui.content->toPlainText());

		QSqlQuery *query = FiveOfRulerDB::insert("qna", column, record);

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
