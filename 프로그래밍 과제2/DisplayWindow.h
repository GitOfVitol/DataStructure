#pragma once

#include <QDialog>
#include "ui_DisplayWindow.h"
#include "Application.h"
#include "DisplayMasterListWindow.h"
#include "DisplayTempListWindow.h"
#include "DisplayStorageTempWindow.h"
#include "DisplayStoSimItemWindow.h"
#include "DisplayStoDetailItemWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayWindow; }
QT_END_NAMESPACE

class DisplayWindow : public QDialog
{
	Q_OBJECT

public:
	DisplayWindow(Application*, QWidget *parent = Q_NULLPTR);
	~DisplayWindow();

private:
	Ui::DisplayWindow* ui;

protected:
	Application* app;
	DisplayMasterListWindow* displayMaster;
	DisplayTempListWindow* displayTemp;
	DisplayStorageTempWindow* displayStoConWin;
	DisplayStoSimItemWindow* displayStoSimWin;
	DisplayStoDetailItemWindow* displayStoDetailWin;

private slots:
	void displayMasterList();
	void displayTempList();
	void displayStoCon();
	void displayStoSimple();
	void displayStoDetail();
};
