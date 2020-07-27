#pragma once

#include <QDialog>
#include "ui_AddTempToMaster1stItemWindow.h"
#include "Application.h"
#include "DisplayStorageTempWindow.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class AddTempToMaster1stItemWindow; }
QT_END_NAMESPACE

class AddTempToMaster1stItemWindow : public QDialog
{
	Q_OBJECT

public:
	/*
		default constructor
	*/
	AddTempToMaster1stItemWindow(Application*, QWidget *parent = Q_NULLPTR);
	/*
		destructor
	*/
	~AddTempToMaster1stItemWindow();

private:
	Ui::AddTempToMaster1stItemWindow *ui;

protected:
	Application* app;
	DisplayStorageTempWindow* displayStoConWin;

private slots:
	void view();
	void addToMaster();
};
