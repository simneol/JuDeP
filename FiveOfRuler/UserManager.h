#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QtCore/QObject>

#include "QNAWriteDialog.h"
#include "QNASeeDialog.h"
#include "QlistWindow.h"
#include "RequestProduct.h"
#include "RegisterProductInformation.h"
#include "RequestShow.h"
#include "User.h"

// ���ֿ� 2014112022
// �뵵 : ����ڿ� ���� �⺻���� ������ �ϴ� Ŭ�����̴�.
class UserManager : public QObject
{
	Q_OBJECT
public:
	UserManager(Info*);
	~UserManager();
	User* getUser();

private:
	QNAWriteDialog *qnaWriteDialog;
	QlistWindow *qnaSeeDialog;
	User *user;
	RegisterProductInformation * registerProduc;

	RequestProduct *requestDialog;
	RequestShow *reauestShowDialog;

	public slots:
		void logout();
		void openQNAWriteDialog();
		void openQNASeeDialog();
		void openRequestDialog();
		void openRequestShowDialog();
		void openRegisterProductInformation();
};
#endif