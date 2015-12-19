#ifndef QNASEEDIALOG_H
#define QNASEEDIALOG_H

#include <QtWidgets/QDialog>

#include "User.h"
#include "ui_QNASeeDialog.h"

// ���ֿ� 2014112022
// �뵵 : Qna�� ������ ���� Ŭ�����̴�.
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
