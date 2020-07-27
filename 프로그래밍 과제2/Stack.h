#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define MAXSTACK 30

template <typename T>
class Stack
{
private:
	int m_iTop;			///< Number of elements.
	int m_nMaxStack;	///< max size of the stack.
	int m_CurPointer;	///< iterator pointer.
	T* m_pItems;		///< Pointer for a stack.

public:
	Stack();
	Stack(int max);
	~Stack();

	/**
	*	@brief	Determines whether the stack is full.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (stack is full)
	*/
	bool IsFull() const;

	/**
	*	@brief	Determines whether the stack is empty.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (stack is empty)
	*/
	bool IsEmpty() const;

	/**
	*	@brief	Adds newItem to the top of the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is full), FullStack exception is thrown; otherwise, newItem is at the top of the stack.
	*/
	int Push(T item);

	/**
	*	@brief	Removes top item from the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is empty), EmptyStack exception is thrown; otherwise, top element has been removed from stack.
	*/
	int Pop(T& item);

	/**
	*	@brief	Returns a copy of top item on the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is empty), EmptyStack exception is thrown; otherwise, top element has been removed from stack.
	*/
	int Top(T& item);

	/**
	*	@brief	Print all the items in the stack on screen
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void Print();

	/**
	*	@brief	Reset m_CurPointer.
	*	@pre	none.
	*	@post	m_CurPointer가 m_iFront 값으로 초기화된다.
	*/
	void ResetCurrentPointer();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& item);
};

// Allocate dynamic array whose size is MAXSTACK.
template<typename T>
inline Stack<T>::Stack()
{
	m_nMaxStack = MAXSTACK;
	m_pItems = new T[m_nMaxStack];
	m_iTop = -1;
	m_CurPointer = -1;
}

// Allocate dynamic array whose size is max.
template<typename T>
inline Stack<T>::Stack(int max)
{
	m_nMaxStack = max;
	m_pItems = new T[m_nMaxStack];
	m_iTop = -1;
}

// Destruct the object. Free the array dynamically allocated.
template<typename T>
inline Stack<T>::~Stack()
{
	delete[] m_pItems;
}

// Determines whether the stack is full.
template<typename T>
inline bool Stack<T>::IsFull() const
{
	if (m_iTop >= m_nMaxStack - 1)
		return true;
	else
		return false;
}

// Determines whether the stack is empty.
template<typename T>
inline bool Stack<T>::IsEmpty() const
{
	if (m_iTop <= -1)
		return true;
	else
		return false;
}

// Adds newItem to the top of the stack.
template<typename T>
inline int Stack<T>::Push(T item)
{
	if (IsFull())
		return -1;
	else
	{
		m_iTop++;
		m_pItems[m_iTop] = item;
		return m_iTop;
	}
}

// Removes top item from the stack.
template<typename T>
inline int Stack<T>::Pop(T& item)
{
	if (IsEmpty())
		return -1;
	else
	{
		item = m_pItems[m_iTop--];
		return m_iTop;
	}
}

// Gets top item from the stack.
template<typename T>
inline int Stack<T>::Top(T& item)
{
	if (IsEmpty())
		return -1;
	else
	{
		item = m_pItems[m_iTop];
		return m_iTop;
	}
}

// Print all the items in the stack on screen
template<typename T>
inline void Stack<T>::Print()
{
	cout << "Stack: ";
	// Stack 내의 모든 element 출력.
	for (int i = m_iTop; i >= 0; i--)
	{
		cout << m_pItems[i] << " - ";
	}
	cout << endl;
}

template<typename T>
inline void Stack<T>::ResetCurrentPointer()
{
	m_CurPointer = -1;
}

template<typename T>
inline int Stack<T>::GetNextItem(T& item)
{
	m_CurPointer++;
	if (m_CurPointer == m_nMaxStack)
		return -1;
	item = m_pItems[m_CurPointer];

	return m_CurPointer;
}