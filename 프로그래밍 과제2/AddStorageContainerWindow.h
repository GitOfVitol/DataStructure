#pragma once

#include <QDialog>
#include "ui_AddStorageContainerWindow.h"
#include "Application.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class AddStorageContainerWindow; }
QT_END_NAMESPACE

class AddStorageContainerWindow : public QDialog
{
	Q_OBJECT

public:
	/*
		default constructor
	*/
	AddStorageContainerWindow(Application*, QWidget* parent = Q_NULLPTR);
	/*
		destructor
	*/
	~AddStorageContainerWindow();

private:
	Ui::AddStorageContainerWindow* ui;
	Application* app;

private slots:
	void addStorageContainer();
	void clear();
};
