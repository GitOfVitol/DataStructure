#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "DoublySortedLinkedList.h"

template <typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

template <typename T>
class DoublyIterator {
	friend class DoublySortedLinkedList<T>;

public:
	DoublyIterator(const DoublySortedLinkedList<T>& list) : a_List(list), a_pCurPointer(list.pFirst) {}

	bool NotNull();
	bool NextNotNull();
	T First();
	T Next();
	DoublyNodeType<T> GetCurrentNode();
private:
	const DoublySortedLinkedList<T>& a_List;
	DoublyNodeType<T>* a_pCurPointer;
};

template <typename T>
bool DoublyIterator<T>::NotNull() {
	if (a_pCurPointer == NULL) return false;
	else return true;
}

template <typename T>
bool DoublyIterator<T>::NextNotNull() {
	if (a_pCurPointer->next == NULL) return false;
	else return true;
}

template <typename T>
T DoublyIterator<T>::First() { return a_List.pFirst->data; }

template <typename T>
T DoublyIterator<T>::Next() {
	a_pCurPointer = a_pCurPointer->next;
	return a_pCurPointer->data;
}

template <typename T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode() { return *a_pCurPointer; }

#endif _DOUBLYITERATOR_H