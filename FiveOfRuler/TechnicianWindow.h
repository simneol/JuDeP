/***************************************
/ �ۼ��� : �ڼ���
/ Ŭ���� : TechnicianWindow
/ ��  �� : Technician User�� ��� ���� Window
/***************************************/
#ifndef TECHNICIANWINDOW_H
#define TECHNICIANWINDOW_H

#include <QtWidgets/QMainWindow>
#include <map>
#include <QTCore/QMap>
#include <QTCore/QString>

#include "ui_TechnicianWindow.h"
#include "QuestionReplyDialog.h"


class TechnicianWindow : public QMainWindow
{
	Q_OBJECT

public:
	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : ������
	/ ��  �� : ��ü�� �����Ѵ�.
	/***************************************/
	TechnicianWindow(QWidget *parent = 0);

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : �Ҹ���
	/ ��  �� : ��ü�� �����Ѵ�.
	/***************************************/
	~TechnicianWindow();

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : CloseAllDialog
	/ ��  �� : Dialog�� ��� �����Ѵ�.
	/ Iterator�� �̿��Ͽ� map�� ����� ��� Dialog�� �����Ѵ�.
	/ map���� QDialog Type�� Value�̸�, �̴� �������� �����ϱ� ���� �ʿ��ϴ�.
	/***************************************/
	void CloseAllDialog();

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : OpenDialog
	/ ��  �� : Dialog�� ����.
	/ �� ���̾�α׵��� �ּ��� �ѹ��̻� ���� ���̾�α״� Hide�� ���·� ����ϸ�
	/ �ѹ��� ������ ���� ���̾�α״� ���� �����Ѵ�.
	/ �� ���̾�α׵��� map�� value�� ����Ǹ�, key�� dialog�� �̸��̴�.
	/ �̸� ���� dialog�� open interface�� ����ȭ�Ǿ� dialog ��½��� dependency�� �ּ�ȭ�ȴ�.
	/***************************************/
	QDialog* OpenDialog(QString str);

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : OpenQuestionReplyDialog
	/ ��  �� : QuestionReplyDialog�� Dialog�� ���������� ������ �Ǿ�,
	/ �̸� ��Ʈ���ϴ� �Լ��� ���� �д�.
	/***************************************/
	void OpenQuestionReplyDialog(int val);
private:
	Ui::TechnicianWindow ui;
	QMap<QString, QDialog*> dialogs;
	int QNAIndex;
signals:
	private slots:

		/***************************************
		/ �ۼ��� : �ڼ���
		/ �޼ҵ� : slotLogout
		/ ��  �� : �α׾ƿ� �޴� Ŭ���� ȣ��Ǵ� �޼ҵ�
		/***************************************/
		void slotLogout();

		/***************************************
		/ �ۼ��� : �ڼ���
		/ �޼ҵ� : slotOpenQuestionReplyWindow
		/ ��  �� : ����õ ���ö��� ��ư Ŭ���� ȣ��Ǵ� �޼ҵ�
		/***************************************/
		void slotOpenQuestionReplyWindow();

		/***************************************
		/ �ۼ��� : �ڼ���
		/ �޼ҵ� : slotOpenRegisterProductDialog
		/ ��  �� : �������� ���δ�Ʈ ��ư Ŭ���� ȣ��Ǵ� �޼ҵ�
		/***************************************/
		void slotOpenRegisterProductDialog();

		/***************************************
		/ �ۼ��� : �ڼ���
		/ �޼ҵ� : slotOpenComponentSearchDialog
		/ ��  �� : ������Ʈ ��ġ ��ư Ŭ���� ȣ��Ǵ� �޼ҵ�
		/***************************************/
		void slotOpenComponentSearchDialog();

		/***************************************
		/ �ۼ��� : �ڼ���
		/ �޼ҵ� : slotOpenProductSearchDialog
		/ ��  �� : ���δ�Ʈ ��ġ ��ư Ŭ���� ȣ��Ǵ� �޼ҵ�
		/***************************************/
		void slotOpenProductSearchDialog();
};

#endif // TECHNICIANWINDOW_H