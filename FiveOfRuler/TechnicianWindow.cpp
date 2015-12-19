/***************************************
/ 작성자 : 박성수
/ 클래스 : TechnicianWindow
/ 용  도 : Technician User의 기능 모음 Window
/***************************************/
#include "TechnicianWindow.h"

#include "WindowManager.h"
#include "TechQNASelectDialog.h"
#include "RegisterProductDialog.h"
#include "ProductSearchDialog.h"
#include "ComponentSearchDialog.h"
#include <QtCore/QDebug>

TechnicianWindow::TechnicianWindow(QWidget *parent)
	: QMainWindow(parent)
{		
	ui.setupUi(this);
	if(((TechUser *)InstanceOfUserManager.getInfo())->getType() == false)
	{
		ui.btn_productImport->hide();
		ui.btn_Assign->hide();
		ui.btn_compoImport->hide();
	}
	connect(ui.action_Logout,
		SIGNAL(triggered()),
		this,
		SLOT(slotLogout()));

	connect(ui.btn_QnA,
		SIGNAL(clicked()),
		this,
		SLOT(slotOpenQuestionReplyWindow()));

	connect(ui.btn_RegiterProduct,
		SIGNAL(clicked()),
		this,
		SLOT(slotOpenRegisterProductDialog()));

	connect(ui.btn_compoSearch,
		SIGNAL(clicked()),
		this,
		SLOT(slotOpenComponentSearchDialog()));

	connect(ui.btn_productSearch,
		SIGNAL(clicked()),
		this,
		SLOT(slotOpenProductSearchDialog()));
}

TechnicianWindow::~TechnicianWindow(){qDebug("~TechnicianWindow()");}

void TechnicianWindow::slotLogout()
{
	WindowManager::slotOpenWindow("LoginWindow");
	WindowManager::slotCloseWindow("TechnicianWindow");
}

void TechnicianWindow::slotOpenRegisterProductDialog()
{
	QDialog *target = OpenDialog("RegisterProduct");
}

void TechnicianWindow::slotOpenComponentSearchDialog()
{
	QDialog *target = OpenDialog("ComponentSearch");
}

void TechnicianWindow::slotOpenProductSearchDialog()
{
	QDialog *target = OpenDialog("ProductSearch");
}

void TechnicianWindow::slotOpenQuestionReplyWindow()
{
	QDialog *target = OpenDialog("TechQNASelectDialog");
	TechQNASelectDialog *target2 = (TechQNASelectDialog *)target;
}

void TechnicianWindow::OpenQuestionReplyDialog(int val)
{
	CloseAllDialog();
	QuestionReplyDialog *target = (QuestionReplyDialog *)OpenDialog("QuestionReplyDialog");
	target->setup(val);

}
#pragma region DialogControll

QDialog* TechnicianWindow::OpenDialog(QString str)
{
	QDialog *target = NULL;
	target = dialogs.value(str);
	if(target == NULL)
	{
		qDebug("Open-New");
		
		if(str == "ComponentSearch")
		{
			target = new ComponentSearchDailog();
		}
		else if(str == "ProductSearch")
		{
			target = new ProductSearchDialog();
		}
		else if(str == "QuestionReplyDialog")
		{
			target = new QuestionReplyDialog();
		}
		else if(str == "TechQNASelectDialog")
		{
			target = new TechQNASelectDialog();
		}
		else if(str == "RegisterProduct")
		{
			target = new RegisterProductDialog();
		}
		dialogs.insert(str, target);
	}
	else
	{
		qDebug("Open-AlreadyHave");
	}
	target->show();
	target->hasFocus();

	return target;
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