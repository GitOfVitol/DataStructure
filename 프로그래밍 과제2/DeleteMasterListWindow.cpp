#include "DeleteMasterListWindow.h"

DeleteMasterListWindow::DeleteMasterListWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::DeleteMasterListWindow), app(main_app)
{
	ui->setupUi(this);
}

DeleteMasterListWindow::~DeleteMasterListWindow()
{
	delete ui;
}

void DeleteMasterListWindow::viewMasterList() {
	displayMasterListWin = new DisplayMasterListWindow(app);
	displayMasterListWin->exec();
}

void DeleteMasterListWindow::deleteFromMaster() {
	ItemType item;
	if (!ui->plainTextEdit->toPlainText().isEmpty()) {
		item.SetName(ui->plainTextEdit->toPlainText().toStdString());
	}
	int check = app->DeleteItemFromMaster(item);
	if (check == 1) {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Succeed!"));
	}
	else {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Wrong Name!"));
	}
}