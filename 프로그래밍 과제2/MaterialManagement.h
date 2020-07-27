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

// mainȭ��
class MaterialManagement : public QMainWindow
{
    Q_OBJECT

public:
    MaterialManagement(QWidget* parent = Q_NULLPTR);

private:
    Ui::MaterialManagementClass* ui;

protected:
    Application* app; 
    AddItemWindow* addItemWindow; // AddItemWindow�� ��ȯ�ϱ� ���� pointer
    DeleteItemWindow* deleteItemWindow; // DeleteItemWindow�� ��ȯ�ϱ� ���� pointer 
    UpdateItemWindow* updateItemWindow; // UpdateItemWindow�� ��ȯ�ϱ� ���� pointer
    SearchItemWindow* searchItemWindow; // SearchItemWindow�� ��ȯ�ϱ� ���� pointer
    DisplayWindow* displayWindow; // DisplayWindow�� ��ȯ�ϱ� ���� pointer

private slots:
    /*
    *	@brief	AddItem UI�� ��ȯ
    *	@pre	UI�� �޼ҵ� ����
    *	@post	AddItem UI�� ��ȯ
    */
    void MainAddItemButton(); // AddItemWindow�� ��ȯ�ϱ� ���� button

    /*
    *	@brief	DeleteItem UI�� ��ȯ
    *	@pre	UI�� �޼ҵ� ����
    *	@post	DeleteItem UI�� ��ȯ
    */
    void MainDeleteItemButton(); // DeleteItemWindow�� ��ȯ�ϱ� ���� button

    /*
    *	@brief	UpdateItem UI�� ��ȯ
    *	@pre	UI�� �޼ҵ� ����
    *	@brief	UpdateItem UI�� ��ȯ
    */
    void MainUpdateItemButton(); // UpdateItemWindow�� ��ȯ�ϱ� ���� button

    /*
    *	@brief	SearchItem UI�� ��ȯ
    *	@pre	UI�� �޼ҵ� ����
    *	@brief	SearchItem UI�� ��ȯ
    */
    void MainSearchItemButton(); // SearchItemWindow�� ��ȯ�ϱ� ���� button

    /*
    *	@brief	Display UI�� ��ȯ
    *	@pre	UI�� �޼ҵ� ����
    *	@brief	Display UI�� ��ȯ
    */
    void MainDisplayButton(); // DisplayWindow�� ��ȯ�ϱ� ���� button
};