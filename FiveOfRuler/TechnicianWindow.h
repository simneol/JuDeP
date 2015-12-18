#ifndef TECHNICIANWINDOW_H
#define TECHNICIANWINDOW_H

#include <QtWidgets/QMainWindow>
#include <map>
#include <QTCore/QMap>
#include <QTCore/QString>

#include "ui_TechnicianWindow.h"
#include "QuestionReplyDialog.h"
#include "TechQNASelectDialog.h"


class TechnicianWindow : public QMainWindow
{
	Q_OBJECT

public:
	TechnicianWindow(QWidget *parent = 0);
	~TechnicianWindow();
	void CloseAllDialog();
	void OpenDialog(QString str);
private:
	Ui::TechnicianWindow ui;
	QMap<QString, QDialog*> dialogs;

signals:
	private slots:
		void slotLogout();
		void slotOpenQuestionReplyWindow();
};

#endif // TECHNICIANWINDOW_H