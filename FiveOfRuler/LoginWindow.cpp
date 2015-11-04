#include "LoginWindow.h"
#include "UserWindow.h"

#include <QtCore/QDebug>
#include <QtCore/QThread>

#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QMessageBox>

#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{		
	ui.setupUi(this);	// 모르는 함수, but ui들보다 먼저 실행되야 정상작동

	/* 생성자에서 멤버 변수 db 초기화 */
	db=QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("122.37.76.152");
	db.setPort(9876);
	db.setDatabaseName("fiveofruler");
	db.setUserName("fiveofruler");
	db.setPassword("papznye54rw5wKBy");

	/* GUI 부분 */
	setFixedSize(400,250);	// 크기 변경 금지
	idLabel=new QLabel(" Your ID ",this);
	idLineEdit=new QLineEdit(this);	// 입력 창
	pwLabel=new QLabel(" Your PW ",this);
	pwLineEdit=new QLineEdit(this);
	pwLineEdit->setEchoMode(QLineEdit::Password);	// 비밀번호 모자이크 처리

	loginButton=new QPushButton("Login",this);
	QObject::connect(loginButton,SIGNAL(clicked()),this,SLOT(login()));	// 로그인 버튼 누르면, login() 실행
	/* 정상적인 login시, loginSuccess() signal을 보냄. 이는 같은 클래스에서 createUserWindow()호출 */
	QObject::connect(this,SIGNAL(loginSuccess()),this,SLOT(createUserWindow()));

	/* Widget들의 위치 및 크기 설정. Layout클래스로 위치 할당하는 방법으로 변경할 예정 */
	idLabel->setGeometry(20,30,100,20);
	idLineEdit->setGeometry(120,30,100,20);
	pwLabel->setGeometry(20,60,100,20);
	pwLineEdit->setGeometry(120,60,100,20);

	loginButton->setGeometry(230,30,70,50);
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
	loginButton->setDisabled(true);
	idLineEdit->setDisabled(true);
	pwLineEdit->setDisabled(true);
	if(checkValid(idLineEdit->text()))
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
				loginButton->setEnabled(true);
				idLineEdit->setEnabled(true);
				pwLineEdit->setEnabled(true);
				return;
			}
		}
		QSqlQuery query;
		qDebug()<<"SELECT * from user_table where id=\'"+idLineEdit->text()+"\'";
		/* Prepared Statement 이용 */
		query.prepare("SELECT * from user_table where id=\'"+idLineEdit->text()+"\'");
		if( !query.exec() )
			qDebug() << query.lastError();
		query.next();
		if(query.value(2).toString()==pwLineEdit->text())
		{
			qDebug("password correct");
			emit loginSuccess();
		}
	}
	loginButton->setEnabled(true);
	idLineEdit->setEnabled(true);
	pwLineEdit->setEnabled(true);
}

void LoginWindow::createUserWindow()
{
	UserWindow *userwindow=new UserWindow(this);
	userwindow->show();
	this->hide();
}