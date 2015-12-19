/********************************
* ForgotIdPwDialog 클래스
*  - 기능 : 사용자의 개인정보를 기반으로 아이디와 비밀번호를
*			찾아주는 다이어로그
*  - 작성자 : 정민혁
*********************************/
#ifndef FORGOTIDPWDIALOG_H
#define FORGOTIDPWDIALOG_H
/* 아이디 및 비밀번호 찾기 창 */
#include <QtWidgets/QDialog>

#include "ui_ForgotIdPwDialog.h"

class ForgotIdPwDialog : public QDialog
{
	Q_OBJECT

public:
	/********************************
	* ForgotIdPwDialog 생성자 함수
	*  - 기능 : 다이어로그의 ui를 초기화하며, 각 ui요소들과 slot함수들을 connect시켜준다.
	*  - 작성자 : 정민혁
	*********************************/
	ForgotIdPwDialog(QWidget *parent = 0);

	/********************************
	* ForgotIdPwDialog 소멸자 함수
	*  - 기능 : 다이어로그의 소멸내역을 debug창에 출력한다.
	*  - 작성자 : 정민혁
	*********************************/
	~ForgotIdPwDialog();

private:
	Ui::ForgotIdPwDialog ui;

signals:
	private slots:
	/********************************
	* slotFind 함수
	*  - 기능 : 사용자가 입력한 정보를 토대로 아이디 혹은 비밀번호를 찾아
	*			메시지박스로 출력해준다.
	*  - 작성자 : 정민혁
	*********************************/
		void slotFind();

	/********************************
	* slotIdShow 함수
	*  - 기능 : 사용자가 id찾기를 할 경우, id 찾기에 필요없는 ui요소들을
	*			hide한다.
	*  - 작성자 : 정민혁
	*********************************/
		void slotIdshow();

	/********************************
	* slotPwShow 함수
	*  - 기능 : 사용자가 pw찾기를 할 경우, 모든 ui요소들을 show한다
	*  - 작성자 : 정민혁
	*********************************/
		void slotPwshow();
};

#endif // FORGOTIDPWDIALOGDIALOG_H