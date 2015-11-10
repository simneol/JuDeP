//#include "fiveofruler.h"
#include "LoginWindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	LoginWindow *loginwindow=new LoginWindow();
	loginwindow->show();

	return app.exec();
}