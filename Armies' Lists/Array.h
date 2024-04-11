#pragma once
#define MAX 350
#include <ctime>
#include <cstdlib>
#include <ostream>

template <typename T>

class Array {
	T* Arrlist[MAX];
	int length;
	int createRandomIndex(int max);
public:
	Array();
	bool isEmpty();
	bool add(const T&);
	bool remove(T&);
	void print();
	int getLength() const;

};


template<typename T>
inline Array<T>::Array():length(0)
{
}

template<typename T>
inline int Array<T>::createRandomIndex(int max)
{
	srand((int)time(0));

	return (rand() % max) + 1;
}

template<typename T>
inline bool Array<T>::isEmpty()
{
	return length == 0;
}

template<typename T>
inline bool Array<T>::add(const T& item)
{
	if (length == MAX)
		return false;

	T* newItem = new T;
	*newItem = item;
	Arrlist[length++] = newItem;
	return true;
}

template<typename T>
inline bool Array<T>::remove(T& item)
{
	if(length == 0)
		return false;

	int randomIndex = createRandomIndex(length-1);
	T* deleteMe = Arrlist[randomIndex];
	item = *Arrlist[randomIndex];
	Arrlist[randomIndex] = Arrlist[length - 1];
	delete deleteMe;
	return true;
}

template<typename T>
inline void Array<T>::print()
{
	if (isEmpty())
		return;
	for (int i = 0; i < length-1; i++)
		std::cout << *Arrlist[i]<<", ";

	std::cout << *Arrlist[length-1];
}

template<typename T>
inline int Array<T>::getLength() const
{
	return this->length;
}
