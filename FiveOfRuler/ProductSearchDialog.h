/***************************************
/ �ۼ��� : �ڼ���
/ Ŭ���� : ProductSearchDialog
/ ��  �� : ��ǰ�� ã�� ���̾�α�
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
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : ������
	/ ��  �� : ��ü�� �����Ѵ�.
	/***************************************/
	ProductSearchDialog(QWidget *parent = 0);
	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : �Ҹ���
	/ ��  �� : ��ü�� �����Ѵ�.
	/***************************************/
	~ProductSearchDialog();

private:
	Ui::ProductSearchDialog ui;
signals:
	private slots:
};

#endif // REGISTERDIALOG_H