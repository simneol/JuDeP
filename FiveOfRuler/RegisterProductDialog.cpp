/***************************************
/ 작성자 : 박성수
/ 클래스 : RegisterProductDialog
/ 용  도 : 프로덕트를 등록하는 다이어로그
/***************************************/
#include "RegisterProductDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>
#include <QString>
#include <QtWidgets/QMessageBox>

RegisterProductDialog::RegisterProductDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}


RegisterProductDialog::~RegisterProductDialog()
{
	qDebug("~QuestionReplyDialog()");
}
