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
	QDialog* OpenDialog(QString str);
	void OpenQuestionReplyDialog(int val);
private:
	Ui::TechnicianWindow ui;
	QMap<QString, QDialog*> dialogs;
	int QNAIndex;
signals:
	private slots:
		void slotLogout();
		void slotOpenQuestionReplyWindow();
		void slotOpenRegisterProductDialog();
		void slotOpenComponentSearchDialog();
		void slotOpenProductSearchDialog();
};

#endif // TECHNICIANWINDOW_H