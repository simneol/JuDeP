#include "UserWindow.h"

#include <QtCore/QDebug>

#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QMessageBox>

UserWindow::UserWindow(QMainWindow* prevWindow,QWidget *parent)
	: QMainWindow(parent)
{		
	ui.setupUi(this);
}

UserWindow::~UserWindow(){qDebug("~UserWindow()");}