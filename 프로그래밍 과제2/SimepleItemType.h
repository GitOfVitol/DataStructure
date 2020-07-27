#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class SimpleItemType {
public:
	/*
		default constructor
	*/
	SimpleItemType();

	/*
		destructor
	*/
	~SimpleItemType();

	string GetPhotoOfArticle() const;

	/*
	*	@brief	Get container Id
	*	@pre	container Id is set.
	*	@post	none.
	*	@return	container Id
	*/
	int GetContainerId() const;

	/*
	*	@brief	Get storage Id
	*	@pre	storage Id is set.
	*	@post	none.
	*	@return	storage Id
	*/
	string GetStorageId() const;

	/*
	*	@brief	Get article name
	*	@pre	article name is set.
	*	@post	none.
	*	@return	article name
	*/
	string GetName() const;

	/*
	*	@brief	Get article type
	*	@pre	article type is set.
	*	@post	none.
	*	@return	article type
	*/
	string GetType() const;

	/*
	*	@brief	Set storage Id
	*	@pre	none.
	*	@post	storage Id is set.
	*	@param	storageId storage Id
	*/
	void SetPhotoOfArticle(string inPhoto);

	/*
	*	@brief	Set storage Id
	*	@pre	none.
	*	@post	storage Id is set.
	*	@param	storageId storage Id
	*/
	void SetStorageId(string storageId);

	/*
	*	@brief	Set container Id
	*	@pre	none.
	*	@post	container Id is set.
	*	@param	containerId container Id
	*/
	void SetContainerId(int containerId);

	/*
	*	@brief	Set name of article
	*	@pre	none.
	*	@post	name of article is set.
	*	@param	name name of article
	*/
	void SetName(string name);

	/*
	*	@brief	Set type of article
	*	@pre	none.
	*	@post	type of article is set.
	*	@param	type type of article
	*/
	void SetType(string type);

	/*
	*	@brief	Set article record.
	*	@pre	none.
	*	@post	article record is set.
	*	@param	id_container, name, type, use, purchase, store, totalNum
	*/
	void SetRecord(string inPhoto, string storageId, int containerId, string name, string type);

	/*
	*	@brief	Display storage id of article on screen.
	*	@pre	storage id of article is set.
	*	@post	storage id of article is on screen.
	*/
	void DisplayPhotoOfArticleOnScreen() const;

	/*
	*	@brief	Display storage id of article on screen.
	*	@pre	storage id of article is set.
	*	@post	storage id of article is on screen.
	*/
	void DisplayStorageIdOnScreen() const;

	/*
	*	@brief	Display container id of article on screen.
	*	@pre	container id of article is set.
	*	@post	container id of article is on screen.
	*/
	void DisplayContainerIdOnScreen() const;

	/*
	*	@brief	Display name of article on screen.
	*	@pre	name of article is set.
	*	@post	name of article is on screen.
	*/
	void DisplayNameOnScreen() const;

	/*
	*	@brief	Display type of article on screen.
	*	@pre	type of article is set.
	*	@post	type of article is on screen.
	*/
	void DisplayTypeOnScreen() const;

	/*
	*	@brief	Display record of article on screen.
	*	@pre	record of article is set.
	*	@post	record of article is on screen.
	*/
	void DisplayRecordOnScreen() const;

	void SetPhotoOfArticleFromKB();

	void SetStorageIdFromKB();

	/*
	*	@brief	Set container Id from keyboard.
	*	@pre	none.
	*	@post	container Id of article is set.
	*/
	void SetContainerIdFromKB();

	/*
	*	@brief	Set name of article from keyboard.
	*	@pre	none.
	*	@post	name of article is set.
	*/
	void SetNameFromKB();

	/*
	*	@brief	Set type of article from keyboard.
	*	@pre	none.
	*	@post	type of article is set.
	*/
	void SetTypeFromKB();

	/*
	*	@brief	Set record of article from keyboard.
	*	@pre	none.
	*	@post	record of article is set.
	*/
	void SetRecordFromKB();

	/*
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	article record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/*
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new article record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	compare article name(primary key) and check self is bigger
	*	@param	data	target item for comparing
	*	@return	return true if self is bigger than other item's primary key otherwise false
	*/
	bool operator>(const SimpleItemType& data);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	compare article name(primary key) and check self is smaller
	*	@param	data	target item for comparing
	*	@return	return true if self is smaller than other item's primary key otherwise false
	*/
	bool operator<(const SimpleItemType& data);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	compare music name(primary key) and check if they are same
	*	@param	data	target item for comparing
	*	@return	return true if self and other item have same primary key otherwise false
	*/
	bool operator==(const SimpleItemType& data);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	copy all elements to otherItem
	*	@param	data
	*/
	void operator=(const SimpleItemType& data);

	/*
	*	@pre	self is initialized
	*	@post	display all elements of Item
	*	@param	os, _item
	*/
	friend ostream& operator<<(ostream& os, const SimpleItemType& _item) {
		os << "Photo Of Article : " << _item.GetPhotoOfArticle() << endl;
		if (_item.GetStorageId() == "") {
			os << "\tStorage Id : Not dertermined" << endl;
		}
		else {
			os << "\tStorage Id : " << _item.GetStorageId() << endl;
		}
		if (_item.GetContainerId() <= 0) {
			os << "\tContainer Id : Not dertermined" << endl;
		}
		else {
			os << "\tContainer Id : " << _item.GetContainerId() << endl;
		}
		os << "\tName Of Article(Primary Key) : " << _item.GetName() << endl;
		os << "\tType Of Article  : " << _item.GetType() << endl;

		return os;
	}

private:
	string a_photo; // photo of article
	string a_name; // name of article
	int id_container; // container id
	string id_storage; // storage id
	string a_type; // type of article 
};
