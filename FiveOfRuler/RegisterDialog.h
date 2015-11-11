#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QtWidgets/QDialog>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

#include <QtSql/QSqlDataBase>

#include "ui_RegisterDialog.h"

class RegisterDialog : public QDialog
{
	Q_OBJECT

public:
	RegisterDialog(QSqlDatabase db,QWidget *parent = 0);
	~RegisterDialog();

private:
	Ui::RegisterDialog ui;
	QSqlDatabase db;

signals:
	private slots:
		void signup();
};

#endif // REGISTERDIALOG_H
