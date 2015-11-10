#include "LoginWindow.h"
#include "UserWindow.h"
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

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);	// Qt Desinger로 구성한 Ui들을 구성하는 함수

	/* 생성자에서 멤버 변수 db 초기화 */
	db=QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(DB_HOSTNAME);
	db.setPort(DB_PORT);
	db.setDatabaseName(DB_DATABASENAME);
	db.setUserName(DB_USERNAME);
	db.setPassword(DB_PASSWORD);

	connect(ui.loginButton,SIGNAL(clicked()),this,SLOT(login()));	// 로그인 버튼 누르면, login() 실행
	/* 정상적인 login시, loginSuccess() signal을 보냄. 이는 같은 클래스에서 createUserWindow()호출 */
	connect(this,SIGNAL(loginSuccess()),this,SLOT(createUserWindow()));
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
				ui.loginButton->setEnabled(true);
				ui.idLineEdit->setEnabled(true);
				ui.pwLineEdit->setEnabled(true);
				return;
			}
		}
		QSqlQuery query;
		qDebug()<<"SELECT * from user_table where id=\'"+ui.idLineEdit->text()+"\'";
		/* Prepared Statement 이용 */
		query.prepare("SELECT * from user_table where id=\'"+ui.idLineEdit->text()+"\'");
		if( !query.exec() )
			qDebug() << query.lastError();
		query.next();
		if(query.value(2).toString()==ui.pwLineEdit->text())
		{
			//ID , PW 공백일때 추가해줘야
			qDebug("password correct");
			emit loginSuccess();
		}
	}
	ui.loginButton->setEnabled(true);
	ui.idLineEdit->setEnabled(true);
	ui.pwLineEdit->setEnabled(true);
}

void LoginWindow::createUserWindow()
{
	UserWindow *userwindow=new UserWindow(this);
	userwindow->show();
	this->hide();
}