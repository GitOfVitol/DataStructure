#pragma once

#include <QDialog>
#include "ui_AddMasterToTempWin.h"
#include "Application.h"
#include "DisplayMasterListWindow.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class AddMasterToTempWin; }
QT_END_NAMESPACE

class AddMasterToTempWin : public QDialog
{
	Q_OBJECT

public:
	/*
		default constructor
    */
	AddMasterToTempWin(Application*, QWidget *parent = Q_NULLPTR);

	/*
		destructor
	*/
	~AddMasterToTempWin();

private:
	Ui::AddMasterToTempWin *ui;

protected:
	Application* app;
	DisplayMasterListWindow* displayMasterListWindow;

private slots:
	void addMasterToTemp();
	void displayMasterList();
};
