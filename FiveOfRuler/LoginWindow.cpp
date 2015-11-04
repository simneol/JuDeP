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
	ui.setupUi(this);	// �𸣴� �Լ�, but ui�麸�� ���� ����Ǿ� �����۵�

	/* �����ڿ��� ��� ���� db �ʱ�ȭ */
	db=QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("122.37.76.152");
	db.setPort(9876);
	db.setDatabaseName("fiveofruler");
	db.setUserName("fiveofruler");
	db.setPassword("papznye54rw5wKBy");

	/* GUI �κ� */
	setFixedSize(400,250);	// ũ�� ���� ����
	idLabel=new QLabel(" Your ID ",this);
	idLineEdit=new QLineEdit(this);	// �Է� â
	pwLabel=new QLabel(" Your PW ",this);
	pwLineEdit=new QLineEdit(this);
	pwLineEdit->setEchoMode(QLineEdit::Password);	// ��й�ȣ ������ũ ó��

	loginButton=new QPushButton("Login",this);
	QObject::connect(loginButton,SIGNAL(clicked()),this,SLOT(login()));	// �α��� ��ư ������, login() ����
	/* �������� login��, loginSuccess() signal�� ����. �̴� ���� Ŭ�������� createUserWindow()ȣ�� */
	QObject::connect(this,SIGNAL(loginSuccess()),this,SLOT(createUserWindow()));

	/* Widget���� ��ġ �� ũ�� ����. LayoutŬ������ ��ġ �Ҵ��ϴ� ������� ������ ���� */
	idLabel->setGeometry(20,30,100,20);
	idLineEdit->setGeometry(120,30,100,20);
	pwLabel->setGeometry(20,60,100,20);
	pwLineEdit->setGeometry(120,60,100,20);

	loginButton->setGeometry(230,30,70,50);
}

LoginWindow::~LoginWindow(){qDebug("~LoginWindow()");}

bool LoginWindow::checkValid(QString id)
{
	/* SQL Injection ������ ����, id ��ȿ�� �˻� */
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
		/* DB�� open���� �ʾ������, 5ȸ���� ����õ� */
		for(int i=0;!db.isOpen() && i<5;i++)
		{
			qDebug("Try DB Open...");
			db.open();
			/* 5ȸ ��� ���ῡ �������� ��� */
			//// 5ȸ �õ� �ȳ��� �߰� �ʿ�
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
		/* Prepared Statement �̿� */
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