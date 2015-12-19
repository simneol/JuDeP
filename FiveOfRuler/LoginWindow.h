/********************************
* LoginWindow 클래스
*  - 기능 : 로그인을 수행하는 MainWindow
*  - 작성자 : 정민혁
*********************************/
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
/* 로그인을 수행하는 창에 대한 전반적인 관리를 하는 부분 (Controller) */
#include <QTCore/QMap>
#include <QtWidgets/QMainWindow>

#include "ui_LoginWindow.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT
public:
	/********************************
	* LoginWindow 생성자 함수
	*  - 기능 : 각 ui들을 초기화하고, ui와 slot함수들을 connect시킨다.
	*  - 작성자 : 정민혁
	*********************************/
	LoginWindow(QWidget *parent = 0);

	/********************************
	* LoginWindow 소멸자 함수
	*  - 기능 : LoginWindow의 소멸 시 debug창에 내역을 출력한다.
	*  - 작성자 : 정민혁
	*********************************/
	~LoginWindow();

	/********************************
	* OpenDialog 함수
	*  - 기능 : 인자값으로 받은 Dialog창을 연다.
	*			각 다이어로그들은 최소한 한번이상 열린 다이어로그는 Hide된 상태로 대기하며
	*			한번도 열리지 않은 다이어로그는 새로 생성한다.
	*			각 다이어로그들은 map에 value로 저장되며, key는 dialog의 이름이다.
	*			이를 통해 dialog는 open interface가 간략화되어 dialog 출력시의 dependency가 최소화된다.		
	*  - 작성자 : 정민혁
	*********************************/
	void OpenDialog(QString str);

private:
	Ui::LoginWindow ui;
	QMap<QString, QDialog*> dialogs;

signals:
	void slotLoginSignal(QString id, QString pw, bool isUser);
	private slots:
	/********************************
	* slotOpenRegisterDialog 함수
	*  - 기능 : OpenDialog를 "RegisterDialog"인자로 호출한다.
	*  - 작성자 : 정민혁
	*********************************/
		void slotOpenRegisterDialog(void);

	/********************************
	* slotOpenForgotIdPwDialog 함수
	*  - 기능 : OpenDialog를 "ForgotIdPwDialog"인자로 호출한다.
	*  - 작성자 : 정민혁
	*********************************/
		void slotOpenForgotIdPwDialog(void);

	/********************************
	* slotLogin 함수
	*  - 기능 : 사용자가 입력한 정보를 기반으로 DB의 자료와 대조하여
	*			로그인 과정을 처리한다.
	*  - 작성자 : 정민혁
	*********************************/
		void slotLogin(void);
};
#endif // LOGINWINDOW_H