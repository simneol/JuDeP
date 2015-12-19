#ifndef	QUESTIONREPLYDIALOG_H
#define QUESTIONREPLYDIALOG_H

#include <QtWidgets/QDialog>

#include "ui_QuestionReplyDialog.h"

class QuestionReplyDialog : public QDialog
{
	Q_OBJECT

public:
	QuestionReplyDialog(QWidget *parent = 0);
	~QuestionReplyDialog();
	void setup(int val);

private:
	Ui::QuestionReplyDialog ui;
signals:
	private slots:
		void slotSubmit();
		void slotCancle();
};

#endif
