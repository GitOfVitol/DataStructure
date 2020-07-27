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
	*	@brief	매인메뉴로 이동
	*	@pre	UI와 메소드 연결
	*	@post	홈화면으로 전환
	*/
	void exit();

	/*
	*	@brief	AddToMasterWindow로 이동
	*	@pre	UI와 메소드 연결, 해당 window 존재
	*	@post	AddToMasterWindow로 전환
	*/
	void AddItemButton1();

	/*
	*	@brief	AddToTempWindow로 이동
	*	@pre	UI와 메소드 연결, 해당 window 존재
	*	@post	AddToTempWindow로 전환
	*/
	void AddItemButton2();

	/*
	*	@brief	AddMasterToTempWin로 이동
	*	@pre	UI와 메소드 연결, 해당 window 존재
	*	@post	AddMasterToTempWin로 전환
	*/
	void AddItemButton3();

	/*
	*	@brief	AddTempToMaster1stItemWindow로 이동
	*	@pre	UI와 메소드 연결, 해당 window 존재
	*	@post	AddTempToMaster1stItemWindow로 전환
	*/
	void AddItemButton4();

	/*
	*	@brief	AddTempToMasterWindow로 이동
	*	@pre	UI와 메소드 연결, 해당 window 존재
	*	@post	AddTempToMasterWindow로 전환
	*/
	void AddItemButton5();

protected:
	Application* app; // main 동작, List 관리
	AddToMasterWindow* addToMasterWindow; // AddToMasterWindow
	AddToTempWindow* addToTempWindow; //AddToTempWindow
	AddMasterToTempWin* addMasterToTempWin; //AddMasterToTempWin
	AddTempToMaster1stItemWindow* addTempToMaster1stItemWin;  // AddTempToMaster1stItemWindow
	AddTempToMasterWindow* addTempToMasterWin; //AddTempToMasterWindow
};
