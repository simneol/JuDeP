/********************************
* ForgotIdPwDialog Ŭ����
*  - ��� : ������� ���������� ������� ���̵�� ��й�ȣ��
*			ã���ִ� ���̾�α�
*  - �ۼ��� : ������
*********************************/
#ifndef FORGOTIDPWDIALOG_H
#define FORGOTIDPWDIALOG_H
/* ���̵� �� ��й�ȣ ã�� â */
#include <QtWidgets/QDialog>

#include "ui_ForgotIdPwDialog.h"

class ForgotIdPwDialog : public QDialog
{
	Q_OBJECT

public:
	/********************************
	* ForgotIdPwDialog ������ �Լ�
	*  - ��� : ���̾�α��� ui�� �ʱ�ȭ�ϸ�, �� ui��ҵ�� slot�Լ����� connect�����ش�.
	*  - �ۼ��� : ������
	*********************************/
	ForgotIdPwDialog(QWidget *parent = 0);

	/********************************
	* ForgotIdPwDialog �Ҹ��� �Լ�
	*  - ��� : ���̾�α��� �Ҹ곻���� debugâ�� ����Ѵ�.
	*  - �ۼ��� : ������
	*********************************/
	~ForgotIdPwDialog();

private:
	Ui::ForgotIdPwDialog ui;

signals:
	private slots:
	/********************************
	* slotFind �Լ�
	*  - ��� : ����ڰ� �Է��� ������ ���� ���̵� Ȥ�� ��й�ȣ�� ã��
	*			�޽����ڽ��� ������ش�.
	*  - �ۼ��� : ������
	*********************************/
		void slotFind();

	/********************************
	* slotIdShow �Լ�
	*  - ��� : ����ڰ� idã�⸦ �� ���, id ã�⿡ �ʿ���� ui��ҵ���
	*			hide�Ѵ�.
	*  - �ۼ��� : ������
	*********************************/
		void slotIdshow();

	/********************************
	* slotPwShow �Լ�
	*  - ��� : ����ڰ� pwã�⸦ �� ���, ��� ui��ҵ��� show�Ѵ�
	*  - �ۼ��� : ������
	*********************************/
		void slotPwshow();
};

#endif // FORGOTIDPWDIALOGDIALOG_H