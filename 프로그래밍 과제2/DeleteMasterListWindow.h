#pragma once

#include <QDialog>
#include "ui_DeleteMasterListWindow.h"
#include "Application.h"
#include "DisplayMasterListWindow.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class DeleteMasterListWindow; }
QT_END_NAMESPACE

class DeleteMasterListWindow : public QDialog
{
	Q_OBJECT

public:
	DeleteMasterListWindow(Application*, QWidget *parent = Q_NULLPTR);
	~DeleteMasterListWindow();

private:
	Ui::DeleteMasterListWindow *ui;

protected:
	Application* app;
	DisplayMasterListWindow* displayMasterListWin;

private slots:
	void viewMasterList();
	void deleteFromMaster();
};
