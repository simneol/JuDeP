#include "TechnicianWindow.h"

#include <QtCore/QDebug>

#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QMessageBox>

TechnicianWindow::TechnicianWindow(QMainWindow* prevWindow,QWidget *parent)
	: QMainWindow(parent)
{		
	if(prevWindow!=NULL)
		prevWindow->close();
	ui.setupUi(this);
}

TechnicianWindow::~TechnicianWindow(){qDebug("~TechnicianWindow()");}