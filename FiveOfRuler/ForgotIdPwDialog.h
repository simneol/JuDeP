#ifndef FORGOTIDPWDIALOG_H
#define FORGOTIDPWDIALOG_H

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
		void find();
		void idshow();
		void pwshow();
};

#endif // FORGOTIDPWDIALOGDIALOG_H
