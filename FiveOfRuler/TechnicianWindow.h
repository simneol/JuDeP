#ifndef TECHNICIANWINDOW_H
#define TECHNICIANWINDOW_H

#include <QtWidgets/QMainWindow>
#include <map>
#include <QTCore/QMap>
#include <QTCore/QString>

#include "ui_TechnicianWindow.h"
#include "QuestionReplyDialog.h"


class TechnicianWindow : public QMainWindow
{
	Q_OBJECT

public:
	TechnicianWindow(QWidget *parent = 0);
	~TechnicianWindow();
	void CloseAllDialog();
	void OpenDialog(QString str);
	void OpenQuestionReplyDialog(int val);
private:
	Ui::TechnicianWindow ui;
	QMap<QString, QDialog*> *dialogs;
	int QNAIndex;
signals:
	private slots:
		void slotLogout();
		void slotOpenQuestionReplyWindow();
};

#endif // TECHNICIANWINDOW_H