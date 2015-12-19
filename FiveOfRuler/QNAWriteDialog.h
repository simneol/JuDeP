#ifndef QNAWRITEDIALOG_H
#define QNAWRITEDIALOG_H

#include <QtWidgets/QDialog>

#include "User.h"
#include "ui_QNAWriteDialog.h"

// ���ֿ� 2014112022
// �뵵 : Qna�� ������ ���� Ŭ�����̴�.
// Qna�� ����� �׿����� ������ �� �� �ִ�.
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
