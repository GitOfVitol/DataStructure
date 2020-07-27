#pragma once

#include <QDialog>
#include "ui_DisplayTempListWindow.h"
#include "Application.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayTempListWindow; }
QT_END_NAMESPACE

class DisplayTempListWindow : public QDialog
{
	Q_OBJECT

public:
	DisplayTempListWindow(Application*, QWidget *parent = Q_NULLPTR);
	~DisplayTempListWindow();

private:
	Ui::DisplayTempListWindow *ui;
	int itemNum;

protected:
	Application* app;
};
