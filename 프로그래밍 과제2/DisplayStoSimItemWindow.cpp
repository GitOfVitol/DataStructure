#include "DisplayStoSimItemWindow.h"

DisplayStoSimItemWindow::DisplayStoSimItemWindow(Application* main_app, QWidget* parent)
	: QDialog(parent), ui(new Ui::DisplayStoSimItemWindow), app(main_app)
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

DisplayStoSimItemWindow::~DisplayStoSimItemWindow()
{
	delete ui;
}

void DisplayStoSimItemWindow::setContainerCombo() {
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

void DisplayStoSimItemWindow::SetTableWidget() {
	string name, photo, type;
	int conId;
	QString qName, qPhoto, qType, qConId;

	ui->tableWidget->setRowCount(itemNum + 1);
	name = tempSimpleItem.GetName();
	photo = tempSimpleItem.GetPhotoOfArticle();
	type = tempSimpleItem.GetType();
	conId = tempSimpleItem.GetContainerId();

	qName = QString::fromStdString(name);
	qType = QString::fromStdString(type);
	qConId = QString::number(conId);

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
	ui->tableWidget->setItem(itemNum, 3, new QTableWidgetItem(qConId));
	ui->tableWidget->resizeRowsToContents();
	ui->tableWidget->resizeColumnsToContents();
}

void DisplayStoSimItemWindow::Message(bool isFind) {
	if (isFind) {
		QMessageBox::information(this, "Search", "Succeed!");
	}
	else {
		QMessageBox::information(this, "Search", "No Item!");
	}
}

void DisplayStoSimItemWindow::displaySimpleItem() {
	QString qStoName = ui->comboBox->currentText();
	string stoName = qStoName.toStdString();
	StorageType curSto;
	curSto.SetStorageId(stoName);
	app->StorageList.RetrieveSeq(curSto);

	itemNum = 0;

	QString qConId = ui->comboBox_2->currentText();
	if (qConId == "All Container") {
		bool isFind = false;
		ContainerType curCon;
		curSto.ResetContainerList();
		curSto.GetNextContainer(curCon);
		curCon.SimpleItemList.ResetList();
		for (int i = 0; i < curCon.GetSimpleListLength(); i++) {
			curCon.SimpleItemList.GetNextItem(tempSimpleItem);
			SetTableWidget();
			itemNum++;
			isFind = true;
		}
		for (int i = 1; i < curSto.GetCurrentNum(); i++) {
			curSto.GetNextContainer(curCon);
			curCon.SimpleItemList.ResetList();
			for (int i = 0; i < curCon.GetSimpleListLength(); i++) {
				curCon.SimpleItemList.GetNextItem(tempSimpleItem);
				SetTableWidget();
				itemNum++;
			}
		}
		Message(isFind);
	}
	else {
		bool isFind = false;
		int conId = qConId.toInt();
		ContainerType curCon;
		curCon.SetContainerId(conId);
		curSto.GetContainer(curCon);
		curCon.SimpleItemList.ResetList();
		for (int i = 0; i < curCon.GetSimpleListLength(); i++) {
			curCon.SimpleItemList.GetNextItem(tempSimpleItem);
			SetTableWidget();
			itemNum++;
			isFind = true;
		}
		Message(isFind);
	}
}

void DisplayStoSimItemWindow::move() {
	displayStoConWin = new DisplayStorageTempWindow(app);
	displayStoConWin->exec();
}