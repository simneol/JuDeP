/***************************************
/ 작성자 : 박성수
/ 클래스 : ComponentSearchDailog
/ 용  도 : 부품을 찾는 다이어로그
/***************************************/
#include "ComponentSearchDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>
#include <QString>
#include <QtWidgets/QMessageBox>

ComponentSearchDailog::ComponentSearchDailog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}


ComponentSearchDailog::~ComponentSearchDailog()
{
	qDebug("~QuestionReplyDialog()");
}
