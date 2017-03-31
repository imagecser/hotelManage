#ifndef MAINN_H
#define MAINN_H


#include "../code/chotel.h"
#include "../code/labfile.h"
#include "ui_mainn.h"
#include <QMessageBox>
#include "../code/hotelmanage.h"
#include <QtWidgets\qscrollbar.h>
#include <QtCore\qfile.h>
#include <QDialog>

extern int i;
namespace Ui {
class Mainn;
}

class Mainn : public QDialog
{
    Q_OBJECT

public:
    ManageInfo m;
    explicit Mainn(QWidget *parent = 0);
    void buildTable();
    void showGrid();
    ~Mainn();

private:
    Ui::Mainn *ui;
private slots:
    void getItemChanged(QTableWidgetItem *item);
    void ShowContextMenu(const QPoint& pos);
    void returnsg();
    void deleteRow();
    void addRow();
    void viewRooms();
    void viewOrders();
    void save(){
        m.msave();
        QMessageBox::about(NULL, "saving...", "data saved!");
    }
};

#endif // MAINN_H
