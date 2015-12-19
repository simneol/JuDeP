/***************************************
/ 작성자 : 박성수
/ 클래스 : ProductSearchDialog
/ 용  도 : 제품을 찾는 다이어로그
/***************************************/
#include "ProductSearchDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>
#include <QString>
#include <QtWidgets/QMessageBox>

ProductSearchDialog::ProductSearchDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}


ProductSearchDialog::~ProductSearchDialog()
{
	qDebug("~QuestionReplyDialog()");
}
