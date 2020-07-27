#include "Application.h"

int Application::GetStorageLength() { return StorageList.GetLength(); }

int Application::AddStorageContainerInfo(StorageType& storage, ContainerType& container) {
	ContainerType tempCon;
	tempCon.SetContainerId(container.GetContainerId());
	if (StorageList.RetrieveSeq(storage)) {
		bool isFind = storage.GetContainer(tempCon);
		if (isFind) return 2;
		else { storage.AddContainer(container); }
		if (StorageList.Replace(storage)) return 1;
		else return 0;
	}
	else {
		storage.AddContainer(container);
		if (StorageList.Add(storage)) return 1;
		else return 0;
	}
}


// MasterList, StorageList ���� empty
void Application::MakeEmptyLIst() {
	MasterList.MakeEmpty();
	StorageList.MakeEmpty();
	cout << "All items are deleted! " << endl;
}

int Application::AddToMasterList(ItemType& item) {
	ItemType data;
	data.SetName(item.GetName());
	if (TempList.RetrieveItemFromQueue(data)) { return 0; }

	StorageType storage;
	storage.SetStorageId(item.GetStorageId()); //StorageId�� �ޱ� ���� �ӽ� StorageType ��ü storage ����

	ContainerType container;
	container.SetContainerId(item.GetContainerId()); //����� �Է� ���� container id �ʱ�ȭ

	SimpleItemType simepleitem;
	string inStoId = item.GetStorageId();
	int inConId = item.GetContainerId();
	string inName = item.GetName();
	string inType = item.GetType();
	string inPhoto = item.GetPhotoOfArticle();
	simepleitem.SetRecord(inPhoto, inStoId, inConId, inName, inType); //SimpleItemType�� �տ��� ����� �Է� ���� �ɷ� �ʱ�ȭ

	if (StorageList.RetrieveSeq(storage)) {//���� ����Ʈ�� storage id�� �ִ� ���

		bool isFind = storage.GetContainer(container); //container id�� ������ �ƴ��� �Ǵ��ϴ� ����
		//���� ������ storage�� container�� update, �ٸ��� ���� �Էµ� container id�� add 

		container.AddItem(simepleitem); //ContainerType�� �ʱ�ȭ�� SimpleItemType�� add

		if (isFind) { 
			if (!MasterList.Add(item)) { return 0; }
			storage.UpdateContainer(container); 
		}//container id�� �̹� �ִ°Ŵ� update
		else { return 3; } //container id�� ���°Ŵ� add

		if (StorageList.Replace(storage)) { return 1; } //���� StorageList�� ����� �Է¹��� StorageType���� ������Ʈ
		else return 0;
	}
	else {//���� ����Ʈ�� storage id�� ���� ���
		return 2;
	}

}
int Application::AddToTempList(ItemType& item) { //TempList�� add
	if (MasterList.Retrieve(item)) { // MasterList�� primary key Ȯ��
		return 0;
	}
	else {
		TempList.AddItemToQueue(item); // Enqueue
		return 1;
	}
}
int Application::AddTempToMasterUsingPrimary(ItemType& item) { //TempList->MasterList (Primary key�� add)
	if (TempList.RetrieveItemFromQueue(item)) {
		TempList.DeleteItemFromQueue(item); // TempList���� primary key�� ���� retrieve �� ���� delete
		return 1;
	}
	else return 0;
}
int Application::AddMasterToTemp(ItemType& item) { //MasterList->TempList
	if (!DeleteItemFromMaster(item)) return 0;
	tempItem.SetStorageId("");
	tempItem.SetContainerId(0);

	TempList.AddItemToQueue(tempItem);
	return 1;
}


int Application::DeleteItemFromMaster(ItemType& item) {
	tempItem.SetName(item.GetName()); //����ڷκ��� MasterList���� ������ item�� name(primary key)�� �Է�
	MasterList.Retrieve(tempItem);
	if (!MasterList.Delete(tempItem)) return 0;

	StorageType storage;
	storage.SetStorageId(tempItem.GetStorageId());

	ContainerType container;
	container.SetContainerId(tempItem.GetContainerId());

	SimpleItemType simpledata;
	simpledata.SetName(tempItem.GetName());

	StorageList.RetrieveSeq(storage);
	storage.GetContainer(container);
	container.DeleteItem(simpledata);
	storage.UpdateContainer(container);

	if (StorageList.Replace(storage)) {
		return 1;
	}
	else return 0;

}
int Application::DeleteItemFromTemp(ItemType& item) {
	if (TempList.DeleteItemFromQueue(item)) {
		return 1;
	}
	else return 0;
}
int Application::DequeueItemFromTemp(ItemType& item) {
	if (TempList.DequeueFromQueue(item)) {
		return 1;
	}
	else return 0;
}

//��ġ�ϴ� primary key�� ����Ʈ �������� replace
int Application::ReplaceItem(ItemType& item) {
	ItemType tempItem;
	tempItem.SetName(item.GetName());
	MasterList.Retrieve(tempItem);//����ڷκ��� �Է¹��� primary key�� �������� ���� MasterList�� �ִ� ���� ��������

	if (!MasterList.Replace(item)) return 0;

	StorageType tempStorage;
	tempStorage.SetStorageId(tempItem.GetStorageId());

	ContainerType tempContainer;
	tempContainer.SetContainerId(tempItem.GetContainerId()); //ContainerId�� �ޱ� ���� �ӽ� ContainerType ��ü data ����

	SimpleItemType tempSimpleItem;
	tempSimpleItem.SetName(tempItem.GetName());

	StorageList.RetrieveSeq(tempStorage);
	tempStorage.GetContainer(tempContainer);
	tempContainer.DeleteItem(tempSimpleItem);
	tempStorage.UpdateContainer(tempContainer);
	StorageList.Replace(tempStorage);

	StorageType updateStorage; // ������ ���� ���ְ� update�� ������ ��� ���ؼ� temp ������ update������ ����.
	updateStorage.SetStorageId(item.GetStorageId());

	ContainerType updateContainer;
	updateContainer.SetContainerId(item.GetContainerId());

	SimpleItemType updateSimpledata;
	string inStoId = item.GetStorageId();
	int inConId = item.GetContainerId();
	string inName = item.GetName();
	string inType = item.GetType();
	string inPhoto = item.GetPhotoOfArticle();
	updateSimpledata.SetRecord(inPhoto, inStoId, inConId, inName, inType); //SimpleItemType�� �տ��� ����� �Է� ���� �ɷ� �ʱ�ȭ

	if (StorageList.RetrieveSeq(updateStorage)) { //replace�� item�� storage id�� �̹� StorageList�� ���� ��
		bool isFind = updateStorage.GetContainer(updateContainer);
		updateContainer.AddItem(updateSimpledata); //ContainerType�� �ʱ�ȭ�� SimpleItemType�� add

		if (isFind) { updateStorage.UpdateContainer(updateContainer); }//container id�� �̹� �ִ°Ŵ� update
		else { return 3; } //container id�� ���°Ŵ� add

		if (StorageList.Replace(updateStorage)) return 1; //���� StorageList�� ����� �Է¹��� StorageType���� ������Ʈ
		else return 0;
	}
	else return 2; // replace�� item�� storage id�� StorageList�� ���� ��
}

int Application::ReplaceTempList(ItemType& item) {
	if (TempList.ReplaceItemFromQueue(item)) return 1;
	else return 0;
}

