#include "DeleteTempListWindow.h"

DeleteTempListWindow::DeleteTempListWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::DeleteTempListWindow), app(main_app)
{
	ui->setupUi(this);
}

DeleteTempListWindow::~DeleteTempListWindow()
{
	delete ui;
}

void DeleteTempListWindow::viewTempList() {
	displayTempListWin = new DisplayTempListWindow(app);
	displayTempListWin->exec();
}

void DeleteTempListWindow::deleteTempList() {
	ItemType item;
	if (!ui->plainTextEdit->toPlainText().isEmpty()) {
		item.SetName(ui->plainTextEdit->toPlainText().toStdString());
	}
	int check = app->DeleteItemFromTemp(item);
	if (check == 1) {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Succeed!"));
	}
	else {
		QMessageBox::information(this, QString::fromLocal8Bit("Windows"), QString::fromLocal8Bit("Wrong Name!"));
	}
}