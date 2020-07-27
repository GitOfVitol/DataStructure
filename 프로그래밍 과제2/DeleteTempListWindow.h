#pragma once

#include <QDialog>
#include "ui_DeleteTempListWindow.h"
#include "Application.h"
#include "DisplayTempListWindow.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class DeleteTempListWindow; }
QT_END_NAMESPACE

class DeleteTempListWindow : public QDialog
{
	Q_OBJECT

public:
	DeleteTempListWindow(Application*, QWidget *parent = Q_NULLPTR);
	~DeleteTempListWindow();

private:
	Ui::DeleteTempListWindow *ui;

protected:
	Application* app;
	DisplayTempListWindow* displayTempListWin;

private slots:
	void viewTempList();
	void deleteTempList();
};
