#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../code/chotel.h"
#include "../code/labfile.h"
#include <QtWidgets\qmainwindow.h>
#include <ui_mainwindow.h>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void buildTable();
    void showGrid();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void getItemChanged(QTableWidgetItem *item);
};

#endif // MAINWINDOW_H
