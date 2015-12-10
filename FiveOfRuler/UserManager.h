#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QtCore/QObject>

#include "QNAWriteDialog.h"
#include "QNASeeDialog.h"
#include "QlistWindow.h"
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

	public slots:
<<<<<<< HEAD
		void logout();
		void openQNAWriteDialog();
		void openQNASeeDialog();
=======
		void slotLogout();
		void slotOpenQNAWriteDialog();
>>>>>>> e29bd90e46d2066a7cbe797db1c35e67b25ac23e
};
#endif