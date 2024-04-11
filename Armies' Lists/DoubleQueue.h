#pragma once
#include "Node.h"
#include "QueueADT.h"

template <typename T>
class DoubleQueue :public QueueADT<T>
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
	int length;

	//std::string ListType;

public:
	DoubleQueue();

	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool enqueueFront(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool enqueueBack(T& backEntry);
	bool peek(T& frntEntry)  const;
	void Print();
	int getLength() const;
	~DoubleQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/


/////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
DoubleQueue<T>::DoubleQueue() {
	backPtr = nullptr;
	frontPtr = nullptr;
	length = 0;
}

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool DoubleQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DoubleQueue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	length++;
	return true;
} // end enqueue

template <typename T>
bool DoubleQueue<T>::enqueueFront(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
	{
		newNodePtr->setNext(frontPtr); // The queue was not empty
		frontPtr = newNodePtr;
		length++;
	}
	return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DoubleQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	length--;
	return true;
}

template <typename T>
bool DoubleQueue<T>::enqueueBack(T& backEntry)
{
	Node<T>* newNodePtr = frontPtr;

	while (newNodePtr->getNext() != backPtr)
	{
		newNodePtr = newNodePtr->getNext();
	};
	backEntry = newNodePtr->getNext()->getItem();
	delete newNodePtr->getNext();
	newNodePtr->setNext() = nullptr;
	backPtr = newNodePtr;
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/

template <typename T>
bool DoubleQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Print
Print all Data's inside the list

Input: None.
Output: None.
*/

template <typename T>
void DoubleQueue<T>::Print() {
	if (!frontPtr) return;
	Node<T>* temp = frontPtr;
	while (temp->getNext()) {
		std::cout << temp->getItem() << ", ";
		temp = temp->getNext();
	}
	std::cout << temp->getItem();
}

template<typename T>
inline int DoubleQueue<T>::getLength() const
{
	return this->length;
}

//////////////////////////////////////////////////////////////////
template <typename T>
DoubleQueue<T>::~DoubleQueue()
{
	//Note that the cout statements here is just for learning purpose
	//They should be normally removed from the destructor
	//Free all nodes in the queue
	T temp;
	while (dequeue(temp));


}

/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers,
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

				The Node: item of type T and a "next" pointer
					-------------
					| item| next | --->
					-------------
General Queue case:

				 frontPtr																backPtr
					\											   						/
					 \											  					   /
					------------- 	  ------------- 	  ------------- 	  -------------
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------

Empty Case:

				 frontptr	 backptr
						\	 /
						 \	/
					---- NULL ------


Single Node Case:
				 frontPtr	 backPtr
					\		/
					 \	   /
					-----------
					|item| next| -->NULL
					-----------

*/
