#ifndef FORGOTIDPWDIALOGDIALOG_H
#define FORGOTIDPWDIALOGDIALOG_H

#include <QtWidgets/QDialog>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

#include <QtSql/QSqlDataBase>

#include "ui_ForgotIdPwDialog.h"

class ForgotIdPwDialog : public QDialog
{
	Q_OBJECT

public:
	ForgotIdPwDialog(QSqlDatabase db,QWidget *parent = 0);
	~ForgotIdPwDialog();

private:
	Ui::ForgotIdPwDialog ui;
	QSqlDatabase db;

signals:
	private slots:
		void find();
		void idshow();
		void pwshow();
};

#endif // FORGOTIDPWDIALOGDIALOG_H
