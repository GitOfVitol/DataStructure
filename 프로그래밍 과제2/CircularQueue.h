#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAXQUEUE 31

template <typename T>
class CircularQueue {
public:

	/*
	*	default constructor
	*/
	CircularQueue();

	/**
	*	@brief	constructor to determine max length of queue
	*	@pre	none
	*	@post	max length of queue is determined
	*	@param	max
	*/
	CircularQueue(int max);

	/*
	*	default destructor
	*/
	~CircularQueue();

	/*
	*	@brief	Determines whether the queue is full.(const)
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is full)
	*/
	bool IsFull() const;

	/*
	*	@brief	Determines whether the queue is empty.(const)
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is empty)
	*/
	bool IsEmpty() const;

	/*
	*	@brief	Makes the queue empty.(const)
	*	@pre	Queue has been initialized.
	*	@post	a_indexFront, a_curPointer, and a_indexRear are set same value as Constructer.
	*/
	void MakeEmpty();

	/*
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
	void EnQueue(T item);

	/*
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
	void DeQueue(T& item);

	/*
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void Print();

	/*
	*	@brief	Reset a_curPointer.
	*	@pre	none.
	*	@post	a_curPointer가 a_iFront 값으로 초기화된다.
	*/
	void ResetList();

	int GetNexItem(T& item);

	int Retrieve(T& item);

	int Delete(T& item);

	int Replace(T& item);

private:
	int a_indexFront; // front index of the circular queue
	int a_indexRear; // rear index of the circular queue
	int a_maxQueue; // maximum size of the circular quere
	int a_curPointer; // iterator pointer
	T* a_pItem; // pointer of item for dynamic allocation
};

template <typename T>
CircularQueue<T>::CircularQueue()
	: a_maxQueue(MAXQUEUE), a_indexFront(MAXQUEUE - 1), a_indexRear(MAXQUEUE - 1), a_curPointer(MAXQUEUE - 1) {
	a_pItem = new T[a_maxQueue];
}

template <typename T>
CircularQueue<T>::CircularQueue(int max)
	: a_maxQueue(max), a_indexFront(MAXQUEUE - 1), a_indexRear(MAXQUEUE - 1), a_curPointer(MAXQUEUE - 1) {
	a_pItem = new T[a_maxQueue];
}

template <typename T>
CircularQueue<T>::~CircularQueue() {
	delete[] a_pItem;
}

template <typename T>
bool CircularQueue<T>::IsFull() const {
	if (a_indexFront - a_indexRear == 1 || a_indexRear - a_indexFront == a_maxQueue - 1) return true;
	else return false;
}

template <typename T>
bool CircularQueue<T>::IsEmpty() const {
	if (a_indexFront == a_indexRear) return true;
	else return false;
}

template <typename T>
void CircularQueue<T>::MakeEmpty() {
	a_indexFront = a_maxQueue - 1;
	a_indexRear = a_maxQueue - 1;
	delete[] a_pItem;
	a_pItem = new T[a_maxQueue];
}

template <typename T>
void CircularQueue<T>::EnQueue(T item) {
	if (IsFull()) return;
	a_indexRear = (a_indexRear + 1) % a_maxQueue;
	a_pItem[a_indexRear] = item;
}

template <typename T>
void CircularQueue<T>::DeQueue(T& item) {
	if (IsEmpty()) return;
	a_indexFront = (a_indexFront + 1) % a_maxQueue;
	item = a_pItem[a_indexFront];
}

template <typename T>
void CircularQueue<T>::Print() {
	if (IsEmpty()) {
		return;
	}
	int start = (a_indexFront + 1) % a_maxQueue;
	for (start;; start = (start + 1) % a_maxQueue) {
		if (start == a_indexRear) {
			cout << a_pItem[start] << " " << endl;
			return;
		}
		else {
			cout << a_pItem[start] << " " << endl;
		}
	}
}

template <typename T>
void CircularQueue<T>::ResetList() { a_curPointer = a_indexFront; }

template <typename T>
int CircularQueue<T>::GetNexItem(T& item) {
	if (IsEmpty()) {
		return -1;
	}

	a_curPointer++;
	a_curPointer = a_curPointer % a_maxQueue;
	item = a_pItem[a_curPointer];
	if (a_curPointer == a_indexRear) {
		this->ResetList();
		return 0;
	}
	return 1;
}

template <typename T>
int CircularQueue<T>::Retrieve(T& item) {
	if (IsEmpty()) {
		return -1;
	}
	ResetList();
	a_curPointer++;
	a_curPointer = a_curPointer % a_maxQueue;

	while (1) {
		if (item == a_pItem[a_curPointer]) {
			item = a_pItem[a_curPointer];
			return a_curPointer;
		}
		else {
			if (a_curPointer == a_indexRear) return -1;
			else {
				a_curPointer++;
				a_curPointer = a_curPointer % a_maxQueue;
			}
		}
	}

}

template <typename T>
int CircularQueue<T>::Delete(T& item) {
	if (Retrieve(item) == -1) return 0;
	else {
		if (a_curPointer == a_indexRear) {
			int tempCurPointer = a_curPointer;
			a_curPointer++;
			a_curPointer = a_curPointer % a_maxQueue;
			a_pItem[tempCurPointer] = a_pItem[a_curPointer];
			a_indexRear--;
			a_indexRear = (a_indexRear + a_maxQueue) % a_maxQueue;
			return 1;
		}
		else {
			while (1) {
				int tempCurPointer = a_curPointer;
				a_curPointer++;
				a_curPointer = a_curPointer % a_maxQueue;
				a_pItem[tempCurPointer] = a_pItem[a_curPointer];

				if (a_curPointer == a_indexRear) {
					a_indexRear--;
					a_indexRear = (a_indexRear + a_maxQueue) % a_maxQueue;
					return 1;
				}
			}
		}
	}
}

template <typename T>
int CircularQueue<T>::Replace(T& item) {
	if (IsEmpty()) {
		return -1;
	}
	ResetList();
	a_curPointer++;
	a_curPointer = a_curPointer % a_maxQueue;

	while (1) {
		if (item == a_pItem[a_curPointer]) {
			a_pItem[a_curPointer] = item;
			return a_curPointer;
		}
		else {
			if (a_curPointer == a_indexRear) return -1;
			else {
				a_curPointer++;
				a_curPointer = a_curPointer % a_maxQueue;
			}
		}
	}
}