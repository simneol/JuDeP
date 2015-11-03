#ifndef FIVEOFRULER_H
#define FIVEOFRULER_H

#include <QtWidgets/QMainWindow>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include "ui_fiveofruler.h"

class FiveOfRuler : public QMainWindow
{
	Q_OBJECT

public:
	FiveOfRuler(int id,QWidget *parent = 0);
	~FiveOfRuler();

private:
	Ui::FiveOfRulerClass ui;
	QPushButton *loginButton;
	QLabel *idLabel,*pwLabel;
	QLineEdit *idLineEdit,*pwLineEdit;

	QTextEdit *te;
signals:

	private slots:
		void changeText();
};

#endif // FIVEOFRULER_H
