#ifndef FORGOTIDPWDIALOG_H
#define FORGOTIDPWDIALOG_H
/* 아이디 및 비밀번호 찾기 창 */
#include <QtWidgets/QDialog>

#include "ui_ForgotIdPwDialog.h"

class ForgotIdPwDialog : public QDialog
{
	Q_OBJECT

public:
	ForgotIdPwDialog(QWidget *parent = 0);
	~ForgotIdPwDialog();

private:
	Ui::ForgotIdPwDialog ui;

signals:
	private slots:
		void slotFind();
		void slotIdshow();
		void slotPwshow();
};

#endif // FORGOTIDPWDIALOGDIALOG_H