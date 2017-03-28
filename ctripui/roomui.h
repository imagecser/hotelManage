#ifndef ROOMUI_H
#define ROOMUI_H

#include <QDialog>
#include <../code/hotelmanage.h>
#include "../code/labfile.h"
#include "../code/chotel.h"
#include <QMessageBox>
#include <QtWidgets\qscrollbar.h>
#include <QtCore\qfile.h>
#include <QtWidgets\qmainwindow.h>
#include "ui_roomui.h"
#include <QMenu>

namespace Ui {
class Roomui;
}

class Roomui : public QDialog
{
    Q_OBJECT

public:
    explicit Roomui(QWidget *parent = 0);
    void buildTable();
    void showGrid();
    ~Roomui();
    ManageInfo m;

private:
    Ui::Roomui *ui;
private slots:
    void getItemChanged(QTableWidgetItem *item);
    void ShowContextMenu(const QPoint& pos);
    void deleteRow();
    void addRow();
};

#endif // ROOMUI_H
