/***************************************
/ �ۼ��� : �ڼ���
/ Ŭ���� : QuestionReplyDialog
/ ��  �� : ������ ���� ���ϴ� ���̾�α�
/***************************************/
#ifndef	QUESTIONREPLYDIALOG_H
#define QUESTIONREPLYDIALOG_H

#include <QtWidgets/QDialog>

#include "ui_QuestionReplyDialog.h"
#include "UserInstanceManager.h"

class QuestionReplyDialog : public QDialog
{
	Q_OBJECT

public:
	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : ������
	/ ��  �� : ��ü�� �����Ѵ�.
	/***************************************/
	QuestionReplyDialog(QWidget *parent = 0);

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : �Ҹ���
	/ ��  �� : ��ü�� �����Ѵ�.
	/***************************************/
	~QuestionReplyDialog();

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : setup
	/ ��  �� : �亯�� ������ postIndex�� �亯�� �ʿ��� ������ �Է��Ѵ�.
	/***************************************/
	void setup(int val);

private:
	Ui::QuestionReplyDialog ui;
	int num;
signals:
	private slots:
		/***************************************
		/ �ۼ��� : �ڼ���
		/ �޼ҵ� : slotSubmit
		/ ��  �� : �亯�ϱ� ��ư�� Ŭ�������� ȣ��� �޼ҵ�
		/***************************************/
		void slotSubmit();

		/***************************************
		/ �ۼ��� : �ڼ���
		/ �޼ҵ� : slotCancle
		/ ��  �� : ����ϱ� ��ư�� Ŭ�������� ȣ��� �޼ҵ�
		/***************************************/
		void slotCancle();

		void write();
};

#endif
