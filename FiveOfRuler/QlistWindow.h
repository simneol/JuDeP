#ifndef QLISTWINDOW_H
#define QLISTWINDOW_H

#include <QtCore/QObject>

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>
#include <qlistview.h>
#include <qstandarditemmodel.h>
#include <QTableWidget.h>
#include <QMessageBox>

#include "QNAWriteDialog.h"
#include "User.h"
#include "ui_QNASeeDialog.h"

// 문주원 2014112022
// 용도 : Qna의 등록된 정보를 확인할 수 있는 클래스이다.
// Qna에 대한 내용은 그에 해당하는 Qna를 클릭할 경우 정보들이
// 실행되는 메서드를 가지고있는 클래스이다.
class QlistWindow : public QDialog
{
	Q_OBJECT

public:
	explicit QlistWindow(QWidget *parent = 0, User* user = NULL);
	~QlistWindow();

	private slots:
		void onClickListItem(const QModelIndex &index);
		void openQNAWriteDialog();
		void newWindow();
		void closeWindow();

private:
	Ui::QNASeeDialog ui;
	QStringListModel *model;
	QNAWriteDialog *qnaWriteDialog;

	User *userStatic;

	void connectSignal(User *user);
	void showData();
};

#endif // QLISTWINDOW_H
