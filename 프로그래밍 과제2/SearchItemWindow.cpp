#include "SearchItemWindow.h"

SearchItemWindow::SearchItemWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::SearchItemWindow), app(main_app)
{
	ui->setupUi(this);
}

SearchItemWindow::~SearchItemWindow()
{
	delete ui;
}

void SearchItemWindow::searchMasterListButton() {
	searchMasterWin = new SearchMasterListWindow(app);
	searchMasterWin->exec();
}

void SearchItemWindow::searchTempListButton() {
	searchTempWin = new SearchTempListWindow(app);
	searchTempWin->exec();
}

void SearchItemWindow::searchTwoInfoMaster() {
	searchTwoInfoMasterWin = new SearchTwoInfoMasterWindow(app);
	searchTwoInfoMasterWin->exec();
}