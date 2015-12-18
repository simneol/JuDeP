#ifndef TECHNICIANWINDOW_H
#define TECHNICIANWINDOW_H

#include <QtWidgets/QMainWindow>

#include "ui_TechnicianWindow.h"
#include "QuestionReplyDialog.h"

class TechnicianWindow : public QMainWindow
{
	Q_OBJECT

public:
	TechnicianWindow(QWidget *parent = 0);
	~TechnicianWindow();
	QuestionReplyDialog *targetQuestionReplyDialog;
private:
	Ui::TechnicianWindow ui;

signals:
	private slots:
		void slotLogout();
		void slotOpenQuestionReplyWindow();
};

#endif // TECHNICIANWINDOW_H