#include "AddTempToMasterWindow.h"

AddTempToMasterWindow::AddTempToMasterWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::AddTempToMasterWindow), app(main_app)
{
	ui->setupUi(this);
}

AddTempToMasterWindow::~AddTempToMasterWindow()
{
	delete ui;
}

void AddTempToMasterWindow::viewStoCon() {
	displayStoConWin = new DisplayStorageTempWindow(app);
	displayStoConWin->exec();
}

void AddTempToMasterWindow::viewTempList() {
	displayTempListWin = new DisplayTempListWindow(app);
	displayTempListWin->exec();
}

void AddTempToMasterWindow::addToMaster() {
	ItemType item;
	if (!ui->plainTextEdit->toPlainText().isEmpty()) {
		item.SetName(ui->plainTextEdit->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_2->toPlainText().isEmpty()) {
		item.SetStorageId(ui->plainTextEdit_2->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_3->toPlainText().isEmpty()) {
		item.SetContainerId(ui->plainTextEdit_3->toPlainText().toInt());
	}
	StorageType tempSto;
	ContainerType tempCon;
	tempSto.SetStorageId(item.GetStorageId());
	tempCon.SetContainerId(item.GetContainerId());
	if (!app->StorageList.RetrieveSeq(tempSto)) {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("No Storage!"));
		return;
	}
	else {
		bool isFind = tempSto.GetContainer(tempCon);
		if (!isFind) {
			QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("No Container!"));
			return;
		}
		ItemType tempItem;
		tempItem.SetName(item.GetName());
		if (app->AddTempToMasterUsingPrimary(tempItem)) {
			tempItem.SetStorageId(item.GetStorageId());
			tempItem.SetContainerId(item.GetContainerId());
			int check = app->AddToMasterList(tempItem);
			if (check == 1) {
				QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Succeed!"));
			}
		}
		else {
			QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Wrong Name!"));
		}

	}
}