#include "ComponentSearchDialog.h"
#include "FiveOfRulerDB.h"

#include <QtCore/QDebug>
#include <QtCore/QVector>
#include <QString>
#include <QtWidgets/QMessageBox>

ComponentSearchDailog::ComponentSearchDailog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}


ComponentSearchDailog::~ComponentSearchDailog()
{
	qDebug("~QuestionReplyDialog()");
}
