#ifndef TECHQNASELECTDIALOG_H
#define TECHQNASELECTDIALOG_H

#include <QtWidgets/QDialog>

#include "User.h"
#include "ui_techQNASelectDialog.h"

class TechQNASelectDialog : public QDialog
{
	Q_OBJECT

public:
	TechQNASelectDialog(QWidget *parent = 0, User* user = NULL);
	~TechQNASelectDialog();

private:
	Ui::TechQNASelectDialog ui;
	User* user;

signals:
	private slots :
		void write();
		void closeQNA();
};

#endif // QNASEEDIALOG_H
