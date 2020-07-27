#include "SimepleItemType.h"

SimpleItemType::SimpleItemType() : a_name(""), id_container(0), id_storage(""), a_type(""), a_photo("") {}
SimpleItemType::~SimpleItemType() {}

string SimpleItemType::GetPhotoOfArticle() const { return a_photo; }
string SimpleItemType::GetStorageId() const { return id_storage; }
int SimpleItemType::GetContainerId() const { return id_container; }
string SimpleItemType::GetName() const { return a_name; }
string SimpleItemType::GetType() const { return a_type; }

void SimpleItemType::SetPhotoOfArticle(string inPhoto) { a_photo = inPhoto; }
void SimpleItemType::SetStorageId(string storageId) { id_storage = storageId; }
void SimpleItemType::SetContainerId(int containerId) { id_container = containerId; }
void SimpleItemType::SetName(string name) { a_name = name; }
void SimpleItemType::SetType(string type) { a_type = type; }
void SimpleItemType::SetRecord(string inPhoto, string storageId, int containerId, string name, string type) {
	SetPhotoOfArticle(inPhoto);
	SetStorageId(storageId);
	SetContainerId(containerId);
	SetName(name);
	SetType(type);
}

void SimpleItemType::DisplayPhotoOfArticleOnScreen() const {
	cout << "\tPhoto Of Article : " << a_photo << endl;
}
void SimpleItemType::DisplayStorageIdOnScreen() const {
	cout << "\tStorage Id : " << id_storage << endl;
}
void SimpleItemType::DisplayContainerIdOnScreen() const {
	cout << "\tContainer Id : " << id_container << endl;
}
void SimpleItemType::DisplayNameOnScreen() const {
	cout << "\tName Of Article(Primary Key) : " << a_name << endl;
}
void SimpleItemType::DisplayTypeOnScreen() const {
	cout << "\tType Of Article  : " << a_type << endl;
}
void SimpleItemType::DisplayRecordOnScreen() const {
	DisplayPhotoOfArticleOnScreen();
	DisplayStorageIdOnScreen();
	DisplayContainerIdOnScreen();
	DisplayNameOnScreen();
	DisplayTypeOnScreen();
}

void SimpleItemType::SetPhotoOfArticleFromKB() {
	cout << "\tPhoto Of Article : ";
	cin >> a_photo;
	cout << endl;
}
void SimpleItemType::SetStorageIdFromKB() {
	cout << "\tStorage ID Of Article : ";
	cin >> id_storage;
	cout << endl;
}
void SimpleItemType::SetContainerIdFromKB() {
	cout << "\tContainer ID Of Article : ";
	cin >> id_container;
	cout << endl;
}
void SimpleItemType::SetNameFromKB() {
	cout << "\tName Of Article(Primary Key) : ";
	cin.ignore();
	getline(cin, a_name);
}
void SimpleItemType::SetTypeFromKB() {
	cout << "\tType Of Article : ";
	cin.ignore();
	getline(cin, a_type);
}
void SimpleItemType::SetRecordFromKB() {
	SetPhotoOfArticleFromKB();
	SetStorageIdFromKB();
	SetContainerIdFromKB();
	SetNameFromKB();
	SetTypeFromKB();
}

int SimpleItemType::ReadDataFromFile(ifstream& fin) {
	fin >> a_photo;
	fin >> id_storage;
	fin >> id_container;
	fin >> a_name;
	fin >> a_type;

	return 1;
}
int SimpleItemType::WriteDataToFile(ofstream& fout) {
	fout << endl;
	fout << a_photo << " ";
	fout << id_storage << " ";
	fout << id_container << " ";
	fout << a_name << " ";
	fout << a_type << " ";

	return 1;

}

bool SimpleItemType::operator<(const SimpleItemType& data) {
	if (a_name < data.a_name) return true;
	else return false;
}
bool SimpleItemType::operator>(const SimpleItemType& data) {
	if (a_name > data.a_name) return true;
	else return false;
}
bool SimpleItemType::operator==(const SimpleItemType& data) {
	if (a_name == data.a_name) return true;
	else return false;
}
void SimpleItemType::operator=(const SimpleItemType& data) {
	a_photo = data.a_photo;
	id_storage = data.id_storage;
	id_container = data.id_container;
	a_name = data.a_name;
	a_type = data.a_type;
}