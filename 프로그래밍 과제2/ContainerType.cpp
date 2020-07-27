#include "ContainerType.h"

ContainerType::ContainerType() : id_container(0), location("") {}
ContainerType::~ContainerType() {}

int ContainerType::GetContainerId() const { return id_container; }
string ContainerType::GetLocation() const { return location; }
int ContainerType::GetSimpleListLength() { return SimpleItemList.GetLength(); }

void ContainerType::SetContainerId(int containerId) { id_container = containerId; }
void ContainerType::SetContainerIdFromKB() {
	cout << "\tContainer ID Of Article : ";
	cin >> id_container;
}
void ContainerType::SetConLocation(string inlocation) { location = inlocation; }
void ContainerType::SetConLocationFromKB() {
	cout << "\tLocation of Container : ";
	cin >> location;
}

void ContainerType::MakeItemEmpty() {
	SimpleItemList.MakeEmpty();
}

int ContainerType::AddItem(SimpleItemType& item) {
	if (SimpleItemList.Add(item)) return 1;
	return 0;
}

int ContainerType::DeleteItem(SimpleItemType& item) {
	if (SimpleItemList.Delete(item)) return 1;
	return 0;
}
int ContainerType::UpdateItem(SimpleItemType& item) {
	if (SimpleItemList.Replace(item)) return 1;
	return 0;
}


int ContainerType::AddPhoto(string& inPhoto) {
	if (PhotoList.Add(inPhoto)) return 1;
	return 0;
}


int ContainerType::DeletePhoto(string& inPhoto) {
	if (PhotoList.Delete(inPhoto)) return 1;
	return 0;
}

int ContainerType::UpdatePhoto(string& inPhoto, string& updatePhoto) {
	if (PhotoList.Replace(inPhoto, updatePhoto)) return 1;
	else return 0;
}

void ContainerType::DisplayContainerId() {
	cout << "\tContainer ID : " << id_container << endl;
}
void ContainerType::DisplayLocation() {
	cout << "\tContainer Location : " << location << endl;
}
void ContainerType::DisplayAllItem() {// iterator�� simpleitemlist��ü ���
	SimpleItemType data;
	SimpleItemList.ResetList();
	int index = SimpleItemList.GetNextItem(data);
	int length = SimpleItemList.GetLength();
	for (index; index < length && index != -1; index = SimpleItemList.GetNextItem(data)) {
		data.DisplayRecordOnScreen();
		cout << endl;
	}
	return;
}
void ContainerType::DisplayDetailsAllItem(DoublySortedLinkedList<ItemType>& ref) { //MasterList�� �����Ͽ� ItemType�� ���
	SimpleItemType data;
	SimpleItemList.ResetList();
	int length = SimpleItemList.GetLength();
	for (int i = 0; i < length; i++) {
		SimpleItemList.GetNextItem(data);
		ItemType detail;
		detail.SetName(data.GetName());
		ref.Retrieve(detail);
		cout << detail << endl;
	}

	return;
}
void ContainerType::DisplayAllPhoto() { //iterator�� photolist��ü ���
	cout << "\t< Container Photo > " << endl;
	string photo;
	PhotoList.ResetList();
	int index = PhotoList.GetNextItem(photo);
	int length = PhotoList.GetLength();
	for (index; index < length && index != -1; index = PhotoList.GetNextItem(photo)) {
		cout << "\t" << photo << endl;
	}
	return;
}

int ContainerType::FindByName(SimpleItemType& item) {

	SimpleItemType data; //curitem�� ��Ÿ�� ItemType ��ü
	bool isFind = false; //��ġ�ϴ� ���� ã�Ҵ��� �˷��ִ� ����
	SimpleItemList.ResetList();
	int index = SimpleItemList.GetNextItem(data); //list index�� ��� ����
	int length = SimpleItemList.GetLength(); //list ���̸� ��� ����

	cout << endl;
	//index 0���� lenth-1���� getnextitem�Լ��� ��ġ�ϴ� name check
	for (index; index < length && index != -1; index = SimpleItemList.GetNextItem(data)) {
		if (data.GetName().find(item.GetName()) != -1) {//find �Լ��� ��ġ���� ������ -1 ��ȯ
			data.DisplayRecordOnScreen();
			isFind = true;
			cout << endl;
		}//name�� �����ϴ� ���ڿ� �߰� �� ���� display on screen, isFind=true
	}

	//primary key�� search�� ���� �ƴϹǷ� isFind ���� �ʿ�
	if (isFind == true) return 1;
	else  return 0;

}

bool ContainerType::operator==(const ContainerType& _item) {
	if (id_container == _item.id_container) return true;
	return false;
}
bool ContainerType::operator>(const ContainerType& _item) {
	if (id_container > _item.id_container) return true;
	return false;
}
bool ContainerType::operator<(const ContainerType& _item) {
	if (id_container < _item.id_container) return true;
	return false;
}

//Simpleitemlist�� photolist�� unsorted���ִ� ������Կ����ڷ� ���� ����
void ContainerType::operator=(const ContainerType& _item) {
	if (id_container != _item.id_container) {
		id_container = _item.id_container;
	}
	location = _item.location;
	SimpleItemList = _item.SimpleItemList;
	PhotoList = _item.PhotoList;

}