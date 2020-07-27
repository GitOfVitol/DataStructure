#pragma once

#include <QDialog>
#include "ui_UpdateItemWindow.h"
#include "Application.h"
#include "UpdateMasterListWindow.h"
#include "UpdateTempListWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UpdateItemWindow; }
QT_END_NAMESPACE

class UpdateItemWindow : public QDialog
{
	Q_OBJECT

public:
	UpdateItemWindow(Application*, QWidget *parent = Q_NULLPTR);
	~UpdateItemWindow();

private:
	Ui::UpdateItemWindow *ui;

protected:
	Application* app;
	UpdateMasterListWindow* updateMasterWin;
	UpdateTempListWindow* updateTempWin;

private slots:
	void updateMaster();
	void updateTemp();
};
