#include "ItemType.h"

string ItemType::GetStorageId() const { return id_storage; }
int ItemType::GetContainerId() const { return id_container; }
string ItemType::GetName() const { return a_name; }
string ItemType::GetType() const { return a_type; }
string ItemType::GetUse() const { return a_use; }
string ItemType::GetDateOfPurchase() const { return d_purchase; }
string ItemType::GetPhotoOfArticle() const { return a_photo; }
int ItemType::GetTotalNum() const { return a_totalNum; }

void ItemType::SetStorageId(string inStorageId) { id_storage = inStorageId; }
void ItemType::SetContainerId(int inContainerId) { id_container = inContainerId; }
void ItemType::SetName(string name) { a_name = name; }
void ItemType::SetType(string type) { a_type = type; }
void ItemType::SetUse(string use) { a_use = use; }
void ItemType::SetDateOfPurchase(string purchase) { d_purchase = purchase; }
void ItemType::SetPhotoOfArticle(string inPhoto) { a_photo = inPhoto; }
void ItemType::SetTotalNum(int totalNum) { a_totalNum = totalNum; }
void ItemType::SetRecord(string inStorageId, int inContainerId, string name, string type, string use, string purchase, string inPhoto, int totalNum) {
	SetPhotoOfArticle(inPhoto);
	SetStorageId(inStorageId);
	SetContainerId(inContainerId);
	SetName(name);
	SetType(type);
	SetUse(use);
	SetDateOfPurchase(purchase);
	SetTotalNum(totalNum);
}

void ItemType::DisplayPhotoOfArticleOnScreen() const {
	cout << "\tPhoto of article  : " << a_photo << endl;
}
void ItemType::DisplayStorageIdOnScreen() const {
	cout << "\tStorage Of Article : " << id_storage << endl;
}
void ItemType::DisplayContainerIdOnScreen() const {
	cout << "\tContainer Of Article : " << id_container << endl;
}
void ItemType::DisplayNameOnScreen() const {
	cout << "\tName Of Article(Primary Key) : " << a_name << endl;
}
void ItemType::DisplayTypeOnScreen() const {
	cout << "\tType Of Article : " << a_type << endl;
}
void ItemType::DisplayUseOnScreen() const {
	cout << "\tUse Of Article  : " << a_use << endl;
}
void ItemType::DisplayDateOfPurchaseOnScreen() const {
	cout << "\tDate Of Purchase  : " << d_purchase << endl;
}
void ItemType::DisplayTotalNumOnScreen() const {
	cout << "\tTotal Number Of Article   : " << a_totalNum << endl;
}
void ItemType::DisplayRecordOnScreen() const {
	DisplayPhotoOfArticleOnScreen();
	DisplayStorageIdOnScreen();
	DisplayContainerIdOnScreen();
	DisplayNameOnScreen();
	DisplayTypeOnScreen();
	DisplayUseOnScreen();
	DisplayDateOfPurchaseOnScreen();
	DisplayTotalNumOnScreen();
}
void ItemType::DisplayExceptConIdOnScreen() const {
	DisplayPhotoOfArticleOnScreen();
	DisplayNameOnScreen();
	DisplayTypeOnScreen();
	DisplayUseOnScreen();
	DisplayDateOfPurchaseOnScreen();
	DisplayTotalNumOnScreen();
}

void ItemType::SetStorageIdFromKB() {
	cout << "\tStorage ID Of Article : ";
	cin >> id_storage;
}
void ItemType::SetContainerIdFromKB() {
	cout << "\tContainer ID Of Article(Only interger) : ";
	cin >> id_container;
}
void ItemType::SetNameFromKB() {
	cout << "\tName Of Article(Primary Key) : ";
	cin >> a_name;
}
void ItemType::SetTypeFromKB() {
	cout << "\tType Of Article : ";
	cin >> a_type;
}
void ItemType::SetUseFromKB() {
	cout << "\tUse Of Article : ";
	cin >> a_use;
}
void ItemType::SetDateOfPurchaseFromKB() {
	cout << "\tDate Of Purchase : ";
	cin >> d_purchase;
}
void ItemType::SetPhotoOfArticleFromKB() {
	cout << "\tPhoto of Article : ";
	cin >> a_photo;
}
void ItemType::SetTotalNumFromKB() {
	cout << "\tTotal Number Of Article : ";
	cin >> a_totalNum;
}
void ItemType::SetRecordFromKB() {
	SetPhotoOfArticleFromKB();
	SetStorageIdFromKB();
	SetContainerIdFromKB();
	SetNameFromKB();
	SetTypeFromKB();
	SetUseFromKB();
	SetDateOfPurchaseFromKB();
	SetTotalNumFromKB();
}
void ItemType::SetExceptConIDFromKB() {
	SetPhotoOfArticleFromKB();
	SetNameFromKB();
	SetTypeFromKB();
	SetUseFromKB();
	SetDateOfPurchaseFromKB();
	SetTotalNumFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> a_photo;
	fin >> id_storage;
	fin >> id_container;
	fin >> a_name;
	fin >> a_type;
	fin >> a_use;
	fin >> d_purchase;
	fin >> a_totalNum;

	return 1;
}
int ItemType::WriteDataToFile(ofstream& fout) {
	fout << endl;
	fout << a_photo << " ";
	fout << id_storage << " ";
	fout << id_container << " ";
	fout << a_name << " ";
	fout << a_type << " ";
	fout << a_use << " ";
	fout << d_purchase << " ";
	fout << a_totalNum;

	return 1;

}

bool ItemType::operator<(const ItemType& data) {
	if (a_name < data.a_name) return true;
	else return false;
}
bool ItemType::operator>(const ItemType& data) {
	if (a_name > data.a_name) return true;
	else return false;
}
bool ItemType::operator==(const ItemType& data) {
	if (a_name == data.a_name) return true;
	else return false;
}
void ItemType::operator=(const ItemType& data) {
	id_storage = data.id_storage;
	id_container = data.id_container;
	a_name = data.a_name;
	a_type = data.a_type;
	a_use = data.a_use;
	d_purchase = data.d_purchase;
	a_photo = data.a_photo;
	a_totalNum = data.a_totalNum;
}