#include "DisplayStorageTempWindow.h"

DisplayStorageTempWindow::DisplayStorageTempWindow(Application* main_app, QWidget* parent)
	: QDialog(parent), ui(new Ui::DisplayStorageTempWindow), app(main_app)
{
	ui->setupUi(this);

	itemNum = 0;
	StorageType curSto;
	app->StorageList.ResetList();
	app->StorageList.GetNextItem(curSto);
	string stoName;
	string stoPho;
	string stoLoc;
	QString qStoName;
	QString qStoPho;
	QString qStoLoc;

	int conId;
	string conPho;
	string conLoc;
	QString qConId;
	QString qConPho;
	QString qConLoc;
	ContainerType curCon;

	for (int i = 0; i < app->GetStorageLength(); i++) {
		curSto.ResetContainerList();
		curSto.GetNextContainer(curCon);
		ui->tableWidget->setRowCount(itemNum + 1);

		stoName = curSto.GetStorageId();
		qStoName = QString::fromStdString(stoName);
		stoLoc = curSto.GetStorageLocation();
		qStoLoc = QString::fromStdString(stoLoc);

		conId = curCon.GetContainerId();
		qConId = QString::number(conId);
		conLoc = curCon.GetLocation();
		qConLoc = QString::fromStdString(conLoc);

		string curStoPho;
		curSto.storagePhoto.ResetList();
		curSto.storagePhoto.GetNextItem(curStoPho);
		if (curStoPho == "bookshelf") {
			QTableWidgetItem* addItem = new QTableWidgetItem;
			addItem->setData(Qt::DecorationRole, QPixmap("photo/BookShelf.jpg").scaled(200, 200, Qt::KeepAspectRatio));
			ui->tableWidget->setItem(itemNum, 1, addItem);
		}
		if (curStoPho == "closet") {
			QTableWidgetItem* addItem = new QTableWidgetItem;
			addItem->setData(Qt::DecorationRole, QPixmap("photo/closet.png").scaled(200, 200, Qt::KeepAspectRatio));
			ui->tableWidget->setItem(itemNum, 1, addItem);
		}
		if (curStoPho == "drawer") {
			QTableWidgetItem* addItem = new QTableWidgetItem;
			addItem->setData(Qt::DecorationRole, QPixmap("photo/drawer.png").scaled(200, 200, Qt::KeepAspectRatio));
			ui->tableWidget->setItem(itemNum, 1, addItem);
		}
		if (curStoPho == "refrigerator") {
			QTableWidgetItem* addItem = new QTableWidgetItem;
			addItem->setData(Qt::DecorationRole, QPixmap("photo/refrigerator.png").scaled(200, 200, Qt::KeepAspectRatio));
			ui->tableWidget->setItem(itemNum, 1, addItem);
		}
		ui->tableWidget->setItem(itemNum, 0, new QTableWidgetItem(qStoName));
		ui->tableWidget->setItem(itemNum, 2, new QTableWidgetItem(qStoLoc));
		ui->tableWidget->setItem(itemNum, 3, new QTableWidgetItem(qConId));
		ui->tableWidget->setItem(itemNum, 4, new QTableWidgetItem(qConLoc));
		itemNum++;
		ui->tableWidget->resizeRowsToContents();
		ui->tableWidget->resizeColumnsToContents();

		for (int i = 1; i < curSto.GetCurrentNum(); i++) {
			curSto.GetNextContainer(curCon);
			conId = curCon.GetContainerId();
			qConId = QString::number(conId);
			conLoc = curCon.GetLocation();
			qConLoc = QString::fromStdString(conLoc);

			ui->tableWidget->setRowCount(itemNum + 1);
			ui->tableWidget->setItem(itemNum, 0, new QTableWidgetItem(" "));
			ui->tableWidget->setItem(itemNum, 2, new QTableWidgetItem(" "));
			ui->tableWidget->setItem(itemNum, 3, new QTableWidgetItem(qConId));
			ui->tableWidget->setItem(itemNum, 4, new QTableWidgetItem(qConLoc));
			
			ui->tableWidget->resizeRowsToContents();
			ui->tableWidget->resizeColumnsToContents();
			itemNum++;
		}
		app->StorageList.GetNextItem(curSto);
	}
}

