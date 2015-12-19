/********************************
* RegisterDialog 클래스
*  - 기능 : 회원가입을 수행하는 다이어로그
*  - 작성자 : 정민혁
*********************************/
#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H
/* 회원 가입을 할 수 있는 창 */
#include <QtWidgets/QDialog>

#include "ui_RegisterDialog.h"

class RegisterDialog : public QDialog
{
	Q_OBJECT

public:
	/********************************
	* RegisterDialog 생성자 함수
	*  - 기능 : 다이어로그의 각 ui들을 초기화 하며, ui들과 slot함수를 connect시킨다.
	*  - 작성자 : 정민혁
	*********************************/
	RegisterDialog(QWidget *parent = 0);

	/********************************
	* RegisterDialog 소멸자 함수
	*  - 기능 : 다이어로그의 소멸 시 debug창에 내역을 출력한다.
	*  - 작성자 : 정민혁
	*********************************/
	~RegisterDialog();

private:
	Ui::RegisterDialog ui;
	bool is_idDuplicated;
signals:
	private slots:
	/********************************
	* slotSignup 함수
	*  - 기능 : 사용자가 입력한 내용을 기반으로 DB애 정보를 입력함으로써 회원가입을 완료한다.
	*  - 작성자 : 정민혁
	*********************************/
		void slotSignup();

	/********************************
	* slotInitDuplication 함수
	*  - 기능 : 사용자가 아이디 입력칸을 수정했을 경우, 중복체크 했던 내역을 무효화시킨다.
	*  - 작성자 : 정민혁
	*********************************/
		void slotInitDuplication();

	/********************************
	* slotCheckIdDUplication 함수
	*  - 기능 : 사용자가 입력한 아이디가 이미 DB에 존재하는지 확인하여,
	*			is_idDuplicated 변수를 조정한다.
	*  - 작성자 : 정민혁
	*********************************/
		void slotCheckIdDuplication();
};

#endif // REGISTERDIALOG_H