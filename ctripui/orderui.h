#ifndef ORDERUI_H
#define ORDERUI_H

#include <QDialog>
#include "ui_orderui.h"
#include <QtWidgets\qscrollbar.h>
#include <QtCore\qfile.h>
#include "../code/chotel.h"
#include "../code/labfile.h"

namespace Ui {
class Orderui;
}

class Orderui : public QDialog
{
    Q_OBJECT

public:
    explicit Orderui(QWidget *parent = 0);
    void buildTable();
    void showGrid();
    ~Orderui();

private:
    Ui::Orderui *ui;
};

#endif // ORDERUI_H
