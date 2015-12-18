#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QtWidgets/QMainWindow>

#include "User.h"
#include "UserManager.h"
#include "ui_UserWindow.h"

class UserWindow : public QMainWindow
{
	Q_OBJECT

public:
	UserWindow(QWidget *parent = 0, Info* userInfo = NULL);
	~UserWindow();

private:
	Ui::UserWindow ui;
	UserManager *userManager;

	User *userStatic;

	QString care, price;

	QStringListModel *model;

	void showData();

signals:
	private slots:
		void onClickListItem(const QModelIndex &index);
		void newWindow();
};

#endif // USERWINDOW_H
