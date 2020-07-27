#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define ADDSIZE 3

template <typename T>
class UnsortedList {
public:
	/*
		default constructor
	*/
	UnsortedList();

	/*
		constructor
	*/
	UnsortedList(int maxSize);

	/*
			destructor
	*/
	~UnsortedList();

	/*
		brief : make list empty
		pre : none
		post : length of list is 0
	*/
	void MakeEmpty();

	/*
		brief : get a number of records in list
		pre : none
		post : none
		return : a number of records
	*/
	int GetLength();

	/*
		brief : to know availability of list wheather is full or not
		pre : none
		post : none
		return : true if list is full / false if list is not full
	*/
	bool IsFull() const;

	/*
		brief : to check array is empty
		pre : none
		post : none
		return : return true if array is empty otherwise return false
	*/
	bool IsEmpty() const;

	/*
		brief : make list iterator -1
		pre : list must be initialized
		post : iterator is initialized
	*/
	void ResetList();

	/*
		brief : move iterator to next and get that data
		pre : list and list iterator must not be initialized.
		post : iterator moves to next list data
		return : return index of current list but if iterator is at the end of list, return -1
	*/
	int GetNextItem(T& data);

	/*
		brief : add a data into list
		pre : list must be initialized
		post : add a new record into list
		param : data
		return : return 1 if this function works well otherwise return 0
	*/
	int Add(T& data);

	/*
		brief : get data using primary key
		pre : primary key in array should be initialized
		post : if found, all of elements is copied in item, otherwise item is unchanged
		return : return current pointer if you find otherwise return -1
	*/
	int Retrieve(T& data);

	/*
		brief : delete data if primary key is same
		pre : primary key should be initialized
		post : key that is matches should be deleted
		return : return 1 if succeed to delete otherwise return 0
	*/
	int Delete(T data);

	/*
		brief : replace data if primary key is same
		pre : primary key should be initialized
		post : key that is matches should be replaced
		return : return 1 if succeed to replace otherwise return 0
	*/
	int Replace(T& data);

	int Replace(T& data, T& item);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	copy all elements to otherItem(복사 대입 연산자, 깊은복사)
	*	@param	rhs
	*/
	void operator=(const UnsortedList& rhs) {
		delete[] a_array;
		a_length = rhs.a_length;
		a_curPointer = rhs.a_curPointer;
		a_maxSize = rhs.a_maxSize;
		a_array = new T[a_maxSize];
		for (int i = 0; i < a_length; i++) {
			a_array[i] = rhs.a_array[i];
		}
	}

	friend ostream& operator<<(ostream& os, const UnsortedList& _item) {
		for (int i = 0; i < _item.a_length; i++)
		{
			os << "\t" << _item.a_array[i] << endl;
		}
		return os;
	}


private:
	T* a_array; // list array
	int a_length; // a number of records of list
	int a_curPointer; // iterator
	int a_maxSize; // max size
};

template <typename T>
UnsortedList <T>::UnsortedList() : a_length(0), a_maxSize(ADDSIZE) {
	ResetList();
	a_array = new T[a_maxSize];
}

template <typename T>
UnsortedList <T>::UnsortedList(int maxSize) : a_length(0), a_maxSize(maxSize) {
	ResetList();
	a_array = new T[a_maxSize];
}

template <typename T>
UnsortedList <T>::~UnsortedList() { delete[] a_array; }

template <typename T>
void UnsortedList <T>::MakeEmpty() { a_length = 0; }

template <typename T>
int UnsortedList <T>::GetLength() { return a_length; }

template <typename T>
bool UnsortedList <T>::IsFull() const {
	if (a_length >= a_maxSize) return true;
	else return false;
}

template <typename T>
bool UnsortedList <T>::IsEmpty() const {
	if (a_length == 0) return true;
	else return false;
}

template <typename T>
void UnsortedList <T>::ResetList() { a_curPointer = -1; }

template <typename T>
int UnsortedList <T>::GetNextItem(T& data) {
	a_curPointer++;
	if (a_curPointer <= a_maxSize - 1) {
		data = a_array[a_curPointer];
		return a_curPointer;
	}
	else return -1;
}

template <typename T>
int UnsortedList <T>::Add(T& data) {
	if (IsFull()) {
		T* tempList = new T[a_length];
		for (int i = 0; i < a_length; i++) {
			tempList[i] = a_array[i];
		}
		delete[] a_array;

		a_maxSize += ADDSIZE;
		a_array = new T[a_maxSize];
		for (int i = 0; i < a_length; i++) {
			a_array[i] = tempList[i];
		}
		delete[] tempList;
	}
	a_array[a_length] = data;
	a_length++;

	return 1;
}

template <typename T>
int UnsortedList <T>::Retrieve(T& data) {
	for (int i = 0; i < a_length; i++) {
		if (a_array[i] == data) {
			data = a_array[i];
			return 1;
		}
	}
	return 0;
}

template <typename T>
int UnsortedList <T>::Delete(T data) {
	for (int i = 0; i < a_length; i++) {
		if (a_array[i] == data) {
			for (int j = i; j < a_length - 1; j++) {
				a_array[j] = a_array[j + 1];
			}
			a_length--;
			return 1;
		}
	}
	return 0;
}

template <typename T>
int UnsortedList <T>::Replace(T& data) {
	for (int i = 0; i < a_length; i++) {
		if (a_array[i] == data) {
			a_array[i] = data;
			return 1;
		}
	}

	return 0;
}

template <typename T>
int UnsortedList <T>::Replace(T& data, T& item) {
	for (int i = 0; i < a_length; i++) {
		if (a_array[i] == data) {
			a_array[i] = item;
			return 1;
		}
	}

	return 0;
}