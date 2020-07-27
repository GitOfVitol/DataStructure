#pragma once

#include <QDialog>
#include "ui_SearchItemWindow.h"
#include "Application.h"
#include "SearchMasterListWindow.h"
#include "SearchTempListWindow.h"
#include "SearchTwoInfoMasterWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SearchItemWindow; }
QT_END_NAMESPACE

class SearchItemWindow : public QDialog
{
	Q_OBJECT

public:
	SearchItemWindow(Application*, QWidget *parent = Q_NULLPTR);
	~SearchItemWindow();

private:
	Ui::SearchItemWindow *ui;

protected:
	Application* app;
	SearchMasterListWindow* searchMasterWin;
	SearchTempListWindow* searchTempWin;
	SearchTwoInfoMasterWindow* searchTwoInfoMasterWin;

private slots:
	void searchMasterListButton();
	void searchTempListButton();
	void searchTwoInfoMaster();
};
