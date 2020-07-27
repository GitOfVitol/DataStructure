#include "SearchTempListWindow.h"

SearchTempListWindow::SearchTempListWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::SearchTempListWindow), app(main_app), text0("0"), text1("1"), text2("2"), text3("3"), text4("4")
{
	ui->setupUi(this);
	ui->comboBox->addItem("Name(Totally Same)");
	ui->comboBox->addItem("Name");
	ui->comboBox->addItem("Use");
	ui->comboBox->addItem("Type");
	ui->comboBox->addItem("Date Of Purchase");
}

SearchTempListWindow::~SearchTempListWindow()
{
	delete ui;
}

void SearchTempListWindow::SetTableWidget() {
	string name, photo, type, use, dateOfPur;
	int totalNum;
	QString qName, qPhoto, qType, qUse, qDateOfPur, qTotalNum;

	ui->tableWidget->setRowCount(itemNum + 1);
	name = tempItem.GetName();
	photo = tempItem.GetPhotoOfArticle();
	type = tempItem.GetType();
	use = tempItem.GetUse();
	dateOfPur = tempItem.GetDateOfPurchase();
	totalNum = tempItem.GetTotalNum();

	qName = QString::fromStdString(name);
	qType = QString::fromStdString(type);
	qUse = QString::fromStdString(use);
	qDateOfPur = QString::fromStdString(dateOfPur);
	qTotalNum = QString::number(totalNum);

	ui->tableWidget->setItem(itemNum, 0, new QTableWidgetItem(qName));
	if (photo == "datastructure") {
		QTableWidgetItem* addItem = new QTableWidgetItem;
		addItem->setData(Qt::DecorationRole, QPixmap("photo/datastructure.png").scaled(200, 200, Qt::KeepAspectRatio));
		ui->tableWidget->setItem(itemNum, 1, addItem);
	}
	if (photo == "os") {
		QTableWidgetItem* addItem = new QTableWidgetItem;
		addItem->setData(Qt::DecorationRole, QPixmap("photo/OS.png").scaled(200, 200, Qt::KeepAspectRatio));
		ui->tableWidget->setItem(itemNum, 1, addItem);
	}
	if (photo == "database") {
		QTableWidgetItem* addItem = new QTableWidgetItem;
		addItem->setData(Qt::DecorationRole, QPixmap("photo/database.png").scaled(200, 200, Qt::KeepAspectRatio));
		ui->tableWidget->setItem(itemNum, 1, addItem);
	}
	if (photo == "coats") {
		QTableWidgetItem* addItem = new QTableWidgetItem;
		addItem->setData(Qt::DecorationRole, QPixmap("photo/coats.png").scaled(200, 200, Qt::KeepAspectRatio));
		ui->tableWidget->setItem(itemNum, 1, addItem);
	}
	if (photo == "mintchoco") {
		QTableWidgetItem* addItem = new QTableWidgetItem;
		addItem->setData(Qt::DecorationRole, QPixmap("photo/mintchoco.png").scaled(200, 200, Qt::KeepAspectRatio));
		ui->tableWidget->setItem(itemNum, 1, addItem);
	}
	if (photo == "sharppencil") {
		QTableWidgetItem* addItem = new QTableWidgetItem;
		addItem->setData(Qt::DecorationRole, QPixmap("photo/sharppencil.png").scaled(200, 200, Qt::KeepAspectRatio));
		ui->tableWidget->setItem(itemNum, 1, addItem);
	}
	if (photo == "shirts") {
		QTableWidgetItem* addItem = new QTableWidgetItem;
		addItem->setData(Qt::DecorationRole, QPixmap("photo/shirts.png").scaled(200, 200, Qt::KeepAspectRatio));
		ui->tableWidget->setItem(itemNum, 1, addItem);
	}
	if (photo == "towel") {
		QTableWidgetItem* addItem = new QTableWidgetItem;
		addItem->setData(Qt::DecorationRole, QPixmap("photo/towel.png").scaled(200, 200, Qt::KeepAspectRatio));
		ui->tableWidget->setItem(itemNum, 1, addItem);
	}	
	ui->tableWidget->setItem(itemNum, 2, new QTableWidgetItem(qType));
	ui->tableWidget->setItem(itemNum, 3, new QTableWidgetItem(qUse));
	ui->tableWidget->setItem(itemNum, 4, new QTableWidgetItem(qDateOfPur));
	ui->tableWidget->setItem(itemNum, 5, new QTableWidgetItem(qTotalNum));

	ui->tableWidget->resizeRowsToContents();
	ui->tableWidget->resizeColumnsToContents();
}

void SearchTempListWindow::Message(bool isFind) {
	if (isFind) {
		QMessageBox::information(this, "Search", "Succeed!");
	}
	else {
		QMessageBox::information(this, "Search", "No Item!");
	}
}

void SearchTempListWindow::search() {
	QString index = QString::number(ui->comboBox->currentIndex());
	itemNum = 0;

	app->TempList.ResetTempList();
	app->TempList.GetNextTempItem(tempItem);

	bool isFind = false;

	if (text0 == index) {
		for (int i = 0; i < app->TempList.GetNumOfItems(); i++) {
			string name = tempItem.GetName();
			if (ui->plainTextEdit->toPlainText().toStdString() == name) {
				SetTableWidget();
				itemNum++;
				app->TempList.GetNextTempItem(tempItem);
				isFind = true;
			}
			else {
				app->TempList.GetNextTempItem(tempItem);
			}
		}
		Message(isFind);
	}

	if (text1 == index) {
		for (int i = 0; i < app->TempList.GetNumOfItems(); i++) {
			string name = tempItem.GetName();
			if (name.find(ui->plainTextEdit->toPlainText().toStdString()) != -1) {
				SetTableWidget();
				itemNum++;
				app->TempList.GetNextTempItem(tempItem);
				isFind = true;
			}
			else {
				app->TempList.GetNextTempItem(tempItem);
			}
		}
		Message(isFind);
	}

	if (text2 == index) {
		for (int i = 0; i < app->TempList.GetNumOfItems(); i++) {
			string use = tempItem.GetUse();
			if (use.find(ui->plainTextEdit->toPlainText().toStdString()) != -1) {
				SetTableWidget();
				itemNum++;
				app->TempList.GetNextTempItem(tempItem);
				isFind = true;
			}
			else {
				app->TempList.GetNextTempItem(tempItem);
			}
		}
		Message(isFind);
	}

	if (text3 == index) {
		for (int i = 0; i < app->TempList.GetNumOfItems(); i++) {
			string type = tempItem.GetType();
			if (type.find(ui->plainTextEdit->toPlainText().toStdString()) != -1) {
				SetTableWidget();
				itemNum++;
				app->TempList.GetNextTempItem(tempItem);
				isFind = true;
			}
			else {
				app->TempList.GetNextTempItem(tempItem);
			}
		}
		Message(isFind);
	}

	if (text4 == index) {
		for (int i = 0; i < app->TempList.GetNumOfItems(); i++) {
			string dateOfPur = tempItem.GetDateOfPurchase();
			if (dateOfPur.find(ui->plainTextEdit->toPlainText().toStdString()) != -1) {
				SetTableWidget();
				itemNum++;
				app->TempList.GetNextTempItem(tempItem);
				isFind = true;
			}
			else {
				app->TempList.GetNextTempItem(tempItem);
			}
		}
		Message(isFind);
	}
}