#include "ProductSearchDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>
#include <QString>
#include <QtWidgets/QMessageBox>

ProductSearchDialog::ProductSearchDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}


ProductSearchDialog::~ProductSearchDialog()
{
	qDebug("~QuestionReplyDialog()");
}