/*
DisplayStorageTempWindow::DisplayStorageTempWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::DisplayStorageTempWindow), app(main_app)
{
	ui->setupUi(this);

	itemNum = 0;
	StorageType curSto;
	app->StorageList.ResetList();
	app->StorageList.GetNextItem(curSto);
	string stoName;
	string stoPho;
	string stoLoc;
	QString qStoName;
	QString qStoPho;
	QString qStoLoc;

	int conId;
	string conPho;
	string conLoc;
	QString qConId;
	QString qConPho;
	QString qConLoc;
	ContainerType curCon;

	for (int i = 0; i < app->GetStorageLength(); i++) {
		curSto.ResetContainerList();
		curSto.GetNextContainer(curCon);
		ui->tableWidget->setRowCount(itemNum + 1);

		stoName = curSto.GetStorageId();
		qStoName = QString::fromStdString(stoName);
		stoLoc = curSto.GetStorageLocation();
		qStoLoc = QString::fromStdString(stoLoc);

		conId = curCon.GetContainerId();
		qConId = QString::number(conId);
		conLoc = curCon.GetLocation();
		qConLoc = QString::fromStdString(conLoc);
		ui->tableWidget->setItem(itemNum, 0, new QTableWidgetItem(qStoName));
		ui->tableWidget->setItem(itemNum, 2, new QTableWidgetItem(qStoLoc));
		QTableWidgetItem* item = new QTableWidgetItem;
		item->setIcon(QIcon("D:\Visual Studio 2019\photo\Bookshelf.png"));
		ui->tableWidget->setItem(itemNum, 1, item);
		ui->tableWidget->setItem(itemNum, 3, new QTableWidgetItem(qConId));
		ui->tableWidget->setItem(itemNum, 5, new QTableWidgetItem(qConLoc));
		itemNum++;
		for (int i = 1; i < curSto.GetCurrentNum(); i++) {
			curSto.GetNextContainer(curCon);
			conId = curCon.GetContainerId();
			qConId = QString::number(conId);
			conLoc = curCon.GetLocation();
			qConLoc = QString::fromStdString(conLoc);
			ui->tableWidget->setRowCount(itemNum + 1);
			ui->tableWidget->setItem(itemNum, 0, new QTableWidgetItem(" "));
			ui->tableWidget->setItem(itemNum, 2, new QTableWidgetItem(" "));
			ui->tableWidget->setItem(itemNum, 3, new QTableWidgetItem(qConId));
			ui->tableWidget->setItem(itemNum, 5, new QTableWidgetItem(qConLoc));
			itemNum++;
		}
		app->StorageList.GetNextItem(curSto);
	}
}
*/

/*
DisplayStorageTempWindow::DisplayStorageTempWindow(Application* main_app, QWidget *parent)
	: QDialog(parent), ui(new Ui::DisplayStorageTempWindow), app(main_app)
{
	ui->setupUi(this);

	itemNum = 0;
	StorageType curSto;
	app->StorageList.ResetList();
	app->StorageList.GetNextItem(curSto);
	string stoName;
	QString qStoName;
	int conId;
	QString qConId;
	ContainerType curCon;

	for (int i = 0; i < app->GetStorageLength(); i++) {
		curSto.ResetContainerList();
		curSto.GetNextContainer(curCon);
		ui->tableWidget->setRowCount(itemNum + 1);
		stoName = curSto.GetStorageId();
		qStoName = QString::fromStdString(stoName);
		conId = curCon.GetContainerId();
		qConId = QString::number(conId);
		ui->tableWidget->setItem(itemNum, 0, new QTableWidgetItem(qStoName));
		ui->tableWidget->setItem(itemNum, 1, new QTableWidgetItem(qConId));
		itemNum++;
		for (int i = 1; i < curSto.GetCurrentNum(); i++) {
			curSto.GetNextContainer(curCon);
			conId = curCon.GetContainerId();
			qConId = QString::number(conId);
			ui->tableWidget->setRowCount(itemNum + 1);
			ui->tableWidget->setItem(itemNum, 0, new QTableWidgetItem(" "));
			ui->tableWidget->setItem(itemNum, 1, new QTableWidgetItem(qConId));
			itemNum++;
		}
		app->StorageList.GetNextItem(curSto);
	}
}
*/

DisplayStorageTempWindow::~DisplayStorageTempWindow()
{
	delete ui;
}
