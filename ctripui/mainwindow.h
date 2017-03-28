#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../code/chotel.h"
#include "../code/labfile.h"
#include <QtWidgets\qmainwindow.h>
#include <ui_mainwindow.h>
#include <QMessageBox>
#include "../code/hotelmanage.h"
#include <QtWidgets\qscrollbar.h>
#include <QtCore\qfile.h>

extern int i;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ManageInfo m;
    explicit MainWindow(QWidget *parent = 0);
    void buildTable();
    void showGrid();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void getItemChanged(QTableWidgetItem *item);
    void ShowContextMenu(const QPoint& pos);
    void deleteRow();
    void addRow();
    void viewRooms();
    void save(){
        m.msave();
        QMessageBox::about(NULL, "saving...", "data saved!");
    }
};

#endif // MAINWINDOW_H

