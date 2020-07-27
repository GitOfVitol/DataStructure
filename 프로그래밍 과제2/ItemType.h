#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class ItemType {
public:
	/*
		default constructor
	*/
	ItemType()
		: id_storage(""), id_container(0), a_type(""), d_purchase(""), a_photo(""), a_name(""), a_use(""), a_totalNum(0) {}

	/*
		destructor
	*/
	~ItemType() {}

	/*
	*	@brief	Get storage Id
	*	@pre	storage Id is set.
	*	@post	none.
	*	@return	storage Id
	*/
	string GetStorageId() const;

	/*
	*	@brief	Get container Id
	*	@pre	container Id is set.
	*	@post	none.
	*	@return	container Id
	*/
	int GetContainerId() const;

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
	*	@brief	Get use of article
	*	@pre	use of article is set.
	*	@post	none.
	*	@return	use of article
	*/
	string GetUse() const;

	/*
	*	@brief	Get date of purchase
	*	@pre	date of purchase is set.
	*	@post	none.
	*	@return	date of purchase
	*/
	string GetDateOfPurchase() const;

	/*
	*	@brief	Get date of store
	*	@pre	date of store is set.
	*	@post	none.
	*	@return	date of store
	*/
	string GetPhotoOfArticle() const;

	/*
	*	@brief	Get total number of article
	*	@pre	total number of article is set.
	*	@post	none.
	*	@return	total number of article
	*/
	int GetTotalNum() const;

	/*
	*	@brief	Set container Id
	*	@pre	none.
	*	@post	container Id is set.
	*	@param	id_container container Id
	*/
	void SetStorageId(string inStroageId);

	/*
	*	@brief	Set container Id
	*	@pre	none.
	*	@post	container Id is set.
	*	@param	id_container container Id
	*/
	void SetContainerId(int inContainerId);

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
	*	@brief	Set use of article
	*	@pre	none.
	*	@post	use of article is set.
	*	@param	use use of article
	*/
	void SetUse(string use);

	/*
	*	@brief	Set date of purchase
	*	@pre	none.
	*	@post	date of purchase is set.
	*	@param	purchase	date of purchase
	*/
	void SetDateOfPurchase(string purchase);

	/*
	*	@brief	Set date of store
	*	@pre	none.
	*	@post	date of store is set.
	*	@param	store	date of store
	*/
	void SetPhotoOfArticle(string inPhoto);

	/*
	*	@brief	Set total number of article
	*	@pre	none.
	*	@post	total number of article is set.
	*	@param	totalNum	total number of article
	*/
	void SetTotalNum(int totalNum);

	/*
	*	@brief	Set article record.
	*	@pre	none.
	*	@post	article record is set.
	*	@param	id_storage, id_container, name, type, use, purchase, store, totalNum
	*/
	void SetRecord(string inStorageId, int inContainerId, string name, string type, string use, string purchase, string inPhoto, int totalNum);

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
	*	@brief	Display use of article on screen.
	*	@pre	use of article is set.
	*	@post	use of article is on screen.
	*/
	void DisplayUseOnScreen() const;

	/*
	*	@brief	Display date of purchase
	*	@pre	date of purchase is set.
	*	@post	date of purchase is on screen.
	*/
	void DisplayDateOfPurchaseOnScreen() const;

	/*
	*	@brief	Display date of store
	*	@pre	date of store is set.
	*	@post	date of store is on screen.
	*/
	void DisplayPhotoOfArticleOnScreen() const;

	/*
	*	@brief	Display total number of article on screen.
	*	@pre	total number of article is set.
	*	@post	total number of article is on screen.
	*/
	void DisplayTotalNumOnScreen() const;

	/*
	*	@brief	Display record of article on screen.
	*	@pre	record of article is set.
	*	@post	record of article is on screen.
	*/
	void DisplayRecordOnScreen() const;

	/*
	*	@brief	Display record of article except container Id on screen.
	*	@pre	record of article except container Id is set.
	*	@post	record of article except container Id is on screen.
	*/
	void DisplayExceptConIdOnScreen() const;

	/*
	*	@brief	Set storage Id from keyboard.
	*	@pre	none.
	*	@post	storage Id of article is set.
	*/
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
	*	@brief	Set use of article from keyboard.
	*	@pre	none.
	*	@post	use of article is set.
	*/
	void SetUseFromKB();

	/*
	*	@brief	Set date of purchase from keyboard.
	*	@pre	none.
	*	@post	date of purchase is set.
	*/
	void SetDateOfPurchaseFromKB();

	/*
	*	@brief	Set date of store from keyboard.
	*	@pre	none.
	*	@post	date of store is set.
	*/
	void SetPhotoOfArticleFromKB();

	/*
	*	@brief	Set total number of article from keyboard.
	*	@pre	none.
	*	@post	total number of article is set.
	*/
	void SetTotalNumFromKB();

	/*
	*	@brief	Set record of article from keyboard.
	*	@pre	none.
	*	@post	record of article is set.
	*/
	void SetRecordFromKB();

	/*
	*	@brief	Set record of article except container Id from keyboard.
	*	@pre	none.
	*	@post	record of article except container Id is set.
	*/
	void SetExceptConIDFromKB();


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
	bool operator>(const ItemType& data);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	compare article name(primary key) and check self is smaller
	*	@param	data	target item for comparing
	*	@return	return true if self is smaller than other item's primary key otherwise false
	*/
	bool operator<(const ItemType& data);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	compare article name(primary key) and check if they are same
	*	@param	data	target item for comparing
	*	@return	return true if self and other item have same primary key otherwise false
	*/
	bool operator==(const ItemType& data);

	/*
	*	@pre	self is initialized, otherItem is initialized
	*	@post	copy all elements to otherItem
	*	@param	data
	*/
	void operator=(const ItemType& data);

	/*
	*	@pre	self is initialized
	*	@post	display all elements of Item
	*	@param	os, _item
	*/
	friend ostream& operator<<(ostream& os, const ItemType& _item) {
		os << "\tPhoto of Article : " << _item.GetPhotoOfArticle() << endl;

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
		os << "\tType Of Article : " << _item.GetType() << endl;
		os << "\tUse Of Article : " << _item.GetUse() << endl;
		os << "\tDate Of Purchase : " << _item.GetDateOfPurchase() << endl;
		os << "\tTotal Number Of Article : " << _item.GetTotalNum() << endl;
		return os;
	}

private:
	string id_storage; // 물품 저장장소 (ex 장롱)
	int id_container; // 물품 저장장소 (ex 장롱의 몇 번째 서랍) - 왼쪽 위부터 순서대로 1부터 시작
	string a_name; //물품이름(primary key)
	string a_type; // 물품 종류 
	string a_use; //용도
	string d_purchase; //구매일
	string a_photo; //물품 사진
	int a_totalNum; //물품의 총 갯수 

};