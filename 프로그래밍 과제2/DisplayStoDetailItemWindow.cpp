#include "DisplayStoDetailItemWindow.h"

DisplayStoDetailItemWindow::DisplayStoDetailItemWindow(Application* main_app, QWidget* parent)
	: QDialog(parent), ui(new Ui::DisplayStoDetailItemWindow), app(main_app)
{
	ui->setupUi(this);

	StorageType curSto;
	app->StorageList.ResetList();
	app->StorageList.GetNextItem(curSto);
	string stoName;
	QString qStoName;
	for (int i = 0; i < app->GetStorageLength(); i++) {
		stoName = curSto.GetStorageId();
		qStoName = QString::fromStdString(stoName);
		ui->comboBox->addItem(qStoName);
		app->StorageList.GetNextItem(curSto);

	}
}


DisplayStoDetailItemWindow::~DisplayStoDetailItemWindow()
{
	delete ui;
}

void DisplayStoDetailItemWindow::setContainerCombo() {
	ui->comboBox_2->clear();
	ui->comboBox_2->addItem("All Container");
	QString qStoName = ui->comboBox->currentText();
	string stoName = qStoName.toStdString();
	StorageType curSto;
	curSto.SetStorageId(stoName);
	app->StorageList.RetrieveSeq(curSto);

	ContainerType curCon;
	curSto.ResetContainerList();
	curSto.GetNextContainer(curCon);
	int conId = curCon.GetContainerId();
	QString qConId = QString::number(conId);
	ui->comboBox_2->addItem(qConId);
	for (int i = 1; i < curSto.GetCurrentNum(); i++) {
		curSto.GetNextContainer(curCon);
		conId = curCon.GetContainerId();
		qConId = QString::number(conId);
		ui->comboBox_2->addItem(qConId);
	}
}

void DisplayStoDetailItemWindow::SetTableWidget() {
	string name, photo, type, use, dateOfPur;
	int conId, totalNum;
	QString qName, qPhoto, qType, qUse, qDateOfPur, qConId, qTotalNum;

	ui->tableWidget->setRowCount(itemNum + 1);
	name = tempItem.GetName();
	photo = tempItem.GetPhotoOfArticle();
	type = tempItem.GetType();
	use = tempItem.GetUse();
	dateOfPur = tempItem.GetDateOfPurchase();
	conId = tempItem.GetContainerId();
	totalNum = tempItem.GetTotalNum();

	qName = QString::fromStdString(name);
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
	ui->tableWidget->setItem(itemNum, 2, new QTableWidgetItem(qConId));
	ui->tableWidget->setItem(itemNum, 3, new QTableWidgetItem(qType));
	ui->tableWidget->setItem(itemNum, 4, new QTableWidgetItem(qUse));
	ui->tableWidget->setItem(itemNum, 5, new QTableWidgetItem(qDateOfPur));
	ui->tableWidget->setItem(itemNum, 6, new QTableWidgetItem(qTotalNum));

	ui->tableWidget->resizeRowsToContents();
	ui->tableWidget->resizeColumnsToContents();
}

void DisplayStoDetailItemWindow::Message(bool isFind) {
	if (isFind) {
		QMessageBox::information(this, "Search", "Succeed!");
	}
	else {
		QMessageBox::information(this, "Search", "No Item!");
	}
}

void DisplayStoDetailItemWindow::display() {
	QString qStoName = ui->comboBox->currentText();
	string stoName = qStoName.toStdString();
	StorageType curSto;
	curSto.SetStorageId(stoName);
	app->StorageList.RetrieveSeq(curSto);

	itemNum = 0;
	DoublyIterator<ItemType> iterator(app->MasterList);
	tempItem = iterator.Next();

	QString qConId = ui->comboBox_2->currentText();
	bool isFind = false;

	if (qConId == "All Container") {
		while (iterator.NextNotNull()) {
			string tempStoName = tempItem.GetStorageId();
			if (tempStoName == stoName) {
				SetTableWidget();
				itemNum++;
				tempItem = iterator.Next();
				isFind = true;
			}
			else {
				tempItem = iterator.Next();
			}
		}
		Message(isFind);
	}
	else {
		while (iterator.NextNotNull()) {
			string tempStoName = tempItem.GetStorageId();
			int tempConId = tempItem.GetContainerId();
			if (tempStoName == stoName && tempConId == qConId.toInt()) {
				SetTableWidget();
				itemNum++;
				tempItem = iterator.Next();
				isFind = true;
			}
			else {
				tempItem = iterator.Next();
			}
		}
		Message(isFind);
	}
}

void DisplayStoDetailItemWindow::move() {
	displayStoConWin = new DisplayStorageTempWindow(app);
	displayStoConWin->exec();
}