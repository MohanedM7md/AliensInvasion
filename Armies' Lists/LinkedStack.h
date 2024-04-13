
/*
This is a program that implements the stack abstract data type using a linked list.
The stack is implemented as a chain of linked nodes that has one pointers, 
a top pointer for the front of the stack .
*/

/*

				The Node: item of type T and a "next" pointer
					------------- 
					| item| next | --->
					-------------
General stack case:

						  top	 
						   |		
						   |											  					   		
					------------- 	  ------------- 	  ------------- 	  ------------- 	  	  
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------	  
		
Empty Case:

					      top	 
						   |		
						   |				
					---- NULL ------
*/

#pragma once


#include "Node.h"
#include "StackADT.h"

template <typename T>
class LinkedStack :public StackADT<T>
{
private :
	Node<T>* top;
	std::string StorageUnitType;
	int length;
public :
	LinkedStack(std::string StorageUnitType = "None");
	bool isEmpty() const ;
	bool push(const T& newEntry);
	bool pop(T& frntEntry);
	bool peek(T& frntEntry)  const;	
	void print();
	~LinkedStack();
	int getLength() const;
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: stack()
The constructor of the stack class.

*/

template<typename T>
LinkedStack<T>::LinkedStack(std::string StorageUnitType) :StorageUnitType(StorageUnitType)
{
	top = nullptr;
	length = 0;
}


/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this stack is empty.

Input: None.
Output: True if the stack is empty; otherwise false.
*/
template<typename T>
inline bool LinkedStack<T>::isEmpty() const
{
	return (top == nullptr);
}





/////////////////////////////////////////////////////////////////////////////////////////

/*Function:push
Adds newEntry at the top of this stack.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template<typename T>
inline bool LinkedStack<T>::push(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (!newNodePtr)
		return false;
	newNodePtr->setNext(top);
	top = newNodePtr;
	length++;
	return true;
}

 // end enstack


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: destack
Removes the last item of this stack. That is, removes the item that was added
freshet.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedStack<T>:: pop(T& frntEntry)
{
	if(isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = top;
	frntEntry = top->getItem();
	top = top->getNext();
		
	// Free memory reserved for the destackd node
	delete nodeToDeletePtr;

	length--;
	return true;
}



/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
copies the top of this stack to the passed param. The operation does not modify the stack.

Input: None.
Output: The top of the stack.
*/

template <typename T>
bool LinkedStack<T>:: peek(T& frntEntry) const
{
	if(isEmpty())
		return false;

	frntEntry = top->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Print
Print all Data's inside the list

Input: None.
Output: None.
*/

template <typename T>
void LinkedStack<T>::print() {
	if (!top) return;
	Node<T>* temp = top;
	while (temp->getNext()) {
		std::cout << temp->getItem() << ", ";
		temp = temp->getNext();
	}
	std::cout << temp->getItem();
}

//////////////////////////////////////////////////////////////////

template <typename T>
LinkedStack<T>::~LinkedStack()
{
	//Note that the cout statements here is just for learning purpose
	//They should be normally removed from the destructor

	//Free all nodes in the stack
	T temp;
	while(pop(temp));

}

template<typename T>
inline int LinkedStack<T>::getLength() const
{
	return this->length;
}
