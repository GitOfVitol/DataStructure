#include "StorageType.h"

StorageType::StorageType() : storage_id(""), storage_location(""), CurrentNum(0), MaxNum(MAXCONTAINER) { }
StorageType::StorageType(int maxNum) : storage_id(""), storage_location(""), CurrentNum(0), MaxNum(maxNum) {}
StorageType::~StorageType() {}

string StorageType::GetStorageId() const { return storage_id; }
string StorageType::GetStorageLocation() const { return storage_location; }
int StorageType::GetCurrentNum() const { return CurrentNum; }
int StorageType::GetMaxNum() const { return MaxNum; }

void StorageType::SetStorageId(string inStorageId) { storage_id = inStorageId; }
void StorageType::SetStorageLocation(string inStorageLocation) { storage_location = inStorageLocation; }

void StorageType::SetStorageIdFromKB() {
	cout << "\tStorage ID : ";
	cin >> storage_id;
}
void StorageType::SetStorageLocationFromKB() {
	cout << "\tLocation of Storage : ";
	cin >> storage_location;
}

void StorageType::UpdateContainerLocation() { // ContainerList의 특정 id에 대한 lcoation update
	ContainerType container;
	container.SetContainerIdFromKB();
	if (!ContainerList.Retrieve(container)) {
		cout << "\tWrong Container Id!" << endl;
		return;
	}
	container.SetConLocationFromKB();
	ContainerList.Replace(container);
	return;
}

int StorageType::AddStoragePhoto(string& inPho) {

	storagePhoto.Add(inPho);

	return 1;
}

bool StorageType::isFull() const {
	if (MaxNum == CurrentNum) return true;
	else return false;
}

int StorageType::GetContainer(ContainerType& _con) { //Container Id를 바탕으로 특정 container get
	if (ContainerList.Retrieve(_con)) return 1;
	else return 0;
}

int StorageType::GetNextContainer(ContainerType& _con) {
	ContainerList.GetNextItem(_con);
	return 1;
}

void StorageType::ResetContainerList(){
	ContainerList.ResetList();
}

int StorageType::AddContainer(ContainerType& _item) { //StorageType에 container add
	if (isFull()) {
		cout << "\t" << storage_id << " Storage is Full!" << endl;
		return 0;
	}
	if (ContainerList.Add(_item)) {
		CurrentNum++;
		return 1;
	}
	else return 0;
}
int StorageType::DeleteContainer(ContainerType& _item) { //StorageType에 container delete
	if (ContainerList.Delete(_item)) return 1;
	else return 0;
}
int StorageType::UpdateContainer(ContainerType& _item) { //StorageType에 container update
	if (ContainerList.Replace(_item)) return 1;
	else return 0;
}

int StorageType::DeleteStoragePhoto(string& inPhoto) { //StorageType의 PhotoList에 photo delete
	if (storagePhoto.Delete(inPhoto)) return 1;
	else return 0;
}
int StorageType::UpdateStoragePhoto(string& inPhoto, string& upPhoto) { //StorageType의 PhotoList에 photo update
	if (storagePhoto.Replace(inPhoto, upPhoto)) return 1;
	else return 0;
}

int StorageType::AddContainerPhoto() { //ContainerType의 PhotoList에 photo add
	ContainerType container;
	container.SetContainerIdFromKB();
	if (!ContainerList.Retrieve(container)) {
		cout << "\tWrong Container Id!" << endl;
		return 0;
	}
	cout << "\tChoose photo name to add : ";
	string photoName;
	cin >> photoName;
	container.AddPhoto(photoName);
	ContainerList.Replace(container);
	return 1;
}
int StorageType::DeleteContainerPhoto() { //ContainerType의 PhotoList에 photo delete
	ContainerType container;
	container.SetContainerIdFromKB();
	if (!ContainerList.Retrieve(container)) {
		cout << "\tWrong Container Id!" << endl;
		return 0;
	}
	cout << "\tChoose photo name to delete : ";
	string photoName;
	cin >> photoName;
	container.DeletePhoto(photoName);
	ContainerList.Replace(container);
	return 1;
}
int StorageType::UpdateContainerPhoto() { //ContainerType의 PhotoList에 photo update
	ContainerType container;
	container.SetContainerIdFromKB();
	if (!ContainerList.Retrieve(container)) {
		cout << "\tWrong Container Id!" << endl;
		return 0;
	}
	string photoName;
	cout << "\tChoose photo name to update : ";
	cin >> photoName;

	string upPhoto;
	cout << "\tNew Photo : ";
	cin >> upPhoto;

	container.UpdatePhoto(photoName, upPhoto);
	ContainerList.Replace(container);
	return 1;
}

void StorageType::DisplayAllContainer() { // ContainerList에 대한 모든 정보 출력
	cout << "\n\n\t--- Current ContainerList --- " << endl << endl;
	cout << ContainerList;
	cout << "\t************************************" << endl;
}
void StorageType::DisplayAllDetailsContainer(DoublySortedLinkedList<ItemType>& ref) { // ContainerList에 대한 모든 정보 MasterList를 참조하여 출력
	cout << "\n\n\t--- Current ContainerList --- " << endl << endl;
	cout << "\t************************************" << endl << endl;
	SimpleItemType tmpsimp;
	ContainerType tmpcon;
	ContainerList.ResetList();
	int length = ContainerList.GetLength();
	for (int index = 0; index < length; index++) {
		ContainerList.GetNextItem(tmpcon);
		tmpcon.DisplayContainerId();
		tmpcon.DisplayLocation();
		cout << endl;
		tmpcon.DisplayAllPhoto();
		cout << endl;
		tmpcon.DisplayDetailsAllItem(ref);
		cout << "\t************************************" << endl << endl;
	}

}
void StorageType::DisplayAllPhotoOfContainer() { //Container의 모든 PHoto 출력
	ContainerType temp;
	ContainerList.ResetList();
	int length = ContainerList.GetLength();
	for (int index = 0; index < length; index++) {
		ContainerList.GetNextItem(temp);
		temp.DisplayContainerId();
		temp.DisplayLocation();
		temp.DisplayAllPhoto();
		cout << endl;
	}
}

bool StorageType::operator==(const StorageType& _item) {
	if (storage_id == _item.GetStorageId()) return true;
	return false;
}
bool StorageType::operator>(const StorageType& _item) {
	if (storage_id > _item.GetStorageId()) return true;
	return false;
}
bool StorageType::operator<(const StorageType& _item) {
	if (storage_id < _item.GetStorageId()) return true;
	return false;
}
void StorageType::operator=(const StorageType& _item) {
	storage_id = _item.GetStorageId();
	storage_location = _item.GetStorageLocation();
	storagePhoto = _item.storagePhoto;
	CurrentNum = _item.GetCurrentNum();
	MaxNum = _item.GetMaxNum();
	ContainerList = _item.ContainerList;
}