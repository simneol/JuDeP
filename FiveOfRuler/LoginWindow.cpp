#include "LoginWindow.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

#include <QtWidgets/QMessageBox>

#include <QtCore/QDebug>
#include <QtCore/QThread>

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{		
	db=QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("122.37.76.152");
	db.setPort(9876);
	db.setDatabaseName("fiveofruler");
	db.setUserName("fiveofruler");
	db.setPassword("papznye54rw5wKBy");

	ui.setupUi(this);
	setFixedSize(400,250);
	idLabel=new QLabel(" Your ID ",this);
	idLineEdit=new QLineEdit(this);
	pwLabel=new QLabel(" Your PW ",this);
	pwLineEdit=new QLineEdit(this);
	pwLineEdit->setEchoMode(QLineEdit::Password);

	loginButton=new QPushButton("Login",this);
	QObject::connect(loginButton,SIGNAL(clicked()),this,SLOT(login()));

	te =new QTextEdit(this);
	te->setGeometry(20,100,300,100);
///			QSqlRecord rec=query.record();
			//	for( int c=0; c<rec.count(); c++ )

	/*	QHBoxLayout *idLayout=new QHBoxLayout;
	idLayout->addWidget(idLabel);
	idLayout->addWidget(idLineEdit);

	QHBoxLayout *pwLayout=new QHBoxLayout;
	pwLayout->addWidget(pwLabel);
	pwLayout->addWidget(pwLineEdit);

	QVBoxLayout *leftLayout=new QVBoxLayout;
	leftLayout->addLayout(idLayout);
	leftLayout->addLayout(pwLayout);*/

	//		QVBoxLayout *topLeftLayout=new QVBoxLayout;

	//		QHBoxLayout *mainLayout=new QHBoxLayout;
	//		mainLayout->addLayout(leftLayout);
	//		setLayout(leftLayout);

	idLabel->setGeometry(20,30,100,20);
	idLineEdit->setGeometry(120,30,100,20);
	pwLabel->setGeometry(20,60,100,20);
	pwLineEdit->setGeometry(120,60,100,20);

	loginButton->setGeometry(230,30,70,50);
}

LoginWindow::~LoginWindow()
{

}

bool LoginWindow::checkValid(QString id)
{
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
//	WaitWindow *waitWindow=new WaitWindow();
//	waitWindow->show();
	QLabel *nl = new QLabel(" Please Wait ... ");
	nl->setFixedSize(200,70);
	nl->show();
	if(checkValid(idLineEdit->text()))
	{
		if(!db.isOpen())
		{
			qDebug("call open()");
			db.open();
		}
		//open실패시 대처
		QSqlQuery query;
		qDebug()<<"SELECT * from user_table where id=\'"+idLineEdit->text()+"\'";
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
//	waitWindow->close();
//	delete waitWindow;
	loginButton->setEnabled(true);
	idLineEdit->setEnabled(true);
	pwLineEdit->setEnabled(true);
}

WaitWindow::WaitWindow(QWidget *parent)
	: QMainWindow(parent)
{		
	//메모리할당어떻게?
	ui.setupUi(this);
	setWindowFlags(Qt::WindowTitleHint);
	setFixedSize(400,250);
	waitLabel=new QLabel(" Wait ... ",this);
	waitLabel->setGeometry(20,30,100,20);
	
}
WaitWindow::~WaitWindow()
{

}