#ifndef QNASEEDIALOG_H
#define QNASEEDIALOG_H

#include <QtWidgets/QDialog>

#include "User.h"
#include "ui_QNASeeDialog.h"

// 문주원 2014112022
// 용도 : Qna의 정보를 보는 클래스이다.
class QNASeeDialog : public QDialog
{
	Q_OBJECT

public:
	QNASeeDialog(QWidget *parent = 0, User* user = NULL);
	~QNASeeDialog();

private:
	Ui::QNASeeDialog ui;
	User* user;

signals:
	private slots :
		void write();
		void closeQNA();
};

#endif // QNASEEDIALOG_H
