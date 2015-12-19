#ifndef REQUESTSHOW_H
#define REQUESTSHOW_H

#include <QtCore/QObject>

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>
#include <qlistview.h>
#include <qstandarditemmodel.h>
#include <QTableWidget.h>
#include <QMessageBox>

#include "User.h"
#include "ui_RequestShow.h"

// 문주원 2014112022
// 용도 : 수리를 등록한 제품에 관해 사용자가 그 정보를 볼 수 있는 클래스이다.
class RequestShow : public QDialog
{
	Q_OBJECT

public:
	explicit RequestShow(QWidget *parent = 0, User* user = NULL);
	~RequestShow();

	private slots:
	void onClickListItem(const QModelIndex &index);
	void newWindow();
	void closeWindow();

private:
	Ui::Dialog ui;
	QStringListModel *model;

	User *userStatic;

	QString care, price;

	void connectSignal(User *user);
	void showData();
};

#endif // REQUESTSHOW_H
