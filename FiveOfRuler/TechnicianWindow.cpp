#include "TechnicianWindow.h"

#include "WindowManager.h"
#include "TechQNASelectDialog.h"
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
	WindowManager::slotOpenWindow("LoginWindow");
	WindowManager::slotCloseWindow("TechnicianWindow");
}

void TechnicianWindow::slotOpenQuestionReplyWindow()
{
	QDialog *target = OpenDialog("TechQNASelectDialog");
	TechQNASelectDialog *target2 = (TechQNASelectDialog *)target;
}

void TechnicianWindow::OpenQuestionReplyDialog(int val)
{
	CloseAllDialog();
	OpenDialog("QuestionReply");
}
#pragma region DialogControll

QDialog* TechnicianWindow::OpenDialog(QString str)
{
	QDialog *target = NULL;
	target = dialogs.value(str);
	if(target == NULL)
	{
		qDebug("Open-New");
		if(str == "QuestionReplyDialog")
		{
			target = new QuestionReplyDialog();
		}
		else if(str == "TechQNASelectDialog")
		{
			target = new TechQNASelectDialog();
		}
		dialogs.insert(str, target);
	}
	else
	{
		qDebug("Open-AlreadyHave");
	}
	target->show();
	return NULL;
	// this->hide();
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