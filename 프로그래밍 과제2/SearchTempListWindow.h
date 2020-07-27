#pragma once

#include <QDialog>
#include "ui_SearchTempListWindow.h"
#include "Application.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SearchTempListWindow; }
QT_END_NAMESPACE

class SearchTempListWindow : public QDialog
{
	Q_OBJECT

public:
	SearchTempListWindow(Application*, QWidget *parent = Q_NULLPTR);
	~SearchTempListWindow();
	void SetTableWidget();
	void Message(bool isFind);

private:
	Ui::SearchTempListWindow *ui;
	int itemNum;
	QString text0;
	QString text1;
	QString text2;
	QString text3;
	QString text4;
	ItemType tempItem;

protected:
	Application* app;

private slots:
	void search();
};