#include "MaterialManagement.h"

MaterialManagement::MaterialManagement(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::MaterialManagementClass), app(new Application)
{
	ui->setupUi(this);
}

// AddItemWindow�� ��ȯ
void MaterialManagement::MainAddItemButton() {
	addItemWindow = new AddItemWindow(app);
	addItemWindow->exec();
}

// DeleteItemWindow�� ��ȯ
void MaterialManagement::MainDeleteItemButton() {
	deleteItemWindow = new DeleteItemWindow(app);
	deleteItemWindow->exec();
}

// UpdateItemWindow�� ��ȯ
void MaterialManagement::MainUpdateItemButton() {
	updateItemWindow = new UpdateItemWindow(app);
	updateItemWindow->exec();
}

// SearchItemWindow�� ��ȯ
void MaterialManagement::MainSearchItemButton() {
	searchItemWindow = new SearchItemWindow(app);
	searchItemWindow->exec();
}

// DisplayWindow�� ��ȯ
void MaterialManagement::MainDisplayButton() {
	displayWindow = new DisplayWindow(app);
	displayWindow->exec();
}