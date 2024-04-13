#pragma once
#include <ostream>

template <typename T>
class doubleNode
{
private:
	T item; // A data item
	doubleNode<T>* next; // Pointer to next node
	doubleNode<T>* previous; // Pointer to next node
public:
	doubleNode();
	doubleNode(const T& r_Item);
	doubleNode(const T& r_Item, doubleNode<T>* nextNodePtr);
	void setItem(const T& r_Item);
	void setNext(doubleNode<T>* nextNodePtr);
	void setPrevious(doubleNode<T>* nextNodePtr);
	T getItem() const;
	doubleNode<T>* getNext() const;
	doubleNode<T>* getPrevious() const;
}; // end doubleNode


template < typename T>
doubleNode<T>::doubleNode()
{
	next = nullptr;
	previous = nullptr;
}

template < typename T>
doubleNode<T>::doubleNode(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
	previous = nullptr;
}

template < typename T>
doubleNode<T>::doubleNode(const T& r_Item, doubleNode<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}
template < typename T>
void doubleNode<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void doubleNode<T>::setNext(doubleNode<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template < typename T>
T doubleNode<T>::getItem() const
{
	return item;
}

template < typename T>
doubleNode<T>* doubleNode<T>::getNext() const
{
	return next;
}

template<typename T>
inline void doubleNode<T>::setPrevious(doubleNode<T>* previousNodeptr)
{
	previous = previousNodeptr;
}

template<typename T>
inline doubleNode<T>* doubleNode<T>::getPrevious() const
{
	return previous;
}
