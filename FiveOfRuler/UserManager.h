#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QtCore/QObject>

#include "QNAWriteDialog.h"
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
	User *user;

	public slots:
		void slotLogout();
		void slotOpenQNAWriteDialog();
};
#endif