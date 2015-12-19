#ifndef PRODUCTSEARCHDAILOG_H
#define PRODUCTSEARCHDAILOG_H

#include <QtWidgets/QDialog>

#include "ui_ProductSearch.h"

class ProductSearchDialog : public QDialog
{
	Q_OBJECT

public:
	ProductSearchDialog(QWidget *parent = 0);
	~ProductSearchDialog();

private:
	Ui::ProductSearchDialog ui;
signals:
	private slots:
};

#endif // REGISTERDIALOG_H