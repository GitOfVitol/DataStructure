#include "DeleteItemWindow.h"

DeleteItemWindow::DeleteItemWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::DeleteItemWindow), app(main_app)
{
	ui->setupUi(this);
}

DeleteItemWindow::~DeleteItemWindow()
{
	delete ui;
}

void DeleteItemWindow::deleteMasterList() {
	deleteMasterListWin = new DeleteMasterListWindow(app);
	deleteMasterListWin->exec();
}

void DeleteItemWindow::delete1stTempList() {
	ItemType item;
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Delete Item", "Are You Sure To Delete?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {
		app->DequeueItemFromTemp(item);
	}
	else {
		return;
	}
}

void DeleteItemWindow::deleteTempList() {
	deleteTempListWin = new DeleteTempListWindow(app);
	deleteTempListWin->exec();
}

void DeleteItemWindow::makeEmptyMaster() {
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Delete Item", "Are You Sure To Make Empty All of MasterList?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {
		app->MakeEmptyLIst();
	}
	else {
		return;
	}
}