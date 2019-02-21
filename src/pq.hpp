#pragma once

#include <cstddef>  // Include to use NULL, otherwise use nullptr
#include <iostream>
#include "node.hpp"

template<class T>
class PQ{
private:
    Node<T> *head;          // the pointer to the front of the list
    Node<T> *tail;          // the pointer to the back of the list
    int count;

public:
    // desc: Inializes a new, empty queue
	PQ();

	Node<T>* makeNode(T val, int priority, Node<T>* nextNode);

    // desc:    Adds new data to the queue
    // param:   data The data to add to the list
    // param:   priority The priority assigned to this node
    // returns: void
	void enqueue(T &data, int priority);

    // desc:    Removes the front element form the queue
    // returns: void
	void dequeue(void);   

    // desc:    Removes the value found at the front of the queue
    // returns: The data found at the front of the queue
    T get_front(void); 

    // desc:    Checks if the queue is empty or not
    // returns: true is the queue is empty, false if not
    bool isEmpty(void);

    // desc:    Clears the queue
    // returns: void
    void clear(void);

    // desc:    Returns the number of elements in the queue
    // returns: The number of elements in the queue
    int get_count(void);
};

template<class T>
PQ<T>::PQ()
{
	head = NULL;
    tail = NULL;
    count = 0;
}

template<class T>
void PQ<T>::enqueue(T &data, int priority)
{
    Node<T> *new_node = new Node<T>(data, priority);

	Node<T>* newNode = new Node<T>(data, priority);
	newNode->set_data(data);

	Node<T>** dblNodePtr = &(this->head);

	// TODO make sure this works properly
	while(*dblNodePtr && (*dblNodePtr)->priority < priority)
		dblNodePtr = &(*dblNodePtr)->next;


	*dblNodePtr = makeNode(data, priority, &(**dblNodePtr));
}

template<class T>
void PQ<T>::dequeue(void)
{
	if(!this->head) return;

	Node<T>* toShift = this->head->next;
	delete this->head;
	this->head = toShift;
}

template<class T>
T  PQ<T>::get_front()
{
	if (this->head) {
		return this->head->get_data();
	}
	return 0;
}

template<class T>
bool PQ<T>::isEmpty()
{
	return this->head == NULL;
}

template<class T>
void PQ<T>::clear(void)
{
	while(this->head)
	{
		Node<T>* toDelete = this->head;
		this->head = this->head->next;
		delete toDelete;
	}
}


template<class T>
int PQ<T>::get_count(void)
{
	unsigned int count = 0;

	Node<T>* node = this->head;
	while (node) {
		node = node->get_next();
		count++;
	}
	return count;
}

template<class T>
Node<T>* PQ<T>::makeNode(T val, int priority, Node<T>* nextNode)
{
	Node<T>* madeNode = new Node<T>(val, priority);
	madeNode->set_next(nextNode);
	return madeNode;
}
