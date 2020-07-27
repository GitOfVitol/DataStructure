#pragma once

#include <QDialog>
#include "ui_AddToMasterWindow.h"
#include "Application.h"
#include <qmessagebox.h>
#include "AddStorageContainerWindow.h"
#include "DisplayStorageTempWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddToMasterWindow; }
QT_END_NAMESPACE

class AddToMasterWindow : public QDialog
{
	Q_OBJECT

public:
	AddToMasterWindow(Application*, QWidget *parent = Q_NULLPTR);
	~AddToMasterWindow();

private:
	Ui::AddToMasterWindow* ui;

protected:
	Application* app;
	AddStorageContainerWindow* addStorageContainerWindow;
	DisplayStorageTempWindow* displayStorageTempWindow;

private slots:
	void addItem();
	void addStorageContainer();
	void view();
	void clear();
};
