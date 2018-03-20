#pragma once
#include <string>
#include <vector>

//����ע��
class Commentses {
	std::string commentses;//ע��
public:
	Commentses() = default;
	Commentses(std::string);
	Commentses(std::vector<std::string>);

	//����ע��
	virtual void setCommentses(std::string);
	//��ȡע��
	virtual std::string getCommentses();

	//��ȡini��ʽ��ע��
	virtual std::string getCommentsesInIni();
};

//�Զ��弯��
template<class T>
class INIvector {
protected:
	std::vector<T> list;//��������
	virtual bool equal(T&, std::string) = 0;
	virtual T New(std::string key) = 0;
public:
	//�ж�
	virtual bool has(std::string);

	//��ȡ
	virtual T& get(std::string key);
	//��ȡ
	virtual T & operator[](std::string key);

	//ɾ��
	virtual void del(std::string key);

	//����
	virtual decltype(list.begin()) begin();
	virtual decltype(list.end()) end();
};

template<class T>
inline bool INIvector<T>::has(std::string key)
{
	for (T t : list)
		if (equal(t, key))return true;
	return false;
}

template<class T>
inline T & INIvector<T>::get(std::string key)
{
	for (T t : list)
		if (equal(t, key))return t;
	list.push_back(New(key));
	return list.back();
}

template<class T>
inline T & INIvector<T>::operator[](std::string key)
{
	return get(key);
}

template<class T>
inline void INIvector<T>::del(std::string key)
{
	for (auto b = begin(); b != end(); b++) {
		if (equal(*b, key)) { list.erase(b); return; }
	}
}

template<class T>
inline decltype(INIvector<T>::list.begin()) INIvector<T>::begin()
{
	return list.begin();
}

template<class T>
inline decltype(INIvector<T>::list.end()) INIvector<T>::end()
{
	return list.end();
}
