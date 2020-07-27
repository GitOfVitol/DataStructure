#include "TempType.h"

TempType::TempType() :numOfItems(0) {}
TempType::~TempType() {}

int TempType::GetNumOfItems() { return numOfItems; }

int TempType::AddItemToQueue(ItemType data) {
	if (tempItemList.IsFull()) return 0; //tempitemlist가 full인지 확인
	tempItemList.EnQueue(data);
	numOfItems++;

	return 1;
}
int TempType::DequeueFromQueue(ItemType& data) {
	if (tempItemList.IsEmpty()) return 0; //tempitemlist가 empty인지 확인
	tempItemList.DeQueue(data);
	numOfItems--;

	return 1;
}

int TempType::RetrieveItemFromQueue(ItemType& data) {
	if (tempItemList.IsEmpty()) return 0;
	if (tempItemList.Retrieve(data) == -1) return 0;
	else return 1;
}

int TempType::DeleteItemFromQueue(ItemType& data) {
	if (tempItemList.IsEmpty()) return 0;
	if (tempItemList.Delete(data)) {
		numOfItems--;

		return 1;
	}
	else return 0;
}

void TempType::ResetTempList() {
	tempItemList.ResetList();
}


int TempType::GetNextTempItem(ItemType& item) {
	tempItemList.GetNexItem(item);
	return 1;
}

void TempType::PrintAllItemInQueue() {
	cout << "\t<Current TempList>" << endl;
	tempItemList.Print();
}

void TempType::PrintNumOfItems() {
	cout << "\tTotal Number of Items : " << numOfItems << endl << endl;
}

int TempType::ReplaceItemFromQueue(ItemType& item) {
	if (tempItemList.Replace(item)==-1) return 0;
	else return 1;
}