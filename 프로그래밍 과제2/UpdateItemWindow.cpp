#include "UpdateItemWindow.h"

UpdateItemWindow::UpdateItemWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::UpdateItemWindow), app(main_app)
{
	ui->setupUi(this);
}

UpdateItemWindow::~UpdateItemWindow()
{
	delete ui;
}

void UpdateItemWindow::updateMaster() {
	updateMasterWin = new UpdateMasterListWindow(app);
	updateMasterWin->exec();
}

void UpdateItemWindow::updateTemp() {
	updateTempWin = new UpdateTempListWindow(app);
	updateTempWin->exec();
}