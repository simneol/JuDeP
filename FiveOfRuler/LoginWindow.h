#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QTCore/QMap>
#include <QtWidgets/QMainWindow>

#include "ui_LoginWindow.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT
public:
	LoginWindow(QWidget *parent = 0);
	~LoginWindow();

	void OpenDialog(QString str);

private:
	Ui::LoginWindow ui;
	QMap<QString, QDialog*> dialogs;

signals:
	void slotLoginSignal(QString id, QString pw, bool isUser);
	private slots:
		void slotOpenRegisterDialog(void);
		void slotOpenForgotIdPwDialog(void);
		void slotLogin(void);
};
#endif // LOGINWINDOW_H