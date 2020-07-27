#include "UpdateMasterListWindow.h"

UpdateMasterListWindow::UpdateMasterListWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::UpdateMasterListWindow), app(main_app)
{
	ui->setupUi(this);

	ui->plainTextEdit1->setPlaceholderText("You must type.");
	ui->plainTextEdit2->setPlaceholderText("You must type.");
	ui->plainTextEdit3->setPlaceholderText("You must type.");
	ui->plainTextEdit4->setPlaceholderText("You must type.");
	ui->plainTextEdit5->setPlaceholderText("You must type.");
	ui->plainTextEdit6->setPlaceholderText("You must type.");
	ui->plainTextEdit7->setPlaceholderText("You must type.");
	ui->plainTextEdit8->setPlaceholderText("You must type.");
}

UpdateMasterListWindow::~UpdateMasterListWindow()
{
	delete ui;
}

void UpdateMasterListWindow::view() {
	searchMasterWin = new SearchMasterListWindow(app);
	searchMasterWin->exec();
}

void UpdateMasterListWindow::viewStoCon() {
	displayStorageTempWindow = new DisplayStorageTempWindow(app);
	displayStorageTempWindow->exec();
}

void UpdateMasterListWindow::addStoCon() {
	addStorageContainerWindow = new AddStorageContainerWindow(app);
	addStorageContainerWindow->exec();
}

void UpdateMasterListWindow::exit() { done(QDialog::Accepted); }

void UpdateMasterListWindow::updateItem() {
	ItemType item;
	if (!ui->plainTextEdit1->toPlainText().isEmpty()) {
		item.SetPhotoOfArticle(ui->plainTextEdit1->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit2->toPlainText().isEmpty()) {
		item.SetStorageId(ui->plainTextEdit2->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit3->toPlainText().isEmpty()) {
		item.SetContainerId(ui->plainTextEdit3->toPlainText().toInt());
	}
	if (!ui->plainTextEdit4->toPlainText().isEmpty()) {
		item.SetName(ui->plainTextEdit4->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit5->toPlainText().isEmpty()) {
		item.SetType(ui->plainTextEdit5->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit6->toPlainText().isEmpty()) {
		item.SetUse(ui->plainTextEdit6->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit7->toPlainText().isEmpty()) {
		item.SetDateOfPurchase(ui->plainTextEdit7->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit8->toPlainText().isEmpty()) {
		item.SetTotalNum(ui->plainTextEdit8->toPlainText().toInt());
	}

	int check = app->ReplaceItem(item);
	if (check == 1) {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Succeed!"));
	}
	else if (check == 2) {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("No Storage!"));
	}
	else if (check == 3) {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("No Container!"));
	}
	else {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Wrong Name!"));
	}

}

void UpdateMasterListWindow::clear() {
	ui->plainTextEdit1->setPlainText("");
	ui->plainTextEdit2->setPlainText("");
	ui->plainTextEdit3->setPlainText("");
	ui->plainTextEdit4->setPlainText("");
	ui->plainTextEdit5->setPlainText("");
	ui->plainTextEdit6->setPlainText("");
	ui->plainTextEdit7->setPlainText("");
	ui->plainTextEdit8->setPlainText("");
}