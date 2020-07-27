#pragma once

#include <QDialog>
#include "ui_DisplayMasterListWindow.h"
#include "Application.h"
#include <qpixmap.h>
#include "DisplayStorageTempWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayMasterListWindow; }
QT_END_NAMESPACE

class DisplayMasterListWindow : public QDialog
{
	Q_OBJECT

public:
	DisplayMasterListWindow(Application*, QWidget *parent = Q_NULLPTR);
	~DisplayMasterListWindow();

private:
	Ui::DisplayMasterListWindow *ui;
	int itemNum;

protected:
	Application* app;
	DisplayStorageTempWindow* displayStoConWin;

private slots:
	void move();
};
