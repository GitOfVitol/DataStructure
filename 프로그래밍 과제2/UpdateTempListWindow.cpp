#include "UpdateTempListWindow.h"

UpdateTempListWindow::UpdateTempListWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::UpdateTempListWindow), app(main_app)
{
	ui->setupUi(this);
}

UpdateTempListWindow::~UpdateTempListWindow()
{
	delete ui;
}

void UpdateTempListWindow::exit() { done(QDialog::Accepted); }

void UpdateTempListWindow::view() {
	searchTempWin = new SearchTempListWindow(app);
	searchTempWin->exec();
}

void UpdateTempListWindow::updateItem() {
	ItemType item;
	if (!ui->plainTextEdit1->toPlainText().isEmpty()) {
		item.SetPhotoOfArticle(ui->plainTextEdit1->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit2->toPlainText().isEmpty()) {
		item.SetName(ui->plainTextEdit2->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit3->toPlainText().isEmpty()) {
		item.SetType(ui->plainTextEdit3->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit4->toPlainText().isEmpty()) {
		item.SetUse(ui->plainTextEdit4->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit5->toPlainText().isEmpty()) {
		item.SetDateOfPurchase(ui->plainTextEdit5->toPlainText().toStdString());
	}
	if (!ui->plainTextEdit6->toPlainText().isEmpty()) {
		item.SetTotalNum(ui->plainTextEdit6->toPlainText().toInt());
	}

	int check = app->ReplaceTempList(item);
	if (check == 1) {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Succeed!"));
	}
	else {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Wrong Name!"));
	}
}

void UpdateTempListWindow::clear() {
	ui->plainTextEdit1->setPlainText("");
	ui->plainTextEdit2->setPlainText("");
	ui->plainTextEdit3->setPlainText("");
	ui->plainTextEdit4->setPlainText("");
	ui->plainTextEdit5->setPlainText("");
	ui->plainTextEdit6->setPlainText("");
}