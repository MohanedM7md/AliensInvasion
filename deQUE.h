#pragma once
#include "Armies' Lists/LinkedQueue.h"
template <class T>
class deQue :public LinkedQueue<T> {

	deQue();
	bool enquefront(T& );
	bool enqueback(T&);
};
template <class T>
deQue<T>::deQue():LinkedQueue<T>() {

}
template<class T>
bool deQue<T>::enquefront(T& name) {
	LinkedQueue<T>::isEmput();
}