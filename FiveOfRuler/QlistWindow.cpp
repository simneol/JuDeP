#include "QlistWindow.h"
#include "FiveOfRulerDB.h"

QlistWindow::QlistWindow(QWidget *parent, User *user) :
QDialog(parent)
{
	ui.setupUi(this);
	QStandardItemModel *model1 = new QStandardItemModel(2, 3, this); //2 Rows and 3 Columns

	model = new QStringListModel(this);
	QStringList list;

	QSqlQuery *query = FiveOfRulerDB::select("qna", "writer", user->getId());

	model->setStringList(list);

	model1->setHorizontalHeaderItem(0, new QStandardItem(QString("No")));
	model1->setHorizontalHeaderItem(1, new QStandardItem(QString("Writer")));
	model1->setHorizontalHeaderItem(2, new QStandardItem(QString("Title")));

	for (int i = 0; query->next(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//list << query->value(j).toString()

			model1->setItem(i, j, new QStandardItem(QString(query->value(j).toString())));
		}
	}


	ui.tableView->setModel(model1);
}

QlistWindow::~QlistWindow()
{
}

void QlistWindow::connectSignal()
{
	connect(ui.tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onClickListItem(const QModelIndex &)));
}

void QlistWindow::onClickListItem(const QModelIndex &index)
{
	QMessageBox::information(this, "Hello!", "You Clicked: \n" + index.data().toString());
}