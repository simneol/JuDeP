#include "RegisterProductDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>
#include <QString>
#include <QtWidgets/QMessageBox>

RegisterProductDialog::RegisterProductDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}


RegisterProductDialog::~RegisterProductDialog()
{
	qDebug("~QuestionReplyDialog()");
}
