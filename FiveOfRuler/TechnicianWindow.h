#ifndef TECHNICIANWINDOW_H
#define TECHNICIANWINDOW_H

#include <QtWidgets/QMainWindow>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

#include <QtSql/QSqlDataBase>

#include "ui_TechnicianWindow.h"

class TechnicianWindow : public QMainWindow
{
	Q_OBJECT

public:
	TechnicianWindow(QMainWindow* prevWindow=NULL,QWidget *parent = 0);
	~TechnicianWindow();

private:
	Ui::TechnicianWindow ui;

	QSqlDatabase db;

signals:
	private slots:
		void logout();
};

#endif // TECHNICIANWINDOW_H
