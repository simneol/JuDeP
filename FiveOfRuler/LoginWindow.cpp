#include "LoginWindow.h"
#include "UserWindow.h"
#include "TechnicianWindow.h"
#include "RegisterDialog.h"
#include "ForgotIdPwDialog.h"
#include "DatabaseInfo.h"

#include <QDebug>
#include <QtCore/QThread>

#include <QtWidgets/QAction>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>

#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

LoginWindow::LoginWindow(QMainWindow* prevWindow, QWidget *parent)
	: QMainWindow(parent)
{
	if(prevWindow!=NULL)
		prevWindow->close();
	// Qt Desinger로 구성한 Ui들을 구성하는 함수
	ui.setupUi(this);

	/* 생성자에서 멤버 변수 db 초기화 */
	db=QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(DB_HOSTNAME);
	db.setPort(DB_PORT);
	db.setDatabaseName(DB_DATABASENAME);
	db.setUserName(DB_USERNAME);
	db.setPassword(DB_PASSWORD);

	/* DB가 open되지 않았을경우, 5회까지 연결시도 */
	for(int i=0;!db.isOpen() && i<5;i++)
	{
		qDebug("Try DB Open...");
		db.open();
		/* 5회 모두 연결에 실패했을 경우 */
		//// 5회 시도 안내문 추가 필요
		if(i==4&&!db.isOpen())
		{
			QMessageBox msgBox;
			msgBox.setText("DB Connection Failure !");
			msgBox.exec();
			// 정상작동 체크 -> 프로그램 종료
			this->close();
			return;
		}
	}

	connect(ui.loginButton,SIGNAL(clicked()),this,SLOT(login()));	// 로그인 버튼 누르면, login() 실행
	connect(ui.registerButton,SIGNAL(clicked()),this,SLOT(createRegisterDialog()));
	connect(ui.forgotIdPwButton,SIGNAL(clicked()),this,SLOT(createForgotIdPwDialog()));

	connect(ui.action_Quit,SIGNAL(triggered()),this,SLOT(close()));

}

LoginWindow::~LoginWindow(){qDebug("~LoginWindow()");}

bool LoginWindow::checkValid(QString id)
{
	/* SQL Injection 예방을 위해, id 유효성 검사 */
	if(id.contains("'")||id.contains("--")||id.contains("/")||id.contains(";")||id.contains("*"))
	{
		qDebug(" include something wrong character!");
		return false;
	}
	return true;
}

void LoginWindow::login()
{
	ui.loginButton->setDisabled(true);
	ui.idLineEdit->setDisabled(true);
	ui.pwLineEdit->setDisabled(true);
	if(checkValid(ui.idLineEdit->text()))
	{
		QSqlQuery query;
		if(ui.userRadioButton->isChecked())
		{
			qDebug()<<"SELECT * from user_table where id=\'"+ui.idLineEdit->text()+"\'";
			/* Prepared Statement 이용 */
			query.prepare("SELECT * from user_table where id=\'"+ui.idLineEdit->text()+"\'");
		}
		else
		{
			qDebug()<<"SELECT * from technician_table where id=\'"+ui.idLineEdit->text()+"\'";
			/* Prepared Statement 이용 */
			query.prepare("SELECT * from technician_table where id=\'"+ui.idLineEdit->text()+"\'");
		}
		if( !query.exec() )
			qDebug() << query.lastError();
		query.next();
		if(query.value(2).toString()==ui.pwLineEdit->text()&&ui.pwLineEdit->text().length()>0)
		{
			//ID , PW 공백일때 추가해줘야
			qDebug("password correct");
			if(ui.userRadioButton->isChecked())
				createUserWindow();
			else
				createTechnicianWindow();
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText(" Please Check Your ID/PW ");
			msgBox.exec();
		}
	}
	ui.loginButton->setEnabled(true);
	ui.idLineEdit->setEnabled(true);
	ui.pwLineEdit->setEnabled(true);
}

void LoginWindow::createUserWindow()
{
	UserWindow *userWindow=new UserWindow(this);
	userWindow->show();
}

void LoginWindow::createTechnicianWindow()
{
	TechnicianWindow *technicianWindow=new TechnicianWindow(this);
	technicianWindow->show();
}

void LoginWindow::createRegisterDialog()
{
	RegisterDialog *registerDialog=new RegisterDialog(db);
	registerDialog->show();
}

void LoginWindow::createForgotIdPwDialog()
{
	ForgotIdPwDialog *forgotIdPwDialog=new ForgotIdPwDialog(db);
	forgotIdPwDialog->show();
}