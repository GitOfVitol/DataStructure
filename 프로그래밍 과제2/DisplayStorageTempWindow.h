#pragma once

#include <QDialog>
#include "ui_DisplayStorageTempWindow.h"
#include "Application.h"
#include <qpixmap.h>

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayStorageTempWindow; }
QT_END_NAMESPACE

class DisplayStorageTempWindow : public QDialog
{
	Q_OBJECT

public:
	DisplayStorageTempWindow(Application*, QWidget *parent = Q_NULLPTR);
	~DisplayStorageTempWindow();

private:
	Ui::DisplayStorageTempWindow *ui;
	int itemNum;

protected:
	Application* app;
};

class TableWidget : public QTableWidget
{
protected:
    QStyleOptionViewItem viewOptions() const
    {
        QStyleOptionViewItem opt = QTableWidget::viewOptions();
        opt.decorationPosition = QStyleOptionViewItem::Bottom;
        opt.decorationAlignment = Qt::AlignCenter;
        return opt;
    }
};