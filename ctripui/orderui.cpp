#include "orderui.h"

Orderui::Orderui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Orderui)
{
    ui->setupUi(this);
    buildTable();
}

Orderui::~Orderui()
{
    delete ui;
}

void Orderui::buildTable(){
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

void Orderui::showGrid(){
    sort(vorders.begin(), vorders.end(), lessOrder());
    auto *table = ui->tableWidget;
    QStringList header;
    table->setColumnCount(6);
    table->setRowCount((int)vorders.size());
    header << "index" << "city" << "name" << "area" <<"key" << "type";
    table->setHorizontalHeaderLabels(header);
    for(int i = 0; i < vorders.size();++i){
        stringstream ss; string s;
        ss << setfill('0') << setw(6) << vorders[i].orderIndex; ss >> s;
        table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(s))); ss.clear();
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(mmap.find(vorders[i].proom)->second->city)));
        table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(mmap.find(vorders[i].proom)->second->name)));
        table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(mmap.find(vorders[i].proom)->second->area)));
        ss << vorders[i].proom->numR; ss >> s;
        table->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(s))); ss.clear();
        table->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(vorders[i].proom->type)));
        for(int j = 0; j < 6; ++j) table->item(i, j)->setTextAlignment(Qt::AlignCenter);
    }
    for(int i = 0; i < table->rowCount(); ++i) table->item(i, 0)->setFlags(Qt::NoItemFlags);
    table->resizeColumnToContents(2);
}
