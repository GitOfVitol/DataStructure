#pragma once

#include <QDialog>
#include "ui_DisplayStoDetailItemWindow.h"
#include "Application.h"
#include <qmessagebox.h>
#include "DisplayStorageTempWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayStoDetailItemWindow; }
QT_END_NAMESPACE

class DisplayStoDetailItemWindow : public QDialog
{
	Q_OBJECT

public:
	DisplayStoDetailItemWindow(Application*, QWidget *parent = Q_NULLPTR);
	~DisplayStoDetailItemWindow();
	void SetTableWidget();
	void Message(bool isFind);

private:
	Ui::DisplayStoDetailItemWindow *ui;
	int itemNum;
	ItemType tempItem;

protected:
	Application* app;
	DisplayStorageTempWindow* displayStoConWin;

private slots:
	void setContainerCombo();
	void display();
	void move();
};