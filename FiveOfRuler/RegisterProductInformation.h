#ifndef REGISTERPRODUCTINFORMATION_H
#define REGISTERPRODUCTINFORMATION_H

#include <QtWidgets/QDialog>

#include "User.h"
#include "ui_RegisterProductInformation.h"

class RegisterProductInformation : public QDialog
{
	Q_OBJECT

public:
	RegisterProductInformation(QWidget *parent = 0, User* user = NULL);
	~RegisterProductInformation();

private:
	Ui::RegisterProductInformation ui;
	User* user;

signals:
	private slots :
		void write();
		void closeRegister();
};

#endif // REGISTERPRODUCTINFORMATION_H
