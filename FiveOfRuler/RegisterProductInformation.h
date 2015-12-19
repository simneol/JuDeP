#ifndef REGISTERPRODUCTINFORMATION_H
#define REGISTERPRODUCTINFORMATION_H

#include <QtWidgets/QDialog>

#include "User.h"
#include "ui_RegisterProductInformation.h"

// 사용자가 자신의 제품을 등록해서 그 제품을 가지고 여러 사용을 하는 클래스이다.
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
