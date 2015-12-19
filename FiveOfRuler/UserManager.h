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

// 문주원 2014112022
// 용도 : 사용자에 대한 기본적인 연산을 하는 클래스이다.
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