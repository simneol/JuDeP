#include "LoginWindow.h"

#include <QtCore/QDebug>

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	// Qt Desinger�� ������ Ui���� �����ϴ� �Լ�
	ui.setupUi(this);

	connect(ui.btn_Login,SIGNAL(clicked()),this,SLOT(slotEmitLoginSignal()));	// �α��� ��ư ������, login() ����
	connect(this,
		SIGNAL(slotLoginSignal(QString,QString,bool)),
		&loginManager,
		SLOT(slotLogin(QString,QString,bool)));

	connect(ui.btn_Register,SIGNAL(clicked()),&loginManager,SLOT(slotOpenRegisterDialog()));
	connect(ui.btn_ForgotIdPw,SIGNAL(clicked()),&loginManager,SLOT(slotOpenForgotIdPwDialog()));

	connect(ui.action_Quit,SIGNAL(triggered()),this,SLOT(close()));
}

LoginWindow::~LoginWindow(){qDebug("~LoginWindow()");}

void LoginWindow::slotEmitLoginSignal()
{
	emit slotLoginSignal(ui.lineEdit_Id->text(),
		ui.lineEdit_Pw->text(),
		ui.radio_User->isChecked());
}