#ifndef REQUESTPRODUCT_H
#define REQUESTPRODUCT_H

#include <QtWidgets/QDialog>

#include "User.h"
#include "ui_RequestProduct.h"

class RequestProduct : public QDialog
{
	Q_OBJECT

public:
	RequestProduct(QWidget *parent = 0, User* user = NULL);
	~RequestProduct();

private:
	Ui::RequestProduct ui;
	User* user;

signals:
	private slots :
		void write();
	void closeRequest();
};

#endif // REQUESTPRODUCT_H
