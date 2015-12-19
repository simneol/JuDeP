#include "RegisterDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>

#include <QtWidgets/QMessageBox>

RegisterDialog::RegisterDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.registerButton,SIGNAL(clicked()),this,SLOT(slotSignup()));
	connect(ui.idDuplicationCheck,SIGNAL(clicked()),this,SLOT(slotCheckIdDuplication()));

	//id창의 항목이 변경되면, 중복체크를 다시 하도록 설정
	connect(ui.idLineEdit,SIGNAL(textChanged(QString)),this,SLOT(slotInitDuplication()));
}

RegisterDialog::~RegisterDialog(){qDebug("~RegisterDialog()");}

// 회원가입 과정
void RegisterDialog::slotSignup()
{
	// ID 중복체크를 안했거나, 중복일 시
	if(is_idDuplicated)
	{
		QMessageBox msgbox;
		msgbox.setText("Please check duplication !");
		msgbox.exec();
		return;
	}
	// 각 column에 해당하는 record를 pair로 묶어서 vector에 삽입
	QVector<QPair<QString,QString> > data;
	data.push_back(qMakePair<QString,QString>("id",ui.idLineEdit->text()));
	data.push_back(qMakePair<QString,QString>("pw",ui.pwLineEdit->text()));
	data.push_back(qMakePair<QString,QString>("email",ui.emailLineEdit->text()));
	data.push_back(qMakePair<QString,QString>("question",QString::number((ui.questionComboBox->currentIndex()))));
	data.push_back(qMakePair<QString,QString>("answer",ui.answerLineEdit->text()));

	QMessageBox msgBox;
	if(FiveOfRulerDB::insert("user",data)!=NULL)
		msgBox.setText(" Registration Complete ! ");
	else
		msgBox.setText(" Registration Fail ! ");
	msgBox.exec();
	this->close();
}

void RegisterDialog::slotCheckIdDuplication()
{
	QMessageBox msgBox;
	// User, Technician 모두 찾아서 유효한 게 나오면 중복
	QSqlQuery *query=FiveOfRulerDB::select("user","id",ui.idLineEdit->text());
	if(!query->isValid())
		query=FiveOfRulerDB::select("technician","id",ui.idLineEdit->text());
	if(query->isValid())
	{
		msgBox.setText("This ID is already exist !! \n Please use another ID !");
		is_idDuplicated=true;
	}
	else
	{
		msgBox.setText("This ID can be used !");
		is_idDuplicated=false;
	}
	msgBox.exec();
}

// 중복체크를 다시 해야하는경우
void RegisterDialog::slotInitDuplication()
{
	// 변수 초기화
	is_idDuplicated=true;
}