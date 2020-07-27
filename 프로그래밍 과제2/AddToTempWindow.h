#pragma once

#include <QDialog>
#include "ui_AddToTempWindow.h"
#include "Application.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class AddToTempWindow; }
QT_END_NAMESPACE

class AddToTempWindow : public QDialog
{
	Q_OBJECT

public:
	AddToTempWindow(Application*, QWidget *parent = Q_NULLPTR);
	~AddToTempWindow();

private:
	Ui::AddToTempWindow *ui;

protected:
	Application* app;

private slots:
	void addTempItem();
	void clear();
};
