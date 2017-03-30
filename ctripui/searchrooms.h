#ifndef SEARCHROOMS_H
#define SEARCHROOMS_H

#include <QDialog>
#include "ui_searchrooms.h"
#include "../code/chotel.h"
#include "../code/labfile.h"
#include <QScrollBar>
#include <QFile>
#include "ordering.h"

namespace Ui {
class SearchRooms;
}

class SearchRooms : public QDialog
{
    Q_OBJECT

public:
    explicit SearchRooms(QWidget *parent = 0);
    ~SearchRooms();
    void buildTable();
    void showGrid();

private:
    Ui::SearchRooms *ui;
};



#endif // SEARCHROOMS_H