#pragma once

#include <QDialog>
#include "ui_DeleteItemWindow.h"
#include "Application.h"
#include "DeleteMasterListWindow.h"
#include "DeleteTempListWindow.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class DeleteItemWindow; }
QT_END_NAMESPACE

class DeleteItemWindow : public QDialog
{
	Q_OBJECT

public:
	DeleteItemWindow(Application* app, QWidget *parent = Q_NULLPTR);
	~DeleteItemWindow();

private:
	Ui::DeleteItemWindow *ui;

protected:
	Application* app;
	DeleteMasterListWindow* deleteMasterListWin;
	DeleteTempListWindow* deleteTempListWin;

private slots:
	void deleteMasterList();
	void delete1stTempList();
	void deleteTempList();
	void makeEmptyMaster();
};
