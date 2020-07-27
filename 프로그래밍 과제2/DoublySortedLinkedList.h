#pragma once
#ifndef _DOUBLYSORTEDLINKEDLIST_H
#define _DOUBLYSORTEDLINKEDLIST_H
#include "DoublyIterator.h"

template<typename T>
class DoublyIterator;

template <typename T>
struct DoublyNodeType {
	T data;
	DoublyNodeType* prev;
	DoublyNodeType* next;
};

template <typename T>
class DoublySortedLinkedList {
	friend class DoublyIterator<T>;

public:
	DoublySortedLinkedList();
	~DoublySortedLinkedList();

	bool IsEmpty();
	bool IsFull();
	void MakeEmpty();
	int GetLength() const;

	int Add(T& item);
	int Delete(T& item);
	int Replace(T& item);
	int Retrieve(T& item);

	void operator=(const DoublySortedLinkedList& _item) {
		DoublyIterator<T> tmp(_item);
		tmp.Next();
		MakeEmpty();

		if (_item.GetLength()) {
			while (tmp.a_pCurPointer != pLast) {
				Add(tmp.a_pCurPointer->data);
				tmp.Next();
			}
		}

	}
	friend ostream& operator<<(ostream& os, const DoublySortedLinkedList& _item) {
		DoublyIterator<T> tmp(_item);
		tmp.Next();

		while (tmp.NextNotNull()) {
			os << tmp.a_pCurPointer->data << endl;
			tmp.Next();
		}

		return os;
	}
private:
	DoublyNodeType<T>* pFirst;
	DoublyNodeType<T>* pLast;
	int a_length;
};

template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList() : a_length(0) {
	pFirst = new DoublyNodeType<T>;
	pLast = new DoublyNodeType<T>;

	pFirst->next = pLast;
	pFirst->prev = NULL;

	pLast->prev = pFirst;
	pLast->next = NULL;
}

template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList() {
	delete pFirst;
	delete pLast;
}

template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty() {
	if (a_length == 0) return true;
	else return false;
}

template <typename T>
bool DoublySortedLinkedList<T>::IsFull() {
	if (a_length == 10) return true;
	else return false;
}

template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty() {
	DoublyNodeType<T>* curItem;
	DoublyIterator<T> iterator(*this);
	iterator.Next();

	while (iterator.NextNotNull()) {
		curItem = iterator.a_pCurPointer;
		iterator.Next();
		delete curItem;
	}

	pFirst->next = pLast;
	pFirst->prev = NULL;
	pLast->prev = pFirst;
	pLast->next = NULL;

	return;
}

template <typename T>
int DoublySortedLinkedList<T>::GetLength() const { return a_length; }

template <typename T>
int DoublySortedLinkedList<T>::Add(T& item) {
	DoublyIterator<T> iterator(*this);
	iterator.Next();

	if (IsEmpty()) {
		DoublyNodeType<T>* curItem = new DoublyNodeType<T>;
		curItem->data = item;
		curItem->prev = pFirst;
		curItem->next = pLast;
		pFirst->next = curItem;
		pLast->prev = curItem;
		a_length++;
		return 1;
	}
	else {
		while (1) {
			if (item < iterator.a_pCurPointer->data || !iterator.NextNotNull()) {
				DoublyNodeType<T>* curItem = new DoublyNodeType<T>;
				curItem->data = item;
				curItem->prev = iterator.a_pCurPointer->prev;
				curItem->next = iterator.a_pCurPointer;
				iterator.a_pCurPointer->prev->next = curItem;
				iterator.a_pCurPointer->prev = curItem;
				a_length++;
				return 1;
			}
			else if (item == iterator.a_pCurPointer->data) { return 0; }
			else { iterator.Next(); }
		}
	}
}

template <typename T>
int DoublySortedLinkedList<T>::Delete(T& item) {
	DoublyIterator<T> iterator(*this);
	iterator.Next();

	while (iterator.a_pCurPointer != pLast) {
		if (item == iterator.a_pCurPointer->data) {
			DoublyNodeType<T>* curItem = new DoublyNodeType<T>;
			curItem = iterator.a_pCurPointer;
			iterator.Next();
			curItem->prev->next = iterator.a_pCurPointer;
			iterator.a_pCurPointer->prev = curItem->prev;
			delete curItem;
			a_length--;
			return 1;
		}
		else { iterator.Next(); }
	}
	return 0;
}

template <typename T>
int DoublySortedLinkedList<T>::Replace(T& item) {
	DoublyIterator<T> iterator(*this);
	iterator.Next();

	while (iterator.a_pCurPointer != pLast) {
		if (item == iterator.a_pCurPointer->data) {
			iterator.a_pCurPointer->data = item;
			return 1;
		}
		else { iterator.Next(); }
	}
	return 0;
}

template <typename T>
int DoublySortedLinkedList<T>::Retrieve(T& item) {
	DoublyIterator<T> iterator(*this);
	iterator.Next();

	while (iterator.a_pCurPointer != pLast) {
		if (item == iterator.a_pCurPointer->data) {
			item = iterator.a_pCurPointer->data;
			return 1;
		}
		else { iterator.Next(); }
	}

	return 0;
}

#endif _DOUBLYSORTEDLINKEDLIST_H