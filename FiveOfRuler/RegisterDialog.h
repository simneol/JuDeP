/********************************
* RegisterDialog Ŭ����
*  - ��� : ȸ�������� �����ϴ� ���̾�α�
*  - �ۼ��� : ������
*********************************/
#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H
/* ȸ�� ������ �� �� �ִ� â */
#include <QtWidgets/QDialog>

#include "ui_RegisterDialog.h"

class RegisterDialog : public QDialog
{
	Q_OBJECT

public:
	/********************************
	* RegisterDialog ������ �Լ�
	*  - ��� : ���̾�α��� �� ui���� �ʱ�ȭ �ϸ�, ui��� slot�Լ��� connect��Ų��.
	*  - �ۼ��� : ������
	*********************************/
	RegisterDialog(QWidget *parent = 0);

	/********************************
	* RegisterDialog �Ҹ��� �Լ�
	*  - ��� : ���̾�α��� �Ҹ� �� debugâ�� ������ ����Ѵ�.
	*  - �ۼ��� : ������
	*********************************/
	~RegisterDialog();

private:
	Ui::RegisterDialog ui;
	bool is_idDuplicated;
signals:
	private slots:
	/********************************
	* slotSignup �Լ�
	*  - ��� : ����ڰ� �Է��� ������ ������� DB�� ������ �Է������ν� ȸ�������� �Ϸ��Ѵ�.
	*  - �ۼ��� : ������
	*********************************/
		void slotSignup();

	/********************************
	* slotInitDuplication �Լ�
	*  - ��� : ����ڰ� ���̵� �Է�ĭ�� �������� ���, �ߺ�üũ �ߴ� ������ ��ȿȭ��Ų��.
	*  - �ۼ��� : ������
	*********************************/
		void slotInitDuplication();

	/********************************
	* slotCheckIdDUplication �Լ�
	*  - ��� : ����ڰ� �Է��� ���̵� �̹� DB�� �����ϴ��� Ȯ���Ͽ�,
	*			is_idDuplicated ������ �����Ѵ�.
	*  - �ۼ��� : ������
	*********************************/
		void slotCheckIdDuplication();
};

#endif // REGISTERDIALOG_H