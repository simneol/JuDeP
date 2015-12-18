#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QtCore/QObject>

#include "QNAWriteDialog.h"
#include "QNASeeDialog.h"
#include "QlistWindow.h"
#include "RequestProduct.h"
#include "User.h"
#include "RequestShow.h"

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
	RequestProduct *requestDialog;
	RequestShow *requestShowDialog;
	User *user;

	public slots:
		void logout();
		void openQNAWriteDialog();
		void openQNASeeDialog();
		void openRequestProduct();
		void openRequestShow();
};
#endif