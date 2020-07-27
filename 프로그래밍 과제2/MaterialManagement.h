#pragma once
#include <QMainWindow>
#include "ui_MaterialManagement.h"
#include "Application.h"
#include "AddItemWindow.h"
#include "DeleteItemWindow.h"
#include "UpdateItemWindow.h"
#include "SearchItemWindow.h"
#include "DisplayWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MaterialManagement; }
QT_END_NAMESPACE

// main화면
class MaterialManagement : public QMainWindow
{
    Q_OBJECT

public:
    MaterialManagement(QWidget* parent = Q_NULLPTR);

private:
    Ui::MaterialManagementClass* ui;

protected:
    Application* app; 
    AddItemWindow* addItemWindow; // AddItemWindow로 전환하기 위한 pointer
    DeleteItemWindow* deleteItemWindow; // DeleteItemWindow로 전환하기 위한 pointer 
    UpdateItemWindow* updateItemWindow; // UpdateItemWindow로 전환하기 위한 pointer
    SearchItemWindow* searchItemWindow; // SearchItemWindow로 전환하기 위한 pointer
    DisplayWindow* displayWindow; // DisplayWindow로 전환하기 위한 pointer

private slots:
    /*
    *	@brief	AddItem UI로 전환
    *	@pre	UI와 메소드 연결
    *	@post	AddItem UI로 전환
    */
    void MainAddItemButton(); // AddItemWindow로 전환하기 위한 button

    /*
    *	@brief	DeleteItem UI로 전환
    *	@pre	UI와 메소드 연결
    *	@post	DeleteItem UI로 전환
    */
    void MainDeleteItemButton(); // DeleteItemWindow로 전환하기 위한 button

    /*
    *	@brief	UpdateItem UI로 전환
    *	@pre	UI와 메소드 연결
    *	@brief	UpdateItem UI로 전환
    */
    void MainUpdateItemButton(); // UpdateItemWindow로 전환하기 위한 button

    /*
    *	@brief	SearchItem UI로 전환
    *	@pre	UI와 메소드 연결
    *	@brief	SearchItem UI로 전환
    */
    void MainSearchItemButton(); // SearchItemWindow로 전환하기 위한 button

    /*
    *	@brief	Display UI로 전환
    *	@pre	UI와 메소드 연결
    *	@brief	Display UI로 전환
    */
    void MainDisplayButton(); // DisplayWindow로 전환하기 위한 button
};