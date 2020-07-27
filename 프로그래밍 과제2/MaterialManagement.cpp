#include "MaterialManagement.h"

MaterialManagement::MaterialManagement(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::MaterialManagementClass), app(new Application)
{
	ui->setupUi(this);
}

// AddItemWindow로 전환
void MaterialManagement::MainAddItemButton() {
	addItemWindow = new AddItemWindow(app);
	addItemWindow->exec();
}

// DeleteItemWindow로 전환
void MaterialManagement::MainDeleteItemButton() {
	deleteItemWindow = new DeleteItemWindow(app);
	deleteItemWindow->exec();
}

// UpdateItemWindow로 전환
void MaterialManagement::MainUpdateItemButton() {
	updateItemWindow = new UpdateItemWindow(app);
	updateItemWindow->exec();
}

// SearchItemWindow로 전환
void MaterialManagement::MainSearchItemButton() {
	searchItemWindow = new SearchItemWindow(app);
	searchItemWindow->exec();
}

// DisplayWindow로 전환
void MaterialManagement::MainDisplayButton() {
	displayWindow = new DisplayWindow(app);
	displayWindow->exec();
}