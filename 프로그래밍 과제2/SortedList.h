#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define MAXSIZE 10
#define ADDSIZE 3

template <typename T>
class SortedList {
public:

	/*
		default constructor
	*/
	SortedList();

	/*
		destructor
	*/
	~SortedList();


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
		brief : add a data into list
		pre : list must be initialized
		post : add a new record into list
		param : data
		return : return 1 if this function works well otherwise return 0
	*/
	int Add(T& data);

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
		brief : get data using primary key
		pre : primary key in array should be initialized
		post : if found, all of elements is copied in item, otherwise item is unchanged
		return : return 1 if you find otherwise return 0
	*/
	int RetrieveSeq(T& data);

	/*
		brief : get data using primary key by binary search
		pre : primary key in array should be initialized
		post : if found, all of elements is copied in item, otherwise item is unchanged
		return : return 1 if you find otherwise return 0
	*/
	int RetrieveBin(T& data);

	/*
		brief : delete data if primary key is same
		pre : primary key should be initialized
		post : key that is matches should be deleted
		return : return 1 if succeed to delete otherwise return 0
	*/
	int Delete(T data);

	/*
		brief : replace data if primary key is same(binary search)
		pre : primary key should be initialized
		post : key that is matches should be replaced
		return : return 1 if succeed to replace otherwise return 0
	*/
	int Replace(T& data);

	void operator=(const SortedList& _item) {
		delete[] a_array;
		a_length = _item.a_length;
		a_curPointer = _item.a_curPointer;
		a_maxSize = _item.a_maxSize;
		a_array = new T[a_maxSize];
		for (int i = 0; i < a_length; ++i) {
			a_array[i] = _item.a_array[i];
		}
	}
	friend ostream& operator<<(ostream& os, const SortedList& _item) {
		for (int i = 0; i < _item.a_length; i++)
		{
			os << _item.a_array[i] << endl;
			os << "\t------------------------------------" << endl << endl;
		}
		return os;
	}
private:
	T* a_array; //list array
	int a_length; //a number of records of list
	int a_curPointer; //iterator
	int a_maxSize; // maxsize
};

template <typename T>
SortedList<T>::SortedList() : a_length(0), a_maxSize(ADDSIZE) {
	ResetList();
	a_array = new T[a_maxSize];
}

template <typename T>
SortedList<T>::~SortedList() {
	delete[] a_array;
}

template <typename T>
void SortedList<T>::MakeEmpty() { a_length = 0; }

template <typename T>
int SortedList<T>::GetLength() { return a_length; }

template <typename T>
bool SortedList<T>::IsFull() const {
	if (a_length >= a_maxSize) return true;
	else return false;
}

template <typename T>
bool SortedList<T>::IsEmpty() const {
	if (a_length == 0) return true;
	else return false;
}

//add item to sorted list
template <typename T>
int SortedList<T>::Add(T& data) {
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
	}//

	if (IsEmpty()) {
		a_array[a_length++] = data;
		return 1;
	}//if list is empty, put data and length++, return 1
	else {
		for (int i = 0; i < a_length; i++) {
			if (a_array[i] < data) {
				if (i == a_length - 1) {
					a_array[a_length] = data;
					a_length++;
					return 1;
				}

			}
			else if (a_array[i] > data) {
				for (int j = a_length; j > i; j--) {
					a_array[j] = a_array[j - 1];
				}
				a_array[i] = data;
				a_length++;
				return 1;
			}
			else {
				cout << "\n\tThere is already same Item!" << endl;
				return 0;
			}
		}
	}
	return 0;

}

template <typename T>
void SortedList<T>::ResetList() { a_curPointer = -1; }

//배열의 다음 인덱스의 아이템과 curPointer를 넘겨줌
template <typename T>
int SortedList<T>::GetNextItem(T& data) {
	a_curPointer++;
	if (a_curPointer <= a_maxSize - 1) {
		data = a_array[a_curPointer];
		return a_curPointer;
	}
	else return -1;
}

//sequential search로 배열 내 item 접근
template <typename T>
int SortedList<T>::RetrieveSeq(T& data) {

	for (a_curPointer = 0; a_curPointer < a_length; a_curPointer++) {
		if (data == a_array[a_curPointer]) {
			data = a_array[a_curPointer];
			return 1; //primary key를 비교해서 같으면 data에 원래 itemtype객체 복사
		}
		else if (data < a_array[a_curPointer]) {
			cout << "\tThere is no item you search!" << endl;
			return 0;
		}//입력받은 primary key가 index가 0인 것보다 작으면 바로 return 0
	}
	return 0;
}

//binary search로 배열 내 아이템 접근
template <typename T>
int SortedList<T>::RetrieveBin(T& data) {
	if (IsEmpty()) return 0;
	int start = 0; //배열의 시작점
	int last = a_length - 1; //배열의 끝점
	int mid = (start + last) / 2; //binary search를 위한 중간 점 계산
	for (mid; last >= 0; mid = (start + last) / 2) {
		if (data == a_array[mid]) {
			data = a_array[mid];
			a_curPointer = mid;
			return 1;
		}//primary key가 같으면 data에 현재 item 복사, curPointer도 복사
		else if (data < a_array[mid]) {
			if (last == 0) return 0;
			else if (start == a_length - 1) return 0;
			last = mid - 1;
		}//last가 배열의 시작 index 되면 실패 return 0, 그 전엔 mid-1
		else if (data > a_array[mid]) {
			if (start == a_length - 1) return 0;
			else if (last == 0) return 0;
			start = mid + 1;
		}//start가 배열의 끝 index가 되면 실패 return 0, 그 전엔 mid+1

	}

	return 0;
}

//binary search로 primary key비교 후 같으면 매개변수로 받은 아이템으로 교체
template <typename T>
int SortedList<T>::Replace(T& data) {
	for (a_curPointer = 0; a_curPointer != -1 && a_curPointer < a_length; a_curPointer++) {
		if (data == a_array[a_curPointer]) {
			a_array[a_curPointer] = data;
			return 1; //primary key를 비교해서 같으면 data에 원래 itemtype객체 복사
		}
	}
	return 0;
}

//sequential search로 primary key 같으면 해당 아이템 삭제, length--
template <typename T>
int SortedList<T>::Delete(T data) {
	if (RetrieveSeq(data)) {
		if (a_length == 1) {
			a_array[0] = a_array[1];
		}
		for (a_curPointer; a_curPointer < a_length - 1; a_curPointer++) {
			a_array[a_curPointer] = a_array[a_curPointer + 1];
		}
		a_length--;
		return 1;
	}
	return 0;
}