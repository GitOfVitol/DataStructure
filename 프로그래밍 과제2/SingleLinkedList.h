#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node* pNext;
};

template <typename T>
class SingleLinkedList {
public:
	/*
	*	default constructor.
	*/
	SingleLinkedList();

	/*
	*	destructor.
	*/
	~SingleLinkedList();

	/*
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/*
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/*
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/*
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	int GetNextItem(T& item);

	/*
	*	@brief	Add item into appropriate spot of this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T& item);

	/*
	*	@brief	Delete item from this list.
	*	@pre	List is not empty. the item exists in list.
	*	@post	Item is deleted from this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Delete(T& item);

	/*
	*	@brief	Change value of item which is in this list.
	*	@pre	List is not empty. the item exists in list.
	*	@post	Item's value is changed.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Replace(T& item);

	/*
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Retrieve(T& item);

	void operator=(const SingleLinkedList& _item) {
		Node<T>* tmp = _item.a_pFirst;
		//기존 노드 초기화
		MakeEmpty();

		//obj 리스트가 존재할 경우
		if (_item.GetLength()) {
			while (tmp != nullptr) {
				Add(tmp->data);
				tmp = tmp->pNext;
			}
		}

	}
	friend ostream& operator<<(ostream& os, const SingleLinkedList& _item) {
		Node<T>* tmp = _item.a_pFirst;

		while (tmp != nullptr) {
			os << tmp->data << endl;
			tmp = tmp->pNext;
		}

		return os;
	}
private:
	Node<T>* a_pFirst;
	Node<T>* a_pCurPointer;
	int a_length;
};

template <typename T>
SingleLinkedList<T>::SingleLinkedList() : a_length(0) {
	a_pFirst = nullptr;
	a_pCurPointer = nullptr;
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() { MakeEmpty(); }

template <typename T>
void SingleLinkedList<T>::MakeEmpty() {
	Node<T>* tempPtr;

	while (a_pFirst != nullptr) {
		tempPtr = a_pFirst;
		a_pFirst = a_pFirst->pNext;
		delete tempPtr;
	}

	a_length = 0;
}

template <typename T>
int SingleLinkedList<T>::GetLength() const { return a_length; }

template <typename T>
void SingleLinkedList<T>::ResetList() { a_pCurPointer = nullptr; }

template <typename T>
int SingleLinkedList<T>::GetNextItem(T& item) {
	if (a_pCurPointer == nullptr) {
		a_pCurPointer = a_pFirst;
		item = a_pCurPointer->data;
		return 0;
	}
	else { a_pCurPointer = a_pCurPointer->pNext; }

	item = a_pCurPointer->data;

	return 1;
}

template <typename T>
int SingleLinkedList<T>::Add(T& item) {
	ResetList();
	Node<T>* node = new Node<T>;
	Node<T>* pre;
	T dummy;

	node->data = item;
	node->pNext = nullptr;

	if (!a_length) {
		a_pFirst = node;
	}
	else {
		while (1) {
			pre = a_pCurPointer;
			GetNextItem(dummy);

			if (a_pCurPointer->data > node->data) {
				if (pre == nullptr) {
					node->pNext = a_pCurPointer;
					a_pFirst = node;
					break;
				}
				pre->pNext = node;
				node->pNext = a_pCurPointer;
				break;
			}

			if (a_pCurPointer->pNext == nullptr) {
				a_pCurPointer->pNext = node;
				break;
			}
		}
	}
	a_length++;
	return 1;

}

template  <typename T>
int SingleLinkedList <T>::Delete(T& item) {
	bool moreToSearch, isFind;
	Node<T>* pre = nullptr;
	a_pCurPointer = a_pFirst;

	isFind = false;
	moreToSearch = (a_pCurPointer != nullptr);

	while (moreToSearch && !isFind) {
		if (item == a_pCurPointer->data) {
			isFind = true;
			if (pre == nullptr) {
				a_pFirst = a_pCurPointer->pNext;
			}
			else {
				pre->pNext = a_pCurPointer->pNext;
				delete a_pCurPointer;
			}
			a_length--;
		}
		else {
			pre = a_pCurPointer;
			a_pCurPointer = a_pCurPointer->pNext;
			moreToSearch = (a_pCurPointer != nullptr);
		}
	}

	if (isFind) return 1;
	else return 0;
}

template <typename T>
int SingleLinkedList<T>::Replace(T& item) {
	bool moreToSearch, isFind;
	Node<T>* location;

	location = a_pFirst;
	isFind = false;
	moreToSearch = (location != nullptr);

	while (moreToSearch && !isFind) {
		if (item == location->data) {
			isFind = true;
			location->data = item;
		}
		else {
			location = location->pNext;
			moreToSearch = (location != nullptr);
		}
	}

	if (isFind) return 1;
	else return 0;
}

template <typename T>
int SingleLinkedList<T>::Retrieve(T& item) {
	bool moreToSearch, isFind;
	Node<T>* location;

	location = a_pFirst;
	isFind = false;
	moreToSearch = (location != nullptr);

	while (moreToSearch && !isFind) {
		if (item == location->data) {
			isFind = true;
			item = location->data;
		}
		else {
			location = location->pNext;
			moreToSearch = (location != nullptr);
		}
	}

	if (isFind) return 1;
	else return 0;
}