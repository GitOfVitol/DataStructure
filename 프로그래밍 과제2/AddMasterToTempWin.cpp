#include "AddMasterToTempWin.h"

AddMasterToTempWin::AddMasterToTempWin(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::AddMasterToTempWin), app(main_app)
{
	ui->setupUi(this);
}

AddMasterToTempWin::~AddMasterToTempWin()
{
	delete ui;
}

void AddMasterToTempWin::displayMasterList() {
	displayMasterListWindow = new DisplayMasterListWindow(app);
	displayMasterListWindow->exec();
}

void AddMasterToTempWin::addMasterToTemp() {
	ItemType item;
	if (!ui->plainTextEdit->toPlainText().isEmpty()) {
		item.SetName(ui->plainTextEdit->toPlainText().toStdString());
	}
	int check = app->AddMasterToTemp(item);
	if (check == 1) {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Succeed!"));
	}
	else {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Not Same Name!"));
	}
}