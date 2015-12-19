#ifndef QNAWRITEDIALOG_H
#define QNAWRITEDIALOG_H

#include <QtWidgets/QDialog>

#include "User.h"
#include "ui_QNAWriteDialog.h"

// 문주원 2014112022
// 용도 : Qna의 정보를 쓰는 클래스이다.
// Qna의 내용과 그에대한 내용을 알 수 있다.
class QNAWriteDialog : public QDialog
{
	Q_OBJECT

public:
	QNAWriteDialog(QWidget *parent = 0,User* user=NULL);
	~QNAWriteDialog();

private:
	Ui::QNAWriteDialog ui;
	User* user;

signals:
	private slots:
		void write();
		void closeQNA();
};

#endif // QNAWRITEDIALOG_H
