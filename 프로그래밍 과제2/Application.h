#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define FILENAMESIZE 1024
#include "SortedList.h"
#include "TempType.h"
#include "ContainerType.h"
#include "StorageType.h"
#include "Base.h"

class Application :public Base {
	friend class AddToMasterWindow;
	friend class DisplayTempListWindow;
	friend class DisplayStorageTempWindow;
	friend class SearchTempListWindow;
	friend class DisplayStoSimItemWindow;
	friend class AddStorageContainerWindow;
	friend class DisplayStoDetailItemWindow;
	friend class AddTempToMaster1stItemWindow;
	friend class AddTempToMasterWindow;

public:

	/*
		default constructor
	*/
	Application() : m_Command(0) {}

	/*
	*	destructor
	*/
	~Application() {}


	/*
	*	@brief	Add new record into MasterList.(You know container to put)
	*	@pre	list should be initialized.
	*	@post	new record is added into the MasterList.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddToMasterList(ItemType& item);

	/*
	*	@brief	Add new record into TempList. (You don't know container - where to put)
	*	@pre	list should be initialized.
	*	@post	new record is added into the TempList.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddToTempList(ItemType& item);

	/*
	*	@brief	retrieve using primary key from TempList and type where to put. after that add to MasterList
	*	@pre	list should be initialized.
	*	@post	record of TempList and additional container id are added into the MasterList.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddTempToMasterUsingPrimary(ItemType& item);

	/*
	*	@brief	Add new record into TempList from MasterList. (You don't know container - where to put)
	*	@pre	list should be initialized.
	*	@post	new record is added into the TempList.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddMasterToTemp(ItemType& item);

	/*
	*	@brief	delete record from masterlist
	*	@pre	masterlist should be initialized.
	*	@post	record is deleted if primary key matches
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteItemFromMaster(ItemType& item);


	/*
	*	@brief	delete record from templist
	*	@pre	templist should be initialized.
	*	@post	record is deleted if primary key matches
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DequeueItemFromTemp(ItemType& item);

	/*
	*	@brief	delete record from templist
	*	@pre	templist should be initialized.
	*	@post	record is deleted if primary key matches
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteItemFromTemp(ItemType& item);

	/*
	*	@brief	replace record from list
	*	@pre	list should be initialized.
	*	@post	record is replaced if primary key matches
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReplaceItem(ItemType& item);

	int ReplaceTempList(ItemType& item);

	/*
	*	@brief	Display all records int list. You have 2 options.(MasterList, TempList)
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/*
	*	@brief	Display all records in the MasterList on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void PrintAllMasterList();

	/*
	*	@brief	Display all records in the TempList on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void PrintAllTempList();

	/*
	*	@brief	Display all storage id in the StorageLIst on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllStorage();

	/*
	*	@brief	Display all container in the StorageList on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllContainer();

	/*
	*	@brief	Display all container in detail in the StorageList on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllDetailsContainer();

	/*
	*	@brief	Display certain container in the StorageList on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayContainer();

	/*
	*	@brief	Display all photo in the ContainerList on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllPhoto();

	/*
		brief : make simpleitemlist and masterlist empty
		pre : none
		post : length of list is 0
	*/
	void MakeEmptyLIst();

	/*
	*	@brief	Add new photo into list. You have 2 options.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void AddPhoto();

	/*
	*	@brief	Delete new photo into list. You have 2 options.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void DeletePhoto();

	/*
	*	@brief	Update new photo into list. You have 2 options.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void UpdatePhoto();

	/*
	*	@brief	Add new photo into Storagelist.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void AddPhotoOfStorage();

	/*
	*	@brief	Delete new photo into Storagelist.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void DeletePhotoOfStorage();

	/*
	*	@brief	Update new photo into Storagelist.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void UpdatePhotoOfStorage();

	/*
	*	@brief	Add new photo into Containerlist.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void AddPhotoOfContainer();

	/*
	*	@brief	Delete new photo into Containerlist.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void DeletePhotoOfContaienr();

	/*
	*	@brief	Update new photo into Containerlist.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void UpdatePhotoOfContainer();

	/*
	*	@brief	Update new Location into list. You have 2 options.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void UpdateLocation();

	/*
	*	@brief	Update new photo into StorageList.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void UpdateStorageLocation();

	/*
	*	@brief	Update new photo into ContainerList.
	*	@pre	list should be initialized.
	*	@post	new photo is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void UpdateContainerLocation();

	/*
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char* fileName);

	/*
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char* fileName);

	/*
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/*
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	int GetStorageLength();

	int AddStorageContainerInfo(StorageType& storage, ContainerType& container);


private:
	ifstream m_InFile; //input file descriptor.
	ofstream m_OutFile;	//output file descriptor.
	TempType TempList; // TempList
	SortedList <StorageType>StorageList; //StorageList
	int m_Command; //current command number.
	ItemType tempItem;
	StorageType tempStorage;
	ContainerType tempContainer;
	SimpleItemType tempSimpleItem;
};