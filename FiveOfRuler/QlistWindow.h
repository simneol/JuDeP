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

// ���ֿ� 2014112022
// �뵵 : Qna�� ��ϵ� ������ Ȯ���� �� �ִ� Ŭ�����̴�.
// Qna�� ���� ������ �׿� �ش��ϴ� Qna�� Ŭ���� ��� ��������
// ����Ǵ� �޼��带 �������ִ� Ŭ�����̴�.
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
