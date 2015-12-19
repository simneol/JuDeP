#ifndef REQUESTPRODUCT_H
#define REQUESTPRODUCT_H

#include <QtWidgets/QDialog>

#include <QDialog>
#include <QMessageBox>

#include "User.h"
#include "ui_RequestProduct.h"

// 문주원 2014112022
// 용도 : 사용자의 제품이 수리가 필요할 경우 사용하는 클래스이다.
class RequestProduct : public QDialog
{
	Q_OBJECT

public:
	RequestProduct(QWidget *parent = 0, User* user = NULL);
	~RequestProduct();
	void pushCombobox();

private:
	Ui::RequestProduct ui;
	User* user;

signals:
	private slots :
		void write();
		void closeRequest();
		void on_pushButton_clicked();
};

#endif // REQUESTPRODUCT_H
