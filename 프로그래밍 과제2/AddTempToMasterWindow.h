#pragma once

#include <QDialog>
#include "ui_AddTempToMasterWindow.h"
#include "Application.h"
#include "DisplayTempListWindow.h"
#include "DisplayStorageTempWindow.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class AddTempToMasterWindow; }
QT_END_NAMESPACE

class AddTempToMasterWindow : public QDialog
{
	Q_OBJECT

public:
	/*
		default constructor
	*/
	AddTempToMasterWindow(Application*, QWidget *parent = Q_NULLPTR);
	/*
		destructor
	*/
	~AddTempToMasterWindow();

private:
	Ui::AddTempToMasterWindow *ui;
	
protected:
	Application* app;
	DisplayTempListWindow* displayTempListWin;
	DisplayStorageTempWindow* displayStoConWin;

private slots:
	void viewStoCon();
	void viewTempList();
	void addToMaster();
};
