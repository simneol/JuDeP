#include "QlistWindow.h"
#include "FiveOfRulerDB.h"

QlistWindow::QlistWindow(QWidget *parent, User *user) :
QDialog(parent)
{
	ui.setupUi(this);
	QStandardItemModel *model1 = new QStandardItemModel(2, 3, this); //2 Rows and 3 Columns

	//model = new QStringListModel(this);
	//QStringList list;

	QSqlQuery *query = FiveOfRulerDB::select("qna", "writer", user->getId());

	//model->setStringList(list);

	/*while (query->next())
	{
		list << query->value(3).toString();
	}
	model->setStringList(list);*/

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

	connectSignal(user);
}

QlistWindow::~QlistWindow()
{
}

void QlistWindow::connectSignal(User *user)
{
	QSqlQuery *query = FiveOfRulerDB::select("qna", "writer", user->getId());
	QStandardItemModel *model1 = new QStandardItemModel(2, 3, this); //2 Rows and 3 Columns

	for (int i = 0; query->next(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//list << query->value(j).toString()

			model1->setItem(i, j, new QStandardItem(QString(query->value(0).toString())));
		}
	}
	ui.tableView->setModel(model1);

	connect(ui.tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onClickListItem(const QModelIndex &)));
}

void QlistWindow::onClickListItem(const QModelIndex &index)
{
	QSqlQuery *query1 = FiveOfRulerDB::select("qna", "postIndex", index.data().toString());

	QMessageBox::information(this, "QNA", "QNA: \n" + query1->value(3).toString());
}