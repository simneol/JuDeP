#include "UserWindow.h"

#include <QtCore/QDebug>

#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QMessageBox>

UserWindow::UserWindow(QMainWindow* prevWindow,QWidget *parent)
	: QMainWindow(parent)
{		
	ui.setupUi(this);

	setFixedSize(600,850);
	idLabel=new QLabel(" Welcome ! ",this);

	idLabel->setGeometry(20,30,100,20);
}

UserWindow::~UserWindow(){qDebug("~UserWindow()");}