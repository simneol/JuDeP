#ifndef QNAWRITEDIALOG_H
#define QNAWRITEDIALOG_H

#include <QtWidgets/QDialog>

#include "User.h"
#include "ui_QNAWriteDialog.h"

class QNAWriteDialog : public QDialog
{
	Q_OBJECT

public:
	QNAWriteDialog(QWidget *parent = 0,User* user=NULL);
	~QNAWriteDialog();

private:
	Ui::QNAWriteDialog ui;
	User* user;

signals:
	private slots:
<<<<<<< HEAD
		void write();
		void closeQNA();
=======
		void slotWrite();
>>>>>>> e29bd90e46d2066a7cbe797db1c35e67b25ac23e
};

#endif // QNAWRITEDIALOG_H
