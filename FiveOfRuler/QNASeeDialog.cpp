#include "QNASeeDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

// ���ֿ� 2014112022
// �뵵 : Qna�� �����ִ� �������ϴ� �������̴�.
QNASeeDialog::QNASeeDialog(QWidget *parent, User* user) : QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;
}

// �뵵 : Qna�� ��ü�� ���ִ� �Ҹ����̴�.
QNASeeDialog::~QNASeeDialog(){ qDebug("~QNASeeDialog()"); }

// �뵵 : Qna�� ������ ���� �޼����̴�.
void QNASeeDialog::write()
{
	QString column, record;

	//QSqlQuery *query = FiveOfRulerDB::select("qna", column, record);
}

// �뵵 : Qnaâ�� �ݴ� �޼����̴�.
void QNASeeDialog::closeQNA()
{
	this->close();
}