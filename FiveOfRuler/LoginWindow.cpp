#include "LoginWindow.h"

#include <QtCore/QDebug>

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	// Qt Desinger�� ������ Ui���� �����ϴ� �Լ�
	ui.setupUi(this);

	connect(ui.loginButton,SIGNAL(clicked()),this,SLOT(slotEmitLoginSignal()));	// �α��� ��ư ������, login() ����
	connect(this,
		SIGNAL(slotLoginSignal(QString,QString,bool)),
		&loginManager,
		SLOT(slotLogin(QString,QString,bool)));

	connect(ui.registerButton,SIGNAL(clicked()),&loginManager,SLOT(slotOpenRegisterDialog()));
	connect(ui.forgotIdPwButton,SIGNAL(clicked()),&loginManager,SLOT(slotOpenForgotIdPwDialog()));

	connect(ui.action_Quit,SIGNAL(triggered()),this,SLOT(close()));
}

LoginWindow::~LoginWindow(){qDebug("~LoginWindow()");}

void LoginWindow::slotEmitLoginSignal()
{
	slotLoginSignal(ui.idLineEdit->text(),
		ui.pwLineEdit->text(),
		ui.userRadioButton->isChecked());
}