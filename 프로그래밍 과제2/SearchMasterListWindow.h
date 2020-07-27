#pragma once

#include <QDialog>
#include "ui_SearchMasterListWindow.h"
#include "Application.h"
#include <qmessagebox.h>
#include "DisplayStorageTempWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SearchMasterListWindow; }
QT_END_NAMESPACE

class SearchMasterListWindow : public QDialog
{
	Q_OBJECT

public:
	SearchMasterListWindow(Application*, QWidget *parent = Q_NULLPTR);
	~SearchMasterListWindow();
	void SetTableWidget();
	void Message(bool isFind);

private:
	Ui::SearchMasterListWindow *ui;
	int itemNum;
	QString text0;
	QString text1;
	QString text2;
	QString text3;
	QString text4;
	ItemType tempItem;

protected:
	Application* app;
	DisplayStorageTempWindow* displayStoConWin;

private slots:
	void search();
	void move();
};
