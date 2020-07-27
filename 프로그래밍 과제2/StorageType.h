#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "SingleLinkedList.h"
#include "ContainerType.h"
#include "SortedList.h"
#include "ItemType.h"
#include "SimepleItemType.h"

#define MAXCONTAINER 10

class StorageType {
	friend class DisplayStorageTempWindow;
public:
	/*
		default constructor
	*/
	StorageType();

	/*
		constructor
	*/
	StorageType(int maxNum);

	/*
		destructor
	*/
	~StorageType();

	/*
	*	@brief	Get storage Id
	*	@pre	storage Id is set.
	*	@post	none.
	*	@return	storage Id
	*/
	string GetStorageId() const;

	/*
	*	@brief	Get storage location
	*	@pre	storage location is set.
	*	@post	none.
	*	@return	storage location
	*/
	string GetStorageLocation() const;

	/*
	*	@brief	Get Current number of container
	*	@pre	Current number of container is set.
	*	@post	none.
	*	@return	Current number of container
	*/
	int GetCurrentNum() const;

	/*
	*	@brief	Get Max number of container
	*	@pre	Max number of container is set.
	*	@post	none.
	*	@return	Max number of container
	*/
	int GetMaxNum() const;

	/*
	*	@brief	Set storage location
	*	@pre	none.
	*	@post	storage location is set.
	*	@param	 inStorageLocation location
	*/
	void SetStorageLocation(string inStorageLocation);

	/*
	*	@brief	Set storage id
	*	@pre	none.
	*	@post	storage id is set.
	*	@param	inStorageId
	*/
	void SetStorageId(string inStorageId);

	/*
	*	@brief	Set storage id from Keryboard
	*	@pre	none.
	*	@post	storage id is set.
	*	@param	 none
	*/
	void SetStorageIdFromKB();

	/*
	*	@brief	Set storage location from Keryboard
	*	@pre	none.
	*	@post	storage id is set.
	*	@param	 none
	*/
	void SetStorageLocationFromKB();

	/*
		brief : update a location of containerlist
		pre : list must be initialized
		post : update a location into containerlist
		param : none
		return : return 1 if this function works well otherwise return 0
	*/
	void UpdateContainerLocation();

	/*
		brief : update a photo into storagelist
		pre : list must be initialized
		post : update a photo into storagelist
		param : none
		return : return 1 if this function works well otherwise return 0
	*/
	int AddStoragePhoto(string& inPho);

	/*
		brief : to know availability of list wheather is full or not
		pre : none
		post : none
		return : true if list is full / false if list is not full
	*/
	bool isFull() const;

	/*
		brief : get a containerType from list using container id
		pre : list must be initialized
		post : get a containerType from list
		param : _item
		return : return 1 if this function works well otherwise return 0
	*/
	int GetContainer(ContainerType& _con);

	int GetNextContainer(ContainerType& _con);

	void ResetContainerList();

	/*
		brief : add a containerType into list
		pre : list must be initialized
		post : add a new containerType into list
		param : _item
		return : return 1 if this function works well otherwise return 0
	*/
	int AddContainer(ContainerType& _item);

	/*
		brief : delete a containerType into list
		pre : list must be initialized
		post : delete a containerType into list
		param : _item
		return : return 1 if this function works well otherwise return 0
	*/
	int DeleteContainer(ContainerType& _item);

	/*
		brief : replace a containerType into list
		pre : list must be initialized
		post : replace a containerType into list
		param : _item
		return : return 1 if this function works well otherwise return 0
	*/
	int UpdateContainer(ContainerType& _item);

	/*
		brief : delete a photo into storagelist
		pre : list must be initialized
		post : delete a photo into storagelist
		param : inPhoto
		return : return 1 if this function works well otherwise return 0
	*/
	int DeleteStoragePhoto(string& inPhoto);

	/*
		brief : update a photo into storagelist
		pre : list must be initialized
		post : update a photo into storagelist
		param : inPhoto, upPhoto
		return : return 1 if this function works well otherwise return 0
	*/
	int UpdateStoragePhoto(string& inPhoto, string& upPhoto);

	/*
		brief : add a photo into list
		pre : list must be initialized
		post : add a photo into list
		param : none
		return : return 1 if this function works well otherwise return 0
	*/
	int AddContainerPhoto();

	/*
		brief : delete a photo from containerlist
		pre : list must be initialized
		post : delete a photo from containerlist
		param : none
		return : return 1 if this function works well otherwise return 0
	*/
	int DeleteContainerPhoto();

	/*
		brief : update a photo of containerlist
		pre : list must be initialized
		post : update a photo of containerlist
		param : none
		return : return 1 if this function works well otherwise return 0
	*/
	int UpdateContainerPhoto();

	/*
	*	@brief	Display all photos on screen.
	*	@pre	photos are set.
	*	@post	photos are on screen.
	*/
	void DisplayAllPhotoOfContainer();

	/*
	*	@brief	Display all containerlist on screen.
	*	@pre	containerlist is set.
	*	@post	containerlist is on screen.
	*/
	void DisplayAllContainer();

	/*
	*	@brief	Display all containerlist on screen. ref MasterList
	*	@pre	containerlist is set.
	*	@post	containerlist is on screen.
	*/
	void DisplayAllDetailsContainer(DoublySortedLinkedList<ItemType>& ref);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	compare storage id and check if they are same
	*	@param	data	target item for comparing
	*	@return	return true if self and other item have same storage id otherwise false
	*/
	bool operator==(const StorageType& _item);
	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	compare container id and check self is bigger
	*	@param	data	target item for comparing
	*	@return	return true if self is bigger than other item's container id otherwise false
	*/
	bool operator>(const StorageType& _item);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	compare container id and check self is smaller
	*	@param	data	target item for comparing
	*	@return	return true if self is smaller than other item's container id otherwise false
	*/
	bool operator<(const StorageType& _item);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	copy all elements to otherItem
	*	@param	data
	*/
	void operator=(const StorageType& _item);

	friend ostream& operator<<(ostream& os, const StorageType& _item) {
		os << "\tStorage ID : " << _item.GetStorageId() << endl;
		os << "\tStorage Location : " << _item.GetStorageLocation() << endl;
		os << "\n\t< Storage Photo >" << endl << _item.storagePhoto << endl;
		os << "\tMax number of Container : " << _item.GetMaxNum() << endl;
		os << "\tTotal number of Container : " << _item.GetCurrentNum() << endl;
		return os;
	}
private:
	string storage_id; // storage id
	UnsortedList <string>storagePhoto; // storage photo list
	string storage_location; // storage location
	int CurrentNum; // cuurrent number of container
	int MaxNum; // max number of container
	SingleLinkedList <ContainerType>ContainerList; // container list
};
