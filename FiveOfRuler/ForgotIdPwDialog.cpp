#include "ForgotIdPwDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>

#include <QtWidgets/QMessageBox>

ForgotIdPwDialog::ForgotIdPwDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	/* 창을 열자마자 기본 설정은, id찾기 */
	slotIdshow();
	connect(ui.radio_Id,SIGNAL(clicked()),this,SLOT(slotIdshow()));
	connect(ui.radio_Pw,SIGNAL(clicked()),this,SLOT(slotPwshow()));
	connect(ui.btn_Find,SIGNAL(clicked()),this,SLOT(slotFind()));
}

ForgotIdPwDialog::~ForgotIdPwDialog(){qDebug("~ForgotIdPwDialog()");}

// ID 혹은 PW 찾기
void ForgotIdPwDialog::slotFind()
{
	QMessageBox msgbox;
	QSqlQuery *query;

	// 눌린 버튼에 따라, 각기 다른 테이블에서 email로 id 가져오기
	if(ui.btn_User->isChecked())
		query=FiveOfRulerDB::select("user","email",ui.lineEdit_Email->text());
	else
		query=FiveOfRulerDB::select("technician","email",ui.lineEdit_Email->text());

	// ID 찾기 일시 바로 출력
	if(ui.radio_Id->isChecked())
	{
		if(query->isValid())
			msgbox.setText("Your ID : "+query->value(0).toString());
		else
			msgbox.setText("Cannot find your ID!");
	}
	else
	{
		// PW 찾기 일 시, 질문과 답도 일치해야 출력
		if(query->isValid()
			&&query->value(3).toInt()==ui.comboBox_Question->currentIndex()
			&&query->value(4).toString()==ui.lineEdit_Answer->text())
			msgbox.setText("Your PW : "+query->value(1).toString());
		else
			msgbox.setText("Cannot find your PW!");
	}
	msgbox.exec();
	this->close();
}

// id찾기 시, id찾기에 필요없는 ui요소 감추기
void ForgotIdPwDialog::slotIdshow()
{
	ui.label_Question->hide();
	ui.label_Answer->hide();
	ui.comboBox_Question->hide();
	ui.lineEdit_Answer->hide();
}

// pw찾기 시, pw찾기에 필요한 ui요소 보이기
void ForgotIdPwDialog::slotPwshow()
{
	ui.label_Question->show();
	ui.label_Answer->show();
	ui.comboBox_Question->show();
	ui.lineEdit_Answer->show();
}