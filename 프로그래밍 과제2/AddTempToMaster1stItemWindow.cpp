#include "AddTempToMaster1stItemWindow.h"

AddTempToMaster1stItemWindow::AddTempToMaster1stItemWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::AddTempToMaster1stItemWindow), app(main_app)
{
	ui->setupUi(this);
}

AddTempToMaster1stItemWindow::~AddTempToMaster1stItemWindow()
{
	delete ui;
}

void AddTempToMaster1stItemWindow::view() {
	displayStoConWin = new DisplayStorageTempWindow(app);
	displayStoConWin->exec();
}

void AddTempToMaster1stItemWindow::addToMaster() {
	ItemType item;
	if (!ui->plainTextEdit->toPlainText().isEmpty()) {
		item.SetStorageId(ui->plainTextEdit->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_2->toPlainText().isEmpty()) {
		item.SetContainerId(ui->plainTextEdit_2->toPlainText().toInt());
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
		app->DequeueItemFromTemp(item);
		int check = app->AddToMasterList(item);
		if (check == 1) {
			QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Succeed!"));
		}
		else {
			QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Same Name!"));
		}
	}

}