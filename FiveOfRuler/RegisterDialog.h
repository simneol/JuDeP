#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QtWidgets/QDialog>

#include "ui_RegisterDialog.h"

class RegisterDialog : public QDialog
{
	Q_OBJECT

public:
	RegisterDialog(QWidget *parent = 0);
	~RegisterDialog();

private:
	Ui::RegisterDialog ui;
	bool is_idDuplicated;
signals:
	private slots:
		void slotSignup();
		void slotInitDuplication();
		void slotCheckIdDuplication();
};

#endif // REGISTERDIALOG_H