#pragma once

#include <QDialog>
#include "ui_DisplayStoSimItemWindow.h"
#include "Application.h"
#include <qmessagebox.h>
#include "DisplayStorageTempWindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class DisplayStoSimItemWindow; }
QT_END_NAMESPACE

class DisplayStoSimItemWindow : public QDialog
{
	Q_OBJECT

public:
	DisplayStoSimItemWindow(Application*, QWidget *parent = Q_NULLPTR);
	~DisplayStoSimItemWindow();
	void SetTableWidget();
	void Message(bool isFind);

private:
	Ui::DisplayStoSimItemWindow* ui;
	SimpleItemType tempSimpleItem;
	int itemNum;

protected:
	Application* app;
	DisplayStorageTempWindow* displayStoConWin;

private slots:
	void setContainerCombo();
	void displaySimpleItem();
	void move();
};
