#ifndef	QUESTIONREPLYDIALOG_H
#define QUESTIONREPLYDIALOG_H

#include <QtWidgets/QDialog>

#include "ui_QuestionReplyDialog.h"
#include "UserInstanceManager.h"

class QuestionReplyDialog : public QDialog
{
	Q_OBJECT

public:
	QuestionReplyDialog(QWidget *parent = 0);
	~QuestionReplyDialog();
	void setup(int val);

private:
	Ui::QuestionReplyDialog ui;
	int num;
signals:
	private slots:
		void slotSubmit();
		void slotCancle();
		void write();
};

#endif
