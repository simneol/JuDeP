#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QtWidgets/QMainWindow>

#include "User.h"
#include "UserManager.h"
#include "ui_UserWindow.h"

// 사용자에 대한 창의 처리를 하는 클래스이다.
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
