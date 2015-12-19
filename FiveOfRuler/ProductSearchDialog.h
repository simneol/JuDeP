/***************************************
/ 작성자 : 박성수
/ 클래스 : ProductSearchDialog
/ 용  도 : 제품을 찾는 다이어로그
/***************************************/
#ifndef PRODUCTSEARCHDAILOG_H
#define PRODUCTSEARCHDAILOG_H

#include <QtWidgets/QDialog>

#include "ui_ProductSearch.h"

class ProductSearchDialog : public QDialog
{
	Q_OBJECT

public:
	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 생성자
	/ 용  도 : 객체를 생성한다.
	/***************************************/
	ProductSearchDialog(QWidget *parent = 0);
	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 소멸자
	/ 용  도 : 객체를 제거한다.
	/***************************************/
	~ProductSearchDialog();

private:
	Ui::ProductSearchDialog ui;
signals:
	private slots:
};

#endif // REGISTERDIALOG_H