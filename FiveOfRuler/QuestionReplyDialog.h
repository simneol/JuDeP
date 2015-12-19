/***************************************
/ 작성자 : 박성수
/ 클래스 : QuestionReplyDialog
/ 용  도 : 질문에 대해 답하는 다이어로그
/***************************************/
#ifndef	QUESTIONREPLYDIALOG_H
#define QUESTIONREPLYDIALOG_H

#include <QtWidgets/QDialog>

#include "ui_QuestionReplyDialog.h"
#include "UserInstanceManager.h"

class QuestionReplyDialog : public QDialog
{
	Q_OBJECT

public:
	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 생성자
	/ 용  도 : 객체를 생성한다.
	/***************************************/
	QuestionReplyDialog(QWidget *parent = 0);

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 소멸자
	/ 용  도 : 객체를 제거한다.
	/***************************************/
	~QuestionReplyDialog();

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : setup
	/ 용  도 : 답변할 질문의 postIndex등 답변에 필요한 정보를 입력한다.
	/***************************************/
	void setup(int val);

private:
	Ui::QuestionReplyDialog ui;
	int num;
signals:
	private slots:
		/***************************************
		/ 작성자 : 박성수
		/ 메소드 : slotSubmit
		/ 용  도 : 답변하기 버튼이 클릭됬을때 호출될 메소드
		/***************************************/
		void slotSubmit();

		/***************************************
		/ 작성자 : 박성수
		/ 메소드 : slotCancle
		/ 용  도 : 취소하기 버튼이 클릭됬을때 호출될 메소드
		/***************************************/
		void slotCancle();

		void write();
};

#endif
