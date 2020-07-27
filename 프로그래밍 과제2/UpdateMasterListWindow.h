#pragma once

#include <QDialog>
#include "ui_UpdateMasterListWindow.h"
#include "Application.h"
#include "SearchMasterListWindow.h"
#include "AddStorageContainerWindow.h"
#include "DisplayStorageTempWindow.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class UpdateMasterListWindow; }
QT_END_NAMESPACE

class UpdateMasterListWindow : public QDialog
{
	Q_OBJECT

public:
	UpdateMasterListWindow(Application*, QWidget *parent = Q_NULLPTR);
	~UpdateMasterListWindow();

private:
	Ui::UpdateMasterListWindow *ui;

protected:
	Application* app;
	SearchMasterListWindow* searchMasterWin;
	AddStorageContainerWindow* addStorageContainerWindow;
	DisplayStorageTempWindow* displayStorageTempWindow;

private slots:
	void view();
	void viewStoCon();
	void addStoCon();
	void exit();
	void updateItem();
	void clear();
};
