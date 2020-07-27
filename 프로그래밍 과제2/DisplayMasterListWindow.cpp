#include "DisplayMasterListWindow.h"

DisplayMasterListWindow::DisplayMasterListWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::DisplayMasterListWindow), app(main_app)
{
	ui->setupUi(this);

	itemNum = 0;
	DoublyIterator<ItemType> iterator(app->MasterList);
	ItemType tempItem = iterator.Next();
	string name, photo, stoName, type, use, dateOfPur;
	int conId, totalNum;
	QString qName, qStoName, qType, qUse, qDateOfPur, qConId, qTotalNum;

	while (iterator.NextNotNull()) {
		ui->tableWidget->setRowCount(itemNum + 1);
		name = tempItem.GetName();
		photo = tempItem.GetPhotoOfArticle();
		stoName = tempItem.GetStorageId();
		type = tempItem.GetType();
		use = tempItem.GetUse();
		dateOfPur = tempItem.GetDateOfPurchase();
		conId = tempItem.GetContainerId();
		totalNum = tempItem.GetTotalNum();

		qName = QString::fromStdString(name);
		qStoName = QString::fromStdString(stoName);
		qType = QString::fromStdString(type);
		qUse = QString::fromStdString(use);
		qDateOfPur = QString::fromStdString(dateOfPur);
		qConId = QString::number(conId);
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
		ui->tableWidget->setItem(itemNum, 2, new QTableWidgetItem(qStoName));
		ui->tableWidget->setItem(itemNum, 3, new QTableWidgetItem(qConId));
		ui->tableWidget->setItem(itemNum, 4, new QTableWidgetItem(qType));
		ui->tableWidget->setItem(itemNum, 5, new QTableWidgetItem(qUse));
		ui->tableWidget->setItem(itemNum, 6, new QTableWidgetItem(qDateOfPur));
		ui->tableWidget->setItem(itemNum, 7, new QTableWidgetItem(qTotalNum));
		ui->tableWidget->resizeRowsToContents();
		ui->tableWidget->resizeColumnsToContents();

		itemNum++;
		tempItem = iterator.Next();
	}
}

DisplayMasterListWindow::~DisplayMasterListWindow()
{
	delete ui;
}

void DisplayMasterListWindow::move() {
	displayStoConWin = new DisplayStorageTempWindow(app);
	displayStoConWin->exec();
}