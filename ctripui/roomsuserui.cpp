#include "roomsuserui.h"

RoomsUserui::RoomsUserui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoomsUserui)
{
    ui->setupUi(this);
    uRow = getVecRow(uRow);
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(orderRoom(QTableWidgetItem*)));
    buildTable();
}

RoomsUserui::~RoomsUserui()
{
    delete ui;
}

void RoomsUserui::buildTable(){
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

void RoomsUserui::showGrid(){
    auto *table = ui->tableWidget;
    int i = uRow;
    string name = vhotels[i].name;
    ui->tableWidget->clear();
    QStringList header;
    table->setColumnCount(4);
    table->setRowCount((int)vrooms[i].size() - 1);
    header << "name" << "key" << "price" << "type";
    table->setHorizontalHeaderLabels(header);
    for(int j = 1; j < vrooms[i].size(); ++j){
        table->setItem(j - 1, 0, new QTableWidgetItem(QString::fromStdString(name)));
        stringstream ss; string s;
        ss << vrooms[i][j].numR;
        ss >> s;
        table->setItem(j - 1, 1, new QTableWidgetItem(QString::fromStdString(s)));
        ss.clear();
        ss << vrooms[i][j].price;
        ss >> s;
        table->setItem(j - 1, 2, new QTableWidgetItem(QString::fromStdString(s))); ss.clear();
        table->setItem(j - 1, 3, new QTableWidgetItem(QString::fromStdString(vrooms[i][j].type)));
        for(int k = 0; k < 4; ++k) table->item(j - 1,k)->setTextAlignment(Qt::AlignCenter);
    }
    table->resizeColumnToContents(0);
}

void RoomsUserui::orderRoom(QTableWidgetItem *item){
    uColumn = item->row() + 1;
}