void Application::DisplayAllItem() {
	int select;
	cout << "\t1. Display All of MasterList" << endl;
	cout << "\t2. Display All of TempList" << endl;
	cout << "\t3. Display All of ContainerList in StorageList" << endl;
	cout << "\t4. Display All of ContainerList in StorageList specifically" << endl;
	cout << "\t5. Display a ContainerType(You choose a container ID)" << endl;
	cout << "\t6. Display All Photos of ContainerList" << endl;
	cout << "\tSelect a number! -->  ";
	cin >> select;
	cout << endl;

	switch (select) {
	case 1:
		PrintAllMasterList();
		break;
	case 2:
		PrintAllTempList();
		break;
	case 3:
		DisplayAllStorage();
		DisplayAllContainer(); // Container��� ���
		break;
	case 4:
		DisplayAllStorage();
		DisplayAllDetailsContainer(); // Container��� ���(item������ MasterList ������ ���)
		break;
	case 5:
		DisplayAllStorage();
		DisplayContainer(); // ���ϴ� Ư�� ContainerType�� ���.
		break;
	case 6:
		DisplayAllPhoto(); // containerlist�� photo ��� ���
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}

}
// Display all records in the MasterList on screen.
void Application::PrintAllMasterList() {
	cout << "\t< Current MasterList >" << endl;

	DoublyIterator<ItemType> iterator(MasterList);
	tempItem = iterator.Next();
	while (iterator.NextNotNull()) {
		tempItem.DisplayRecordOnScreen();
		tempItem = iterator.Next();
		cout << endl;
	}

}
void Application::PrintAllTempList() { //TempList��� ���
	TempList.PrintNumOfItems();
	TempList.PrintAllItemInQueue();
}
void Application::DisplayAllStorage() { //StorageList ���� ��� ���(ContainerList ����)
	cout << "\t--- Storage Information Of Current StorageLIst ---" << endl;
	cout << "\n\t------------------------------------" << endl << endl;
	cout << StorageList << endl;
}
void  Application::DisplayAllContainer() { //StorageList�� ContainerList���� ���(SimpleItem)
	string select;
	cout << "\tChoose Storage Id to display : ";
	cin >> select;
	tempStorage.SetStorageId(select);
	if (!StorageList.RetrieveSeq(tempStorage)) {
		cout << "\tWrong Storage Id!" << endl;
		return;
	}
	tempStorage.DisplayAllContainer();
}
void  Application::DisplayAllDetailsContainer() { //StorageList�� ContainerList���� ���(MasterList ����)
	string select;
	cout << "\tChoose Storage Id to display : ";
	cin >> select;
	tempStorage.SetStorageId(select);
	if (!StorageList.RetrieveSeq(tempStorage)) {
		cout << "\tWrong Storage Id!" << endl;
		return;
	}
	tempStorage.DisplayAllDetailsContainer(MasterList);
}
void Application::DisplayAllPhoto() { // ContainerList�� ��� ���� ���
	int length = StorageList.GetLength();
	StorageList.ResetList();
	for (int i = 0; i < length; i++) {
		StorageList.GetNextItem(tempStorage);
		cout << "\tStorage Id : " << tempStorage.GetStorageId() << endl;
		tempStorage.DisplayAllPhotoOfContainer();
	}
}
void Application::DisplayContainer() { // Ư�� container�� ���� ���� ���
	string selectStorage;
	int selectContainer;
	cout << "\tChoose Storage Id to display : ";
	cin.ignore();
	getline(cin, selectStorage);
	tempStorage.SetStorageId(selectStorage);
	if (!StorageList.RetrieveSeq(tempStorage)) {
		cout << "\tWrong Storage Id!" << endl;
		return;
	}
	tempStorage.DisplayAllPhotoOfContainer();
	cout << "\tChoose Container Id to display : ";
	cin >> selectContainer;
	tempContainer.SetContainerId(selectContainer);
	tempStorage.GetContainer(tempContainer);
	tempContainer.DisplayAllItem();
}

