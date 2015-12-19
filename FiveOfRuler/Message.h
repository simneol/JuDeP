#ifndef MESSAGE_H
#define MESSAGE_H

#include <QMainWindow>
#include <qstandarditemmodel.h>
#include <QTableWidget.h>

#include <QtWidgets/QDialog>
#include <QStringList>
#include <QStringListModel>
#include <qlistview.h>

#include "User.h"
#include "ui_MessageDialog.h"

// ���ֿ� 2014112022
// �޽����� ����ڿ� ��ũ�ϼǰ��� ���� ��ȯ�ϴ� Ŭ�����̴�.
class Message : public QDialog
{
	Q_OBJECT

public:
	Message(QWidget *parent = 0, User* user = NULL);
	~Message();
	void showData();

private:
	Ui::MessageDialog ui;
	User* user;
	QStringListModel *model;

signals:
	private slots :
		void writeMessage();
		void closeMessage();
		void onClickListItem(const QModelIndex &index);
		void newWindow();
};

#endif // MESSAGE_H
