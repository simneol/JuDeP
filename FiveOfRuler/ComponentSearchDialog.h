/***************************************
/ 작성자 : 박성수
/ 클래스 : ComponentSearchDailog
/ 용  도 : 부품을 찾는 다이어로그
/***************************************/
#ifndef COMPOENTSEARCHDAILOG_H
#define COMPOENTSEARCHDAILOG_H

#include <QtWidgets/QDialog>

#include "ui_ComponentSearch.h"

class ComponentSearchDailog : public QDialog
{
	Q_OBJECT

public:
	ComponentSearchDailog(QWidget *parent = 0);
	~ComponentSearchDailog();

private:
	Ui::ComponentSearchDailog ui;
signals:
	private slots:
};

#endif // REGISTERDIALOG_H