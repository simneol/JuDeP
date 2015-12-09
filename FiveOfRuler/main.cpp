#include "WindowManager.h"
#include "FiveOfRulerDB.h"
// This is test branch !
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QSplashScreen>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QSplashScreen *splash =new QSplashScreen;
	splash->setPixmap(QPixmap("image/splash.png"));
	splash->show();

	Qt::Alignment topRight=Qt::AlignRight|Qt::AlignTop;

	splash->showMessage(QObject::tr("Initialize DB..."),topRight,Qt::white);
	FiveOfRulerDB fiveofrulerDB;

	for(int i=1;i<=5;i++)
	{
		splash->showMessage(QObject::tr("Connect to DB...")+" ("+(i+'0')+"/5)",topRight,Qt::white);
		if(fiveofrulerDB.open())
			break;
		if(i==5)
		{
			QMessageBox msgbox;
			msgbox.setText(QObject::tr("Cannot connect to DB !\nPlease check your Internet connection."));
			msgbox.exec();
			return 0;
		}
	}
	WindowManager::slotOpenWindow("LoginWindow");
	delete splash;

	return app.exec();
}