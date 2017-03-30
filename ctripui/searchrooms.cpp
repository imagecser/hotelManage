#include "searchrooms.h"
#include "ui_searchrooms.h"

SearchRooms::SearchRooms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchRooms)
{
    ui->setupUi(this);
    buildTable();
}

SearchRooms::~SearchRooms()
{
    delete ui;
}

void SearchRooms::buildTable(){
    auto *table = ui->tableWidget;
    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setHighlightSections(false);
    table->horizontalHeader()->setStretchLastSection(true);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);//编辑
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

void SearchRooms::showGrid(){
    auto *table = ui->tableWidget;
    int i = uRow;
    string name = vhotels[i].name;
    ui->tableWidget->clear();
    QStringList header;
    table->setColumnCount(4);
    table->setRowCount((int)vrooms[i].size() - 1);
    header << "name" << "key" << "price" << "type";
    table->setHorizontalHeaderLabels(header);

}
