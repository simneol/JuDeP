/***************************************
/ �ۼ��� : �ڼ���
/ Ŭ���� : TemplateSingleton
/ ��  �� : �̱����� �����ϴ� ���ø� Ŭ����
/***************************************/
#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class TemplateSingleton
{
public:
	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : getInstance
	/ ��  �� : ������ ��ü�� ���� �� �ִ� �޼ҵ�
	/***************************************/
	static T & getInstance()
	{
		if(pInstance == NULL) pInstance = new T;
		return *pInstance;
	}

	/***************************************
	/ �ۼ��� : �ڼ���
	/ �޼ҵ� : destroyInstance
	/ ��  �� : ������ ��ü�� ���� �� �� ȣ��Ǵ� �޼ҵ�(�����߿� ȣ����� �ʴ´�.)
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