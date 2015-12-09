#include "LoginWindow.h"

#include <QtCore/QDebug>

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	// Qt Desinger�� ������ Ui���� �����ϴ� �Լ�
	ui.setupUi(this);

	connect(ui.loginButton,SIGNAL(clicked()),this,SLOT(slotEmitLoginSignal()));	// �α��� ��ư ������, login() ����
	connect(this,SIGNAL(slotLoginSignal(QString,QString,bool)),&loginManager,SLOT(login(QString,QString,bool)));

	connect(ui.registerButton,SIGNAL(clicked()),&loginManager,SLOT(openRegisterDialog()));
	connect(ui.forgotIdPwButton,SIGNAL(clicked()),&loginManager,SLOT(openForgotIdPwDialog()));

	connect(ui.action_Quit,SIGNAL(triggered()),this,SLOT(close()));
}

LoginWindow::~LoginWindow(){qDebug("~LoginWindow()");}

void LoginWindow::slotEmitLoginSignal(){emit slotLoginSignal(ui.idLineEdit->text(),ui.pwLineEdit->text(),ui.userRadioButton->isChecked());}