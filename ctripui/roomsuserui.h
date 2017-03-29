#ifndef ROOMSUSERUI_H
#define ROOMSUSERUI_H

#include <QDialog>
#include "../code/chotel.h"
#include "../code/labfile.h"
#include "../code/hotelmanage.h"
#include <QtWidgets\qscrollbar.h>
#include <QtCore\qfile.h>
#include "ui_roomsuserui.h"
#include "ordering.h"

namespace Ui {
class RoomsUserui;
}

class RoomsUserui : public QDialog
{
    Q_OBJECT

public:
    explicit RoomsUserui(QWidget *parent = 0);
    void buildTable();
    void showGrid();
    ~RoomsUserui();

private:
    Ui::RoomsUserui *ui;
private slots:
    void orderRoom(QTableWidgetItem *item);
};

#endif // ROOMSUSERUI_H
