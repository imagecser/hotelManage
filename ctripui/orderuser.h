#ifndef ORDERUSER_H
#define ORDERUSER_H

#include <QDialog>
#include "ui_orderuser.h"
#include <QtWidgets\qscrollbar.h>
#include <QtCore\qfile.h>
#include "../code/chotel.h"
#include "../code/labfile.h"
#include <QMenu>
#include <QMessageBox>
#include "../code/hoteluser.h"

namespace Ui {
class OrderUser;
}

class OrderUser : public QDialog
{
    Q_OBJECT

public:
    explicit OrderUser(QWidget *parent = 0);
    ~OrderUser();
    void buildTable();
    void showGrid();

private:
    Ui::OrderUser *ui;
    UserInfo us;
private slots:
    void ShowContextMenu(const QPoint& pos);
    void del();
    void save(){
        UserInfo user;
        user.usave();
        QMessageBox::about(NULL, "saving...", "orders saved!");
    }
};

#endif // ORDERUSER_H
