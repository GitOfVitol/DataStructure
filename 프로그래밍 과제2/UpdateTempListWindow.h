#pragma once

#include <QDialog>
#include "ui_UpdateTempListWindow.h"
#include "Application.h"
#include "SearchTempListWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UpdateTempListWindow; }
QT_END_NAMESPACE

class UpdateTempListWindow : public QDialog
{
	Q_OBJECT

public:
	UpdateTempListWindow(Application*, QWidget *parent = Q_NULLPTR);
	~UpdateTempListWindow();

private:
	Ui::UpdateTempListWindow* ui;

protected:
	Application* app;
	SearchTempListWindow* searchTempWin;

private slots:
	void exit();
	void view();
	void updateItem();
	void clear();
};
