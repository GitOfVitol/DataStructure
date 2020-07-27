#include "AddItemWindow.h"

AddItemWindow::AddItemWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::AddItemWindow), app(main_app)
{
	ui->setupUi(this);
}

AddItemWindow::~AddItemWindow()
{
	delete ui;
}

void AddItemWindow::exit() { done(QDialog::Accepted); }

void AddItemWindow::AddItemButton1() {
	addToMasterWindow = new AddToMasterWindow(app);
	addToMasterWindow->exec();
}

void AddItemWindow::AddItemButton2() {
	addToTempWindow = new AddToTempWindow(app);
	addToTempWindow->exec();
}

void AddItemWindow::AddItemButton3() {
	addMasterToTempWin = new AddMasterToTempWin(app);
	addMasterToTempWin->exec();
}

void AddItemWindow::AddItemButton4() {
	addTempToMaster1stItemWin = new AddTempToMaster1stItemWindow(app);
	addTempToMaster1stItemWin->exec();
}

void AddItemWindow::AddItemButton5() {
	addTempToMasterWin = new AddTempToMasterWindow(app);
	addTempToMasterWin->exec();
}