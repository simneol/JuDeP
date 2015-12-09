#include "LoginWindow.h"

#include <QtCore/QDebug>

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	// Qt Desinger로 구성한 Ui들을 구성하는 함수
	ui.setupUi(this);

	connect(ui.loginButton,SIGNAL(clicked()),this,SLOT(slotEmitLoginSignal()));	// 로그인 버튼 누르면, login() 실행
	connect(this,SIGNAL(slotLoginSignal(QString,QString,bool)),&loginManager,SLOT(login(QString,QString,bool)));

	connect(ui.registerButton,SIGNAL(clicked()),&loginManager,SLOT(openRegisterDialog()));
	connect(ui.forgotIdPwButton,SIGNAL(clicked()),&loginManager,SLOT(openForgotIdPwDialog()));

	connect(ui.action_Quit,SIGNAL(triggered()),this,SLOT(close()));
}

LoginWindow::~LoginWindow(){qDebug("~LoginWindow()");}

void LoginWindow::slotEmitLoginSignal(){emit slotLoginSignal(ui.idLineEdit->text(),ui.pwLineEdit->text(),ui.userRadioButton->isChecked());}