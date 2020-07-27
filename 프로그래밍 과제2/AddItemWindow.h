#pragma once

#include <QDialog>
#include "ui_AddItemWindow.h"
#include "Application.h"
#include "AddToMasterWindow.h"
#include "AddToTempWindow.h"
#include "AddMasterToTempWin.h"
#include "AddTempToMaster1stItemWindow.h"
#include "AddTempToMasterWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddItemWindow; }
QT_END_NAMESPACE

class AddItemWindow : public QDialog
{
	Q_OBJECT

public:
	/*
		default constructor
	*/
	AddItemWindow(Application*, QWidget *parent = Q_NULLPTR);

	/*
		destructor
	*/
	~AddItemWindow();

private:
	Ui::AddItemWindow *ui;

private slots:
	/*
	*	@brief	���θ޴��� �̵�
	*	@pre	UI�� �޼ҵ� ����
	*	@post	Ȩȭ������ ��ȯ
	*/
	void exit();

	/*
	*	@brief	AddToMasterWindow�� �̵�
	*	@pre	UI�� �޼ҵ� ����, �ش� window ����
	*	@post	AddToMasterWindow�� ��ȯ
	*/
	void AddItemButton1();

	/*
	*	@brief	AddToTempWindow�� �̵�
	*	@pre	UI�� �޼ҵ� ����, �ش� window ����
	*	@post	AddToTempWindow�� ��ȯ
	*/
	void AddItemButton2();

	/*
	*	@brief	AddMasterToTempWin�� �̵�
	*	@pre	UI�� �޼ҵ� ����, �ش� window ����
	*	@post	AddMasterToTempWin�� ��ȯ
	*/
	void AddItemButton3();

	/*
	*	@brief	AddTempToMaster1stItemWindow�� �̵�
	*	@pre	UI�� �޼ҵ� ����, �ش� window ����
	*	@post	AddTempToMaster1stItemWindow�� ��ȯ
	*/
	void AddItemButton4();

	/*
	*	@brief	AddTempToMasterWindow�� �̵�
	*	@pre	UI�� �޼ҵ� ����, �ش� window ����
	*	@post	AddTempToMasterWindow�� ��ȯ
	*/
	void AddItemButton5();

protected:
	Application* app; // main ����, List ����
	AddToMasterWindow* addToMasterWindow; // AddToMasterWindow
	AddToTempWindow* addToTempWindow; //AddToTempWindow
	AddMasterToTempWin* addMasterToTempWin; //AddMasterToTempWin
	AddTempToMaster1stItemWindow* addTempToMaster1stItemWin;  // AddTempToMaster1stItemWindow
	AddTempToMasterWindow* addTempToMasterWin; //AddTempToMasterWindow
};
