#include "TechnicianWindow.h"
#include "WindowManager.h"
#include <QtCore/QDebug>

TechnicianWindow::TechnicianWindow(QWidget *parent)
	: QMainWindow(parent)
{		
	ui.setupUi(this);
	
	connect(ui.action_Logout,
		SIGNAL(triggered()),
		this,
		SLOT(slotLogout()));

	connect(ui.btn_QnA,
		SIGNAL(clicked()),
		this,
		SLOT(slotOpenQuestionReplyWindow()));
}

TechnicianWindow::~TechnicianWindow(){qDebug("~TechnicianWindow()");}

void TechnicianWindow::slotLogout()
{
	WindowManager::openWindow("LoginWindow");
	WindowManager::closeWindow("TechnicianWindow");
}

void TechnicianWindow::slotOpenQuestionReplyWindow()
{
	OpenDialog("QuestionReply");
}

#pragma region DialogControll

void TechnicianWindow::OpenDialog(QString str)
{
	QDialog *target = NULL;
	target = dialogs.value(str);
	if(target == NULL)
	{
		qDebug("Open-New");
		if(str == "QuestionReply")
		{
			target = new QuestionReplyDialog();
		}
		dialogs.insert(str, target);
		target->show();
		target->hasFocus();
	}
	else
	{
		qDebug("Open-AlreadyHave");
		target->show();
		target->hasFocus();
	}

	this->hide();
}

void TechnicianWindow::CloseAllDialog()
{
	qDebug("Close-");
	foreach (QDialog* dialog, dialogs)
	{
		dialog->hide();
	}

	this->hasFocus();
}
#pragma endregion