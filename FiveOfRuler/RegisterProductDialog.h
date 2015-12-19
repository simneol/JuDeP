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
