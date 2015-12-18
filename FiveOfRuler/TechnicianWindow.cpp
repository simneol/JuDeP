#include "TechnicianWindow.h"
#include "WindowManager.h"

#include <QtCore/QDebug>

TechnicianWindow::TechnicianWindow(QWidget *parent)
	: QMainWindow(parent)
{		
	ui.setupUi(this);
	targetQuestionReplyDialog = NULL;

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
	if(targetQuestionReplyDialog == NULL)
	{
		targetQuestionReplyDialog = new QuestionReplyDialog();
		targetQuestionReplyDialog->show();
		targetQuestionReplyDialog->hasFocus();
	}
	else
	{
		targetQuestionReplyDialog->show();
		targetQuestionReplyDialog->hasFocus();
	}

}