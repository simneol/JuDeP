#ifndef QLISTWINDOW_H
#define QLISTWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>
#include <qtableview.h>
#include <qstandarditemmodel.h>
#include <QTableWidget.h>
#include <QMessageBox>

#include "User.h"

#include "ui_QNASeeDialog.h"

class QlistWindow : public QDialog
{
	Q_OBJECT

public:
	explicit QlistWindow(QWidget *parent = 0, User* user = NULL);
	~QlistWindow();

	private slots:
		void onClickListItem(const QModelIndex &index);

private:
	Ui::QNASeeDialog ui;
	QStringListModel *model;

	void connectSignal();
};

#endif // QLISTWINDOW_H