void Application::AddPhoto() { // StorageList, ContainerList�� ������ ���� ���� add
	int select;
	cout << "\t1. StorageList" << endl;
	cout << "\t2. ContainerList" << endl;
	cout << "\tSelect a number! -->  ";
	cin >> select;
	cout << endl;

	switch (select) {
	case 1:
		AddPhotoOfStorage();
		break;
	case 2:
		AddPhotoOfContainer();
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}
void Application::AddPhotoOfStorage() {
	DisplayAllStorage();

	StorageType storage;
	cout << "\t< Choose a Storage ID to add >" << endl;
	storage.SetStorageIdFromKB();
	if (!StorageList.RetrieveSeq(storage)) {
		cout << "\tWrong Storage Id!" << endl;
		return;
	}

	cout << "\tPhoto : ";
	string photoName;
	cin >> photoName;
	storage.AddStoragePhoto(photoName);
	StorageList.Replace(storage);
	cout << "\n\tPhoto is added succesfully!" << endl;
}
void Application::AddPhotoOfContainer() {
	DisplayAllPhoto();
	StorageType storage;

	cout << "\t< Choose a Storage ID and Container ID to add >" << endl;
	storage.SetStorageIdFromKB();
	if (!StorageList.RetrieveSeq(storage)) {
		cout << "\tWrong Storage Id!" << endl;
		return;
	}
	storage.AddContainerPhoto();
	StorageList.Replace(storage);
	cout << "\n\tPhoto is added succesfully!" << endl;

}

void Application::DeletePhoto() { // ContainerList, STorageList�� ���� photo ���� delete
	int select;
	cout << "\t1. StorageList" << endl;
	cout << "\t2. ContainerList" << endl;
	cout << "\tSelect a number! -->  ";
	cin >> select;
	cout << endl;

	switch (select) {
	case 1:
		DeletePhotoOfStorage();
		break;
	case 2:
		DeletePhotoOfContaienr();
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}
void Application::DeletePhotoOfStorage() {
	DisplayAllStorage();

	StorageType storage;
	cout << "\t< Choose a Storage ID to delete >" << endl;
	storage.SetStorageIdFromKB();
	if (!StorageList.RetrieveSeq(storage)) {
		cout << "\tWrong Storage Id!" << endl;
		return;
	}

	cout << "\tPhoto : ";
	string photoName;
	cin >> photoName;

	storage.DeleteStoragePhoto(photoName);
	StorageList.Replace(storage);

	cout << "\n\tPhoto is deleted succesfully!" << endl;
}
void Application::DeletePhotoOfContaienr() {
	DisplayAllPhoto();

	StorageType storage;

	cout << "\t< Choose a Storage ID and Container ID to delete >" << endl;
	storage.SetStorageIdFromKB();
	if (!StorageList.RetrieveSeq(storage)) {
		cout << "\tWrong Storage Id!" << endl;
		return;
	}

	storage.DeleteContainerPhoto();
	StorageList.Replace(storage);

	cout << "\n\tPhoto is deleted succesfully!" << endl;
}

void Application::UpdatePhoto() { // ContainerList, StorageList�� ���� Photo ���� update
	int select;
	cout << "\t1. StorageList" << endl;
	cout << "\t2. ContainerList" << endl;
	cout << "\tSelect a number! -->  ";
	cin >> select;
	cout << endl;

	switch (select) {
	case 1:
		UpdatePhotoOfStorage();
		break;
	case 2:
		UpdatePhotoOfContainer();
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}
void Application::UpdatePhotoOfStorage() {
	DisplayAllStorage();

	StorageType storage;
	cout << "\t< Choose a Storage ID to update >" << endl;
	storage.SetStorageIdFromKB();
	if (!StorageList.RetrieveSeq(storage)) {
		cout << "\tWrong Storage Id!" << endl;
		return;
	}

	string photoName;
	cout << "\tPhoto : ";
	cin >> photoName;

	string upPhoto;
	cout << "\tNew Photo : ";
	cin >> upPhoto;

	storage.UpdateStoragePhoto(photoName, upPhoto);
	StorageList.Replace(storage);
	cout << "\n\tPhoto is updated succesfully!" << endl;
}
void Application::UpdatePhotoOfContainer() {
	DisplayAllPhoto();

	StorageType storage;

	cout << "\t< Choose a Storage ID and Container ID to update >" << endl;
	storage.SetStorageIdFromKB();
	if (!StorageList.RetrieveSeq(storage)) {
		cout << "\tWrong Storage Id!" << endl;
		return;
	}

	storage.UpdateContainerPhoto();
	StorageList.Replace(storage);

	cout << "\n\tPhoto is updated succesfully!" << endl;
}

void Application::UpdateLocation() { //StorageList, ContainerList�� location update
	int select;
	cout << "\t1. StorageList" << endl;
	cout << "\t2. ContainerList" << endl;
	cout << "\tSelect a number! -->  ";
	cin >> select;
	cout << endl;

	switch (select) {
	case 1:
		UpdateStorageLocation();
		break;
	case 2:
		UpdateContainerLocation();
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}
void Application::UpdateStorageLocation() {
	DisplayAllStorage();

	StorageType storage;
	cout << "\t< Choose a Storage ID to update >" << endl;
	storage.SetStorageIdFromKB();
	if (!StorageList.RetrieveSeq(storage)) {
		cout << "\tWrong Storage Id!" << endl;
		return;
	}

	storage.SetStorageLocationFromKB();
	StorageList.Replace(storage);
	cout << "\n\tLocation of Storage is updated succesfully!" << endl;
}
void Application::UpdateContainerLocation() {
	DisplayAllPhoto();

	StorageType storage;
	cout << "\t< Choose a Storage ID to update >" << endl;
	storage.SetStorageIdFromKB();
	if (!StorageList.RetrieveSeq(storage)) {
		cout << "\tWrong Storage Id!" << endl;
		return;
	}

	storage.UpdateContainerLocation();
	StorageList.Replace(storage);
	cout << "\n\tLocation of Container is updated succesfully!" << endl;
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName) {
	m_InFile.open(fileName);

	if (m_InFile) return 1;
	else return 0;
}
// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName) {
	m_OutFile.open(fileName);

	if (m_OutFile) return 1;
	else return 0;
}
// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile() {
	int index = 0;
	ItemType data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	if (!OpenInFile(filename)) return 0;

	while (!m_InFile.eof())
	{
		data.ReadDataFromFile(m_InFile);
		MasterList.Add(data);
	}

	m_InFile.close();

	return 1;
}
// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile() {
	ItemType data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	if (!OpenOutFile(filename))	return 0;

	DoublyIterator<ItemType> iterator(MasterList);
	data = iterator.Next();
	while (iterator.NextNotNull()) {
		data.WriteDataToFile(m_OutFile);
		data = iterator.Next();
	}

	m_OutFile.close();

	return 1;
}