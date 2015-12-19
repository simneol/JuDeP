/***************************************
/ 작성자 : 박성수
/ 클래스 : TemplateSingleton
/ 용  도 : 싱글톤을 구현하는 템플릿 클래스
/***************************************/
#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class TemplateSingleton
{
public:
	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : getInstance
	/ 용  도 : 유일한 객체를 얻을 수 있는 메소드
	/***************************************/
	static T & getInstance()
	{
		if(pInstance == NULL) pInstance = new T;
		return *pInstance;
	}

	/***************************************
	/ 작성자 : 박성수
	/ 메소드 : destroyInstance
	/ 용  도 : 유일한 객체를 제거 할 때 호출되는 메소드(실행중에 호출되지 않는다.)
	/***************************************/
	static void destroyInstance()
	{
		delete pInstance;
		pInstance = NULL;
	}

private:
	static T * pInstance;
};

template<typename T> T* TemplateSingleton<T>::pInstance = 0;

#endif