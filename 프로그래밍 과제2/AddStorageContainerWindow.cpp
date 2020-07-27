#include "AddStorageContainerWindow.h"

AddStorageContainerWindow::AddStorageContainerWindow(Application* main_app, QWidget* parent)
	: QDialog(parent), ui(new Ui::AddStorageContainerWindow), app(main_app)
{
	ui->setupUi(this);

	ui->plainTextEdit->setPlaceholderText("You must type.");
	ui->plainTextEdit_2->setPlaceholderText("If Storage already exists, don't type.");
	ui->plainTextEdit_3->setPlaceholderText("If Storage already exists, don't type.");
	ui->plainTextEdit_4->setPlaceholderText("You must type.");
	ui->plainTextEdit_5->setPlaceholderText("If Container already exists, don't type.");
	ui->plainTextEdit_6->setPlaceholderText("If Container already exists, don't type.");
}

AddStorageContainerWindow::~AddStorageContainerWindow()
{
	delete ui;
}

void AddStorageContainerWindow::addStorageContainer() {
	StorageType storage;
	ContainerType container;
	if (!ui->plainTextEdit->toPlainText().isEmpty()) {
		storage.SetStorageId(ui->plainTextEdit->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_2->toPlainText().isEmpty()) {
		storage.SetStorageLocation(ui->plainTextEdit_2->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_3->toPlainText().isEmpty()) {
		storage.AddStoragePhoto(ui->plainTextEdit_3->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_4->toPlainText().isEmpty()) {
		container.SetContainerId(ui->plainTextEdit_4->toPlainText().toInt());
	}
	if (!ui->plainTextEdit_5->toPlainText().isEmpty()) {
		container.SetConLocation(ui->plainTextEdit_5->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_6->toPlainText().isEmpty()) {
		container.AddPhoto(ui->plainTextEdit_6->toPlainText().toStdString());
	}
	
	int check = app->AddStorageContainerInfo(storage, container);
	if (check == 2) {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Same Container!"));
	}
	else if (check == 1) {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Succeed!"));
	}
	else {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Failed!"));
	}
	
}

void AddStorageContainerWindow::clear() {
	ui->plainTextEdit->setPlainText("");
	ui->plainTextEdit_2->setPlainText("");
	ui->plainTextEdit_3->setPlainText("");
	ui->plainTextEdit_4->setPlainText("");
	ui->plainTextEdit_5->setPlainText("");
	ui->plainTextEdit_6->setPlainText("");
}