/***************************************
/ 작성자 : 박성수
/ 클래스 : TechQNASelectDialog
/ 용  도 : 일반 사용자의 질문에 대해 답변 할 수 있는 Window
/***************************************/
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

#include "User.h"
#include "TechUser.h"
#include "ui_techQNASelectDialog.h"
#include "UserInstanceManager.h"

class TechQNASelectDialog : public QDialog
{
	Q_OBJECT

public:
	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 생성자
	/ 용  도 : 객체를 생성한다.
	/***************************************/
	TechQNASelectDialog(QWidget *parent = 0, TechUser* user = NULL);

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 소멸자
	/ 용  도 : 객체를 제거한다.
	/***************************************/
	~TechQNASelectDialog();

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : showData
	/ 용  도 : DB에 있는 내용을 ListView에 출력한다.
	/***************************************/
	void showData();
private:
	Ui::TechQNASelectDialog ui;
	TechUser* user;
	int selectNumber;
	QStringListModel *model;
signals:
	private slots :
		/***************************************
		/ 작성자 : 박성수
		/ 메소드 : onClickSelectBtn
		/ 용  도 : Select 버튼이 클릭되면 호출되는 메소드
		/***************************************/
		void onClickSelectBtn();

		/***************************************
		/ 작성자 : 박성수
		/ 메소드 : onClickListItem
		/ 용  도 : ListView에 Item들이 클릭되면 호출되는 메소드
		/***************************************/
		void onClickListItem(const QModelIndex &index);
};

#endif // QNASEEDIALOG_H
