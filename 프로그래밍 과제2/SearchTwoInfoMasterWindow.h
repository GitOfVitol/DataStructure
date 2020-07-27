#pragma once

#include <QDialog>
#include "ui_SearchTwoInfoMasterWindow.h"
#include "Application.h"
#include <qmessagebox.h>
#include "DisplayStorageTempWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SearchTwoInfoMasterWindow; }
QT_END_NAMESPACE

class SearchTwoInfoMasterWindow : public QDialog
{
	Q_OBJECT

public:
	SearchTwoInfoMasterWindow(Application*, QWidget *parent = Q_NULLPTR);
	~SearchTwoInfoMasterWindow();
	void SetTableWidget();
	void Message(bool isFind);

private:
	Ui::SearchTwoInfoMasterWindow* ui;
	int itemNum;
	QString text0;
	QString text1;
	QString text2;
	ItemType tempItem;

protected:
	Application* app;
	DisplayStorageTempWindow* displayStoConWin;

private slots:
	void search();
	void move();
};
