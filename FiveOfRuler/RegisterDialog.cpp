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

	//idâ�� �׸��� ����Ǹ�, �ߺ�üũ�� �ٽ� �ϵ��� ����
	connect(ui.idLineEdit,SIGNAL(textChanged(QString)),this,SLOT(slotInitDuplication()));
}

RegisterDialog::~RegisterDialog(){qDebug("~RegisterDialog()");}

// ȸ������ ����
void RegisterDialog::slotSignup()
{
	// ID �ߺ�üũ�� ���߰ų�, �ߺ��� ��
	if(is_idDuplicated)
	{
		QMessageBox msgbox;
		msgbox.setText("Please check duplication !");
		msgbox.exec();
		return;
	}
	// �� column�� �ش��ϴ� record�� pair�� ��� vector�� ����
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
	// User, Technician ��� ã�Ƽ� ��ȿ�� �� ������ �ߺ�
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

// �ߺ�üũ�� �ٽ� �ؾ��ϴ°��
void RegisterDialog::slotInitDuplication()
{
	// ���� �ʱ�ȭ
	is_idDuplicated=true;
}