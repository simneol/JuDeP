/***************************************
/ 작성자 : 박성수
/ 클래스 : TechnicianWindow
/ 용  도 : Technician User의 기능 모음 Window
/***************************************/
#ifndef TECHNICIANWINDOW_H
#define TECHNICIANWINDOW_H

#include <QtWidgets/QMainWindow>
#include <map>
#include <QTCore/QMap>
#include <QTCore/QString>

#include "ui_TechnicianWindow.h"
#include "QuestionReplyDialog.h"


class TechnicianWindow : public QMainWindow
{
	Q_OBJECT

public:
	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 생성자
	/ 용  도 : 객체를 생성한다.
	/***************************************/
	TechnicianWindow(QWidget *parent = 0);

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : 소멸자
	/ 용  도 : 객체를 제거한다.
	/***************************************/
	~TechnicianWindow();

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : CloseAllDialog
	/ 용  도 : Dialog를 모두 종료한다.
	/ Iterator를 이용하여 map에 저장된 모든 Dialog를 종료한다.
	/ map에는 QDialog Type이 Value이며, 이는 다형성을 구현하기 위해 필요하다.
	/***************************************/
	void CloseAllDialog();

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : OpenDialog
	/ 용  도 : Dialog를 연다.
	/ 각 다이어로그들은 최소한 한번이상 열린 다이어로그는 Hide된 상태로 대기하며
	/ 한번도 열리지 않은 다이어로그는 새로 생성한다.
	/ 각 다이어로그들은 map에 value로 저장되며, key는 dialog의 이름이다.
	/ 이를 통해 dialog는 open interface가 간략화되어 dialog 출력시의 dependency가 최소화된다.
	/***************************************/
	QDialog* OpenDialog(QString str);

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : OpenQuestionReplyDialog
	/ 용  도 : QuestionReplyDialog는 Dialog가 순차적으로 열리게 되어,
	/ 이를 컨트럴하는 함수를 따로 둔다.
	/***************************************/
	void OpenQuestionReplyDialog(int val);
private:
	Ui::TechnicianWindow ui;
	QMap<QString, QDialog*> dialogs;
	int QNAIndex;
signals:
	private slots:

		/***************************************
		/ 작성자 : 박성수
		/ 메소드 : slotLogout
		/ 용  도 : 로그아웃 메뉴 클릭시 호출되는 메소드
		/***************************************/
		void slotLogout();

		/***************************************
		/ 작성자 : 박성수
		/ 메소드 : slotOpenQuestionReplyWindow
		/ 용  도 : 퀘스천 리플라이 버튼 클릭시 호출되는 메소드
		/***************************************/
		void slotOpenQuestionReplyWindow();

		/***************************************
		/ 작성자 : 박성수
		/ 메소드 : slotOpenRegisterProductDialog
		/ 용  도 : 레지스터 프로덕트 버튼 클릭시 호출되는 메소드
		/***************************************/
		void slotOpenRegisterProductDialog();

		/***************************************
		/ 작성자 : 박성수
		/ 메소드 : slotOpenComponentSearchDialog
		/ 용  도 : 컴포넌트 서치 버튼 클릭시 호출되는 메소드
		/***************************************/
		void slotOpenComponentSearchDialog();

		/***************************************
		/ 작성자 : 박성수
		/ 메소드 : slotOpenProductSearchDialog
		/ 용  도 : 프로덕트 서치 버튼 클릭시 호출되는 메소드
		/***************************************/
		void slotOpenProductSearchDialog();
};

#endif // TECHNICIANWINDOW_H