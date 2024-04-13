//this updated version for DoubleLinked Queue of Frank M. ADT class
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
#pragma once
/** @file DoubleQueueADT.h */
//this class follows the restirictions of eng. TA Mohamed ismail that was given in the Document called "project Recommended DS"
template<class T>
class DoubleQueueADT
{
public:
   /** Sees whether this queue is empty.
    @return  True if the queue is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to the to the first of this queue.
    @post  If the operation was successful, newEntry is at the
       first of the queue.
    @param newEntry  The object to be added as a new entry.
    @return  True if the addition is successful or false if not. */
   virtual bool enqueueFront(const T& newEntry) = 0;
   
   /** Adds a new entry to the to the End of this queue.
    @post  If the operation was successful, newEntry is at the
       End of the queue.
    @param backEntry  The object to be added as a new entry.
    @return  True if the addition is successful or false if not. */
   virtual bool enqueueBack(const T& backEntry) = 0;
   /** Copies the Back item of the queue to the passed parameter and removes it from queue
    @post  If the operation was successful, the Back of the queue
       would be copied to backEntry parameter and removed from the queue.
    @return  True if the removal is successful or false if not. */
   virtual bool dequeueBack(T& backEntry) = 0;
   /** Copies the Front item of the queue to the passed parameter and removes it from queue
    @post  If the operation was successful, the Front of the queue
       would be copied to frntEntry parameter and removed from the queue.
    @return  True if the removal is successful or false if not. */
   virtual bool dequeueFront(T& frntEntry) = 0;
   /** Copies the front item of the queue to the passed parameter without removing it from queue
    @pre  The queue is not empty.
    @post  The front of the queue has been copied to FrontEntry param , and the
       queue is unchanged.
    @return  The front of the queue. */
   virtual bool peek(T& FrontEntry) const = 0;


   virtual void Print()  = 0;
   
   /** Destroys this queue and frees its memory. */
   virtual ~DoubleQueueADT() { }
}; // end QueueADT
