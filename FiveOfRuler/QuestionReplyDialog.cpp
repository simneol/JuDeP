#include "QuestionReplyDialog.h"
#include "FiveOfRulerDB.h"


#include <QtCore/QDebug>
#include <QtCore/QVector>
#include <QString>
#include <QtWidgets/QMessageBox>

QuestionReplyDialog::QuestionReplyDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	// submit button connect
	connect(ui.btn_Submit,
		SIGNAL(clicked()),
		this,
		SLOT(slotSubmit()));

	// cancle button connect
	connect(ui.btn_Cancle,
		SIGNAL(clicked()),
		this,
		SLOT(slotCancle()));
}


QuestionReplyDialog::~QuestionReplyDialog()
{
	qDebug("~QuestionReplyDialog()");
}

void QuestionReplyDialog::setup(int val)
{
	num = val;
	QString index = QString::number(num);
	
	QSqlQuery *query = FiveOfRulerDB::select("qna", "postIndex", index);
	ui.textEdit_Question->setText(query->value(3).toString());
	ui.label_QuestionerID->setText(query->value(1).toString());

}

void QuestionReplyDialog::write()
{
	
}
void QuestionReplyDialog::slotSubmit()
{
	QSqlQuery *query = FiveOfRulerDB::select("qna", "postIndex", QString::number(num));

	QVector<QPair<QString,QString> > data;
	Info* user = (Info *)InstanceOfUserManager.getInfo();
	QString id = user->getId();
	data.push_back(qMakePair<QString,QString>("writer", id));
	QString title = "Re : " + query->value(2).toString();
	data.push_back(qMakePair<QString,QString>("title", title));
	data.push_back(qMakePair<QString,QString>("content",ui.textEdit_Answer->toPlainText()));
	data.push_back(qMakePair<QString,QString>("isReply","1"));

	//QSqlQuery *query2 = FiveOfRulerDB::insert("qna", data);
	if(FiveOfRulerDB::insert("qna", data) != NULL)
	{
		qDebug() << "Success";
	}

	this->close();
}

void QuestionReplyDialog::slotCancle()
{
	this->close();
}