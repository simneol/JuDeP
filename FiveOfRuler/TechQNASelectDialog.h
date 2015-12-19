/***************************************
/ �ۼ��� : �ڼ���
/ Ŭ���� : TechQNASelectDialog
/ ��  �� : �Ϲ� ������� ������ ���� �亯 �� �� �ִ� Window
/***************************************/
#ifndef TECH_QNA_SELECT_DIALOG_H
#define TECH_QNA_SELECT_DIALOG_H

#include <QtWidgets/QDialog>
#include <QtCore/QObject>

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>
#include <qlistview.h>
#include <qstandarditemmodel.h>
#include <QTableWidget.h>
#include <QMessageBox>

#include "User.h"
#include "TechUser.h"
#include "ui_techQNASelectDialog.h"
#include "UserInstanceManager.h"

class TechQNASelectDialog : public QDialog
{
	Q_OBJECT

public:
	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : ������
	/ ��  �� : ��ü�� �����Ѵ�.
	/***************************************/
	TechQNASelectDialog(QWidget *parent = 0, TechUser* user = NULL);

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : �Ҹ���
	/ ��  �� : ��ü�� �����Ѵ�.
	/***************************************/
	~TechQNASelectDialog();

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : showData
	/ ��  �� : DB�� �ִ� ������ ListView�� ����Ѵ�.
	/***************************************/
	void showData();
private:
	Ui::TechQNASelectDialog ui;
	TechUser* user;
	int selectNumber;
	QStringListModel *model;
signals:
	private slots :
		/***************************************
		/ �ۼ��� : �ڼ���
		/ �޼ҵ� : onClickSelectBtn
		/ ��  �� : Select ��ư�� Ŭ���Ǹ� ȣ��Ǵ� �޼ҵ�
		/***************************************/
		void onClickSelectBtn();

		/***************************************
		/ �ۼ��� : �ڼ���
		/ �޼ҵ� : onClickListItem
		/ ��  �� : ListView�� Item���� Ŭ���Ǹ� ȣ��Ǵ� �޼ҵ�
		/***************************************/
		void onClickListItem(const QModelIndex &index);
};

#endif // QNASEEDIALOG_H
