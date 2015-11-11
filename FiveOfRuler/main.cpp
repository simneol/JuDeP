#include "LoginWindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets\/QSplashScreen>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QSplashScreen *splash =new QSplashScreen;
	splash->setPixmap(QPixmap("image/splash.png"));
	splash->show();

	Qt::Alignment topRight=Qt::AlignRight|Qt::AlignTop;
	splash->showMessage(QObject::tr("Connect to Login DB..."),topRight,Qt::white);

	LoginWindow *loginwindow=new LoginWindow();
	loginwindow->show();
	splash->finish(loginwindow);
	delete splash;

	return app.exec();
}