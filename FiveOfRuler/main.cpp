#include "fiveofruler.h"
#include <QtWidgets/QApplication>

#include <QtWidgets\/QPlainTextEdit>

#include <QtCore/QDebug>
#include <QtCore/QMetaObject>
#include <QtCore/QThread>
#include <QtCore/QDateTime>
#include <QtCore/QtGlobal>

#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

#include <QtWidgets/QWidget>

#include <cstdio>
#include <cassert>

enum{LOGIN,USER,TECHNICIAN,ADMIN};
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	FiveOfRuler *loginWindow=new FiveOfRuler(LOGIN);
	loginWindow->show();


//	/* QLabel */
//	// HTML ���� ���
//	// �� ��° ���ڷ� â�� �ּҰ� �־��ָ� �ش� â ���� ��� ����
//	QLabel *label =new QLabel("<h2><i>Hello Qt!</i> "
//							"<font color=red>Qt!</font></h2>",&w);
//	// ��ġ �� ũ��
//	label->setGeometry(10,110,200,50);
////	label->show(); // �������϶��� show()�Լ� �Ⱦ��� �Ⱥ���
//	
//	/* QButton */
//	QPushButton *button = new QPushButton("Quit",&w);
//	QPushButton *button2 = new QPushButton("Button2",&w);
//
//	button2->setGeometry(10,200,200,30);
//	// SIGNAL : clicked, pressed, relaesed ...
////	QObject::connect(button, SIGNAL(clicked()),&a,SLOT(quit()));
//	QObject::connect(button, SIGNAL(clicked()),button2,SLOT(setText("zz")));
//
////	button->show();
//	button->setText("New Name");
//	button->setToolTip("tooltip");
//	button->setGeometry(10,30,200,30);
//
//	QFont font("consolas");
//	button->setFont(font);
//	
//	/*
//	QIcon icon("/path/icon.png");
//	button->setIcon(icon);
//	*/
////	button->setIcon(QIcon::fromTheme("face-smile"));
//
//	/* HBox, Slider, QSpinBox */
//	



//	w.show();
	return app.exec();
}