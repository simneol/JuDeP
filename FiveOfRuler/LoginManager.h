#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include "RegisterDialog.h"
#include "ForgotIdPwDialog.h"

#include <QtCore/QObject>

class LoginManager : public QObject
{
	Q_OBJECT
public:
	LoginManager();
	~LoginManager();
private:
	RegisterDialog *registerDialog;
	ForgotIdPwDialog *forgotIdPwDialog;
signals:
	public slots:
	void slotLogin(QString id, QString pw, bool isUser);
	void slotOpenRegisterDialog();
	void slotOpenForgotIdPwDialog();
};
#endif