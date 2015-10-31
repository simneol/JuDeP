#ifndef FIVEOFRULER_H
#define FIVEOFRULER_H

#include <QtWidgets/QMainWindow>
#include "ui_fiveofruler.h"

class FiveOfRuler : public QMainWindow
{
	Q_OBJECT

public:
	FiveOfRuler(QWidget *parent = 0);
	~FiveOfRuler();

private:
	Ui::FiveOfRulerClass ui;
};

#endif // FIVEOFRULER_H
