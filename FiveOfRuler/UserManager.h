#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QtCore/QObject>

#include "QNAWriteDialog.h"
#include "QNASeeDialog.h"
#include "QlistWindow.h"
#include "RequestProduct.h"
#include "RequestShow.h"
#include "RegisterProductInformation.h"
#include "User.h"

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

	RequestProduct *requestDialog;
	RequestShow *reauestShowDialog;
	RegisterProductInformation *registerProduc;

	public slots:
		void logout();
		void openQNAWriteDialog();
		void openQNASeeDialog();
		void openRequestDialog();
		void openRequestShowDialog();
		void openRegisterProductInformation();
};
#endif