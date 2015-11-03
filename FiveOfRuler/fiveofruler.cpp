#include "fiveofruler.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

#include <QtWidgets/QMessageBox>
#include <QtSql/QSqlDataBase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

#include <QtCore/QDebug>

FiveOfRuler::FiveOfRuler(int id,QWidget *parent)
	: QMainWindow(parent)
{
	QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("192.168.1.171");
	db.setDatabaseName("fiveofruler");
	db.setUserName("fiveofruler");
	db.setPassword("papznye54rw5wKBy");

	bool ok=db.open();
	QSqlQuery query;
	query.prepare("SELECT * from user_table");
	ui.setupUi(this);
	switch(id)
	{
	case 0:
		setFixedSize(400,250);
		idLabel=new QLabel(" Your ID ",this);
		idLineEdit=new QLineEdit(this);
		pwLabel=new QLabel(" Your PW ",this);
		pwLineEdit=new QLineEdit(this);
		pwLineEdit->setEchoMode(QLineEdit::Password);

		loginButton=new QPushButton("Login",this);
		QObject::connect(loginButton,SIGNAL(clicked()),this,SLOT(changeText()));

		te =new QTextEdit(this);
		te->setGeometry(20,100,300,100);
		if( !query.exec() )
			qDebug() << query.lastError();
		else
		{
			qDebug("Selected!");
			while(query.next())
			{
				QSqlRecord rec=query.record();
				for( int c=0; c<rec.count(); c++ )
					qDebug()<<query.value(c).toString();
				te->setText(query.value(0).toString()+"kk");
			}
		}
		//		te->setText(QSqlDatabase::drivers()[3]);
		//		QObject::connect(loginButton,SIGNAL(clicked()),

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

		break;


	}
}

FiveOfRuler::~FiveOfRuler()
{

}

void FiveOfRuler::changeText()
{
	te->setText("Wow! DB is successfully loaded !");
}