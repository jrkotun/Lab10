#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "SortedListDoublyLinked.h"

template < class T >
class Hybrid
{

   private:
		// used for the easy way 
		// QueueLinked<T>* q;
      QueueLinked<DoubleNode<T> >* q;
      SortedListDoublyLinked<T>* sldl;

   public:
      Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
      ~Hybrid();

      bool isEmpty();
      void enqueue(T* item);
      T* dequeue();
      ListDoublyLinkedIterator<T>* iterator();

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
	// used for the easy way
	   //q = new QueueLinked<T>();
   q = new QueueLinked<DoubleNode<T> >();
   sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);
}

template < class T >
Hybrid<T>::~Hybrid()
{
   delete q;
   delete sldl;
}

template < class T >
bool Hybrid<T>::isEmpty()
{
	return sldl->isEmpty();
}

template < class T >
void Hybrid<T>::enqueue(T* item)
{
	//q->enqueue(item);
	DoubleNode<T>* node = sldl->addDN(item);
	q->enqueue(node);
}

template < class T >
T* Hybrid<T>::dequeue()
{
	DoubleNode<T>* curr = q->dequeue();
	T* item = sldl->remove(curr);
	return item;
	
	// Doing it the easy way...
	
	/*T* item = q->dequeue();
	sldl->remove(item->getKey());
	return item;*/
	
}

template < class T >
ListDoublyLinkedIterator<T>* Hybrid<T>::iterator()
{
	return sldl->iterator();
}
//DO THIS
//complete the implementation for the Hybrid ADT in two different ways
//as outlined in the Lab 10 description
//simply comment the first implementation out when working on the second implementation
//use the getKey method to dequeue/remove






#endif
