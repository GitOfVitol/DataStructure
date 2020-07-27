#include "AddToTempWindow.h"

AddToTempWindow::AddToTempWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::AddToTempWindow), app(main_app)
{
	ui->setupUi(this);
}

AddToTempWindow::~AddToTempWindow()
{
	delete ui;
}

void AddToTempWindow::addTempItem() {
	ItemType item;
	if (!ui->plainTextEdit->toPlainText().isEmpty()) {
		item.SetPhotoOfArticle(ui->plainTextEdit->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_2->toPlainText().isEmpty()) {
		item.SetName(ui->plainTextEdit_2->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_3->toPlainText().isEmpty()) {
		item.SetType(ui->plainTextEdit_3->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_4->toPlainText().isEmpty()) {
		item.SetUse(ui->plainTextEdit_4->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_5->toPlainText().isEmpty()) {
		item.SetDateOfPurchase(ui->plainTextEdit_5->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit_6->toPlainText().isEmpty()) {
		item.SetTotalNum(ui->plainTextEdit_6->toPlainText().toInt());
	}

	int check = app->AddToTempList(item);
	if (check == 1) {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Succeed!"));
	}
	else {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Same Name in MasterList!"));
	}
}

void AddToTempWindow::clear() {
	ui->plainTextEdit->setPlainText("");
	ui->plainTextEdit_2->setPlainText("");
	ui->plainTextEdit_3->setPlainText("");
	ui->plainTextEdit_4->setPlainText("");
	ui->plainTextEdit_5->setPlainText("");
	ui->plainTextEdit_6->setPlainText("");
}