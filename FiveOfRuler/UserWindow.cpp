#include "UserWindow.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

#include <QtWidgets/QMessageBox>

#include <QtCore/QDebug>

UserWindow::UserWindow(QWidget *parent)
	: QMainWindow(parent)
{		
	//db=QSqlDatabase::addDatabase("QMYSQL");
	//db.setHostName("122.37.76.152");
	//db.setPort(9876);
	//db.setDatabaseName("fiveofruler");
	//db.setUserName("fiveofruler");
	//db.setPassword("papznye54rw5wKBy");

	ui.setupUi(this);

	setFixedSize(600,850);
	idLabel=new QLabel(" Welcome ! ",this);

	te =new QTextEdit(this);
	te->setGeometry(20,100,300,100);

	idLabel->setGeometry(20,30,100,20);
}

UserWindow::~UserWindow()
{

}