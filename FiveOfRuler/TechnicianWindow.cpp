#include "TechnicianWindow.h"
#include "TechQNASelectDialog.h"

#include "WindowManager.h"
#include <QtCore/QDebug>

TechnicianWindow::TechnicianWindow(QWidget *parent)
	: QMainWindow(parent)
{		
	ui.setupUi(this);
	dialogs = new QMap<QString, QDialog*>();
	dialogs->clear();

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
	OpenDialog("TechQNASelectDialog");
}

void TechnicianWindow::OpenQuestionReplyDialog(int val)
{
	QDialog *target = nullptr;
	target = (*dialogs)["TechQNASelectDialog"];
	qDebug("go");
	OpenDialog("QuestionReplyDialog");
}
#pragma region DialogControll

void TechnicianWindow::OpenDialog(QString str)
{
	QDialog *target = NULL;
	target = dialogs->value(str);
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
		dialogs->insert(str, target);
		target->show();
		target->hasFocus();
	}
	else
	{
		qDebug("Open-AlreadyHave");
		target->show();
		target->hasFocus();
	}

	// this->hide();
}

void TechnicianWindow::CloseAllDialog()
{
	if(dialogs->isEmpty() == false)
	{

		foreach(QString key, dialogs->keys())
		{
			((QDialog*)dialogs->value(key))->hide();
		}

	}
	this->hasFocus();
}
#pragma endregion