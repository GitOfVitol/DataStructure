#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "UnsortedList.h"
#include "SimepleItemType.h"
#include "Base.h"

class ContainerType :public Base {
	friend class DisplayStoSimItemWindow;
	friend class DisplayStorageTempWindow;

public:
	/*
		default constructor
	*/
	ContainerType();

	/*
		destructor
	*/
	~ContainerType();

	int GetSimpleListLength();

	/*
	*	@brief	Get container Id
	*	@pre	container Id is set.
	*	@post	none.
	*	@return	container Id
	*/
	int GetContainerId() const;

	/*
	*	@brief	Get location
	*	@pre	location is set.
	*	@post	none.
	*	@return	location
	*/
	string GetLocation() const;

	/*
	*	@brief	Set container id
	*	@pre	none.
	*	@post	container id is set.
	*	@param	 container id
	*/
	void SetContainerId(int containerId);

	/*
	*	@brief	Set container id from keyboard.
	*	@pre	none.
	*	@post	container id is set.
	*/
	void SetContainerIdFromKB();

	/*
	*	@brief	Set location
	*	@pre	none.
	*	@post	location is set.
	*	@param	location
	*/
	void SetConLocation(string inlocation);

	/*
	*	@brief	Set location from keyboard.
	*	@pre	none.
	*	@post	location is set.
	*/
	void SetConLocationFromKB();

	/*
	*	@brief	make empty simleitemlist
	*	@pre	none.
	*	@post	simpleitemlist is empty
	*/
	void MakeItemEmpty();

	/*
		@brief : add a simpleitemtype into list
		@pre : list must be initialized
		@post : add a new simpleitemtype into list
		@param : data
		@return : return 1 if this function works well otherwise return 0
	*/
	int AddItem(SimpleItemType& item);

	/*
		@brief : delete a simpleitemtype into list
		@pre : list must be initialized
		@post : delete a simpleitemtype into list
		@param : data
		@return : return 1 if this function works well otherwise return 0
	*/
	int DeleteItem(SimpleItemType& item);

	/*
		@brief : replace a simpleitemtype into list
		@pre : list must be initialized
		@post : replace a simpleitemtype into list
		@param : data
		@return : return 1 if this function works well otherwise return 0
	*/
	int UpdateItem(SimpleItemType& item);


	/*
		@brief : add a photo into list
		@pre : list must be initialized
		@post : add a photo into list
		@param : inPhoto
		@return : return 1 if this function works well otherwise return 0
	*/
	int AddPhoto(string& inPhoto);

	/*
		@brief : delete a photo into list
		@pre : list must be initialized
		@post : delete a photo into list
		@param : inPhoto
		@return : return 1 if this function works well otherwise return 0
	*/
	int DeletePhoto(string& inPhoto);

	/*
		@brief : replace a photo into list
		@pre : list must be initialized
		@post : replace a photo into list
		@param : inPhoto, updatePhoto
		@return : return 1 if this function works well otherwise return 0
	*/
	int UpdatePhoto(string& inPhoto, string& updatePhoto);

	/*
	*	@brief	Display container id of article on screen.
	*	@pre	container id of article is set.
	*	@post	container id of article is on screen.
	*/
	void DisplayContainerId();

	/*
	*	@brief	Display location on screen.
	*	@pre	location is set.
	*	@post	location is on screen.
	*/
	void DisplayLocation();

	/*
	*	@brief	Display all simpleitemlist on screen.
	*	@pre	simpleitemlist is set.
	*	@post	simpleitemlist is on screen.
	*/
	void DisplayAllItem();

	/*
	*	@brief	Display all simpleitemlist on screen, ref MasterList
	*	@pre	simpleitemlist is set.
	*	@post	simpleitemlist is on screen.
	*/
	void DisplayDetailsAllItem(DoublySortedLinkedList<ItemType>& ref);

	/*
	*	@brief	Display all photos on screen.
	*	@pre	photos are set.
	*	@post	photos are on screen.
	*/
	void DisplayAllPhoto();

	/*
	*	@brief	get record from simpleitemlist using name and display on screen
	*	@pre	list should be initialized.
	*	@post	record is displayed on screen if name of article matches
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int FindByName(SimpleItemType& item);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	compare container id and check if they are same
	*	@param	data	target item for comparing
	*	@return	return true if self and other item have same container id otherwise false
	*/
	bool operator==(const ContainerType& _item);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	compare container id and check self is bigger
	*	@param	data	target item for comparing
	*	@return	return true if self is bigger than other item's container id otherwise false
	*/
	bool operator>(const ContainerType& _item);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	compare container id and check self is smaller
	*	@param	data	target item for comparing
	*	@return	return true if self is smaller than other item's container id otherwise false
	*/
	bool operator<(const ContainerType& _item);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	copy all elements to otherItem
	*	@param	data
	*/
	void operator=(const ContainerType& _item);

	friend ostream& operator<<(ostream& os, const ContainerType& _item) {
		cout << "\t************************************" << endl << endl;
		os << "\tContainer ID : " << _item.id_container << endl;
		os << "\tContainer Location : " << _item.location << endl;
		os << "\n\t< Container Photo >" << endl << _item.PhotoList << endl;
		os << "\t< SimpleItemType >" << endl << _item.SimpleItemList;
		return os;
	}

private:
	int id_container; // container id
	string location; // location of container
	UnsortedList <string>PhotoList; // PhotoList
	UnsortedList <SimpleItemType>SimpleItemList; //SimpleItemList(container id, usage, name(primary key), type)
};
