#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class TemplateSingleton
{
public:
	static T & getInstance()
	{
		if(pInstance == NULL) pInstance = new T;
		return *pInstance;
	}

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