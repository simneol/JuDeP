/***************************************
/ 작성자 : 박성수
/ 클래스 : RegisterProductDialog
/ 용  도 : 프로덕트를 등록하는 다이어로그
/***************************************/
#ifndef	RegisterProductDialog_H
#define RegisterProductDialog_H

#include <QtWidgets/QDialog>

#include "ui_RegisterProduct.h"

// 
class RegisterProductDialog : public QDialog
{
	Q_OBJECT

public:
	RegisterProductDialog(QWidget *parent = 0);
	~RegisterProductDialog();
private:
	Ui::RegisterProductDialog ui;
signals:
	private slots:
};

#endif
