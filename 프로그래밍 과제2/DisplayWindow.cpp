#include "DisplayWindow.h"

DisplayWindow::DisplayWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::DisplayWindow), app(main_app)
{
	ui->setupUi(this);
}

DisplayWindow::~DisplayWindow()
{
	delete ui;
}

void DisplayWindow::displayMasterList() {
	displayMaster = new DisplayMasterListWindow(app);
	displayMaster->exec();
}

void DisplayWindow::displayTempList() {
	displayTemp = new DisplayTempListWindow(app);
	displayTemp->exec();
}

void DisplayWindow::displayStoCon() {
	displayStoConWin = new DisplayStorageTempWindow(app);
	displayStoConWin->exec();
}

void DisplayWindow::displayStoSimple() {
	displayStoSimWin = new DisplayStoSimItemWindow(app);
	displayStoSimWin->exec();
}

void DisplayWindow::displayStoDetail() {
	displayStoDetailWin = new DisplayStoDetailItemWindow(app);
	displayStoDetailWin->exec();
}