#include "mainwindow.h"
#include <QtWidgets\qscrollbar.h>
#include <QtCore\qfile.h>
#include <../code/labfile.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    //setFixedSize(this->width(), this->height());
    ui->setupUi(this);
    buildTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buildTable(){
    auto *table = ui->tableWidget;
    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setHighlightSections(false);
    table->horizontalHeader()->setStretchLastSection(true);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    //table->setEditTriggers(QAbstractItemView::NoEditTriggers);//编辑
    table->horizontalHeader()->setFixedHeight(35);
    QFont font("等线", 10, 20);
    table->setFont(font);
    table->setStyleSheet(
                //"color:grey;"
                //"selection-background-color:lightblue;"
                "selection-background-color:rgb(34, 175, 75);"
                );
    table->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
                                                "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
                                                "QScrollBar::handle:hover{background:gray;}"
                                                "QScrollBar::sub-line{background:transparent;}"
                                                "QScrollBar::add-line{background:transparent;}");
    table->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
                                              "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
                                              "QScrollBar::handle:hover{background:gray;}"
                                              "QScrollBar::sub-line{background:transparent;}"
                                              "QScrollBar::add-line{background:transparent;}");
    showGrid();
}

void MainWindow::getItemChanged(QTableWidgetItem *item){
    int j = item->column();
    int i = item->row();
    string str = item->text().toStdString();
    if(j == 0) {
        int index = atoi(str.c_str());
        bool isOk = true;
        for(int i = 0; i < vhotels.size(); ++i)
            if(vhotels[i].indexH == index)
                isOk = false;
        if(isOk == true)
            vhotels[i].indexH = index;
        else QMessageBox::about(NULL, "error", "index input error!");
    }
    else if(j == 1) vhotels[i].name = str;
    else if(j == 2) vhotels[i].city = str;
    else vhotels[i].area = str;
    ui->tableWidget->clear();
    showGrid();
}

void MainWindow::showGrid(){
    disconnect(ui->tableWidget, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(getItemChanged(QTableWidgetItem*)));
    sort(vhotels.begin(), vhotels.end(), lessHotel());
    sort(vrooms.begin(), vrooms.end(), lessRoom());
    auto *table = ui->tableWidget;
    QStringList header;
    table->setColumnCount(4);
    table->setRowCount((int)vhotels.size());
    header << "index" << "name" << "city" << "area";
    table->setHorizontalHeaderLabels(header);
    for(int i = 0; i < vhotels.size(); ++i){
        stringstream ss;
        string s;
        ss << setfill('0') << setw(4) << vhotels[i].indexH;
        ss >> s;
        table->setItem(i, 0,new QTableWidgetItem(QString::fromStdString(s)));
        table->setItem(i, 1,new QTableWidgetItem(QString::fromStdString(vhotels[i].name)));
        table->setItem(i, 2,new QTableWidgetItem(QString::fromStdString(vhotels[i].city)));
        table->setItem(i, 3,new QTableWidgetItem(QString::fromStdString(vhotels[i].area)));
        for(int j = 0; j < 4; ++j) table->item(i,j)->setTextAlignment(Qt::AlignCenter);
    }
    table->resizeColumnToContents(1);
    connect(table, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(getItemChanged(QTableWidgetItem*)));
}
