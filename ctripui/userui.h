#ifndef USERUI_H
#define USERUI_H

#include <QDialog>
#include <QMessageBox>
#include "../code/hotelmanage.h"
#include <QtWidgets\qscrollbar.h>
#include <QtCore\qfile.h>
#include "ui_userui.h"
#include "../code/hoteluser.h"
#include "../code/chotel.h"
#include "orderuser.h"
#include "searchrooms.h"
#include "uppwd.h"

namespace Ui {
class Userui;
}

class Userui : public QDialog
{
    Q_OBJECT

public:
    explicit Userui(QWidget *parent = 0);
    void buildTable();
    void showGrid();
    ~Userui();

private:
    Ui::Userui *ui;
private slots:
    void viewRooms(QTableWidgetItem*);
    void viewOrders();
    void search();
    void returnsg();
    void changepwd();
};

#endif // USERUI_H
