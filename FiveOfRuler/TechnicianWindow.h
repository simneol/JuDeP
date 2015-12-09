#ifndef TECHNICIANWINDOW_H
#define TECHNICIANWINDOW_H

#include <QtWidgets/QMainWindow>

#include "ui_TechnicianWindow.h"

class TechnicianWindow : public QMainWindow
{
	Q_OBJECT

public:
	TechnicianWindow(QWidget *parent = 0);
	~TechnicianWindow();

private:
	Ui::TechnicianWindow ui;

signals:
	private slots:
		void slotLogout();
};

#endif // TECHNICIANWINDOW_H
