#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "ItemType.h"
#include "CircularQueue.h"

class TempType {
public:
	/*
		default constructor
	*/
	TempType();

	/*
		destructor
	*/
	~TempType();

	/*
	*	@brief	Get total num of Items in TempList
	*	@pre	total num of Items in TempList is set.
	*	@post	none.
	*	@return	total num of Items in TempList
	*/
	int GetNumOfItems();

	/*
	*	@brief	Enqueue new record into tempItemList. (You don't know container - where to put)
	*	@pre	list should be initialized.
	*	@post	new record is Enqueued into the tempItemList.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItemToQueue(ItemType data);

	/*
	*	@brief	Dequeue new record from tempItemList.
	*	@pre	list should be initialized.
	*	@post	new record is Dequeued from the tempItemList.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DequeueFromQueue(ItemType& data);

	int RetrieveItemFromQueue(ItemType& data);

	int DeleteItemFromQueue(ItemType& data);

	/*
	*	@brief	Display total num of Items in TempList
	*	@pre	total num of Items in TempList is set.
	*	@post	total num of Items in TempList is on screen.
	*/
	void PrintNumOfItems();

	/*
	*	@brief	Display all Items in TempList
	*	@pre	all Items in TempList is set.
	*	@post	all Items in TempList is on screen.
	*/
	void PrintAllItemInQueue();

	int GetNextTempItem(ItemType& item);

	void ResetTempList();

	int ReplaceItemFromQueue(ItemType& data);

private:
	int numOfItems; // Total number of Item in TempList
	CircularQueue <ItemType>tempItemList; // TempList using CircularQueue
};