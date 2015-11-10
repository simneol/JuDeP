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
	ui.setupUi(this);	// Qt Desinger�� ������ Ui���� �����ϴ� �Լ�

	/* �����ڿ��� ��� ���� db �ʱ�ȭ */
	db=QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(DB_HOSTNAME);
	db.setPort(DB_PORT);
	db.setDatabaseName(DB_DATABASENAME);
	db.setUserName(DB_USERNAME);
	db.setPassword(DB_PASSWORD);

	connect(ui.loginButton,SIGNAL(clicked()),this,SLOT(login()));	// �α��� ��ư ������, login() ����
	/* �������� login��, loginSuccess() signal�� ����. �̴� ���� Ŭ�������� createUserWindow()ȣ�� */
	connect(this,SIGNAL(loginSuccess()),this,SLOT(createUserWindow()));
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
	ui.loginButton->setDisabled(true);
	ui.idLineEdit->setDisabled(true);
	ui.pwLineEdit->setDisabled(true);
	if(checkValid(ui.idLineEdit->text()))
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
				ui.loginButton->setEnabled(true);
				ui.idLineEdit->setEnabled(true);
				ui.pwLineEdit->setEnabled(true);
				return;
			}
		}
		QSqlQuery query;
		qDebug()<<"SELECT * from user_table where id=\'"+ui.idLineEdit->text()+"\'";
		/* Prepared Statement �̿� */
		query.prepare("SELECT * from user_table where id=\'"+ui.idLineEdit->text()+"\'");
		if( !query.exec() )
			qDebug() << query.lastError();
		query.next();
		if(query.value(2).toString()==ui.pwLineEdit->text())
		{
			//ID , PW �����϶� �߰������
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