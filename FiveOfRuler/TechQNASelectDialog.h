#ifndef TECH_QNA_SELECT_DIALOG_H
#define TECH_QNA_SELECT_DIALOG_H

#include <QtWidgets/QDialog>
#include <QtCore/QObject>

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>
#include <qlistview.h>
#include <qstandarditemmodel.h>
#include <QTableWidget.h>
#include <QMessageBox>

#include "TechnicianWindow.h"
#include "User.h"
#include "TechUser.h"
#include "ui_techQNASelectDialog.h"
#include "UserInstanceManager.h"

class TechQNASelectDialog : public QDialog
{
	Q_OBJECT

public:
	TechQNASelectDialog(QWidget *parent = 0, TechUser* user = NULL);
	~TechQNASelectDialog();

	void showData();
	void setDialog(TechnicianWindow *window);
private:
	Ui::TechQNASelectDialog ui;
	TechUser* user;
	int selectNumber;
	QStringListModel *model;
	TechnicianWindow *window;
signals:
	private slots :
		void onClickSelectBtn();
		void onClickListItem(const QModelIndex &index);
};

#endif // QNASEEDIALOG_H
