#include "WindowManager.h"
#include "FiveOfRulerDB.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QSplashScreen>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	/* SplashScreen을 띄운 뒤, 프로그램 실행에 필요한 초기화 작업을 진행한다. */
	QSplashScreen *splash =new QSplashScreen;
	splash->setPixmap(QPixmap("image/splash.png"));
	splash->show();

	Qt::Alignment topRight=Qt::AlignRight|Qt::AlignTop;

	/* 작업 내용에 따라, SplashScreen에 작업 내용을 반영 */
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