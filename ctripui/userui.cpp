#include "userui.h"
#include "roomsuserui.h"

Userui::Userui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userui)
{
    ui->setupUi(this);
    buildTable();
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(viewRooms(QTableWidgetItem*)));
    connect(ui->orderBtn, SIGNAL(clicked()), this, SLOT(viewOrders()));
}

Userui::~Userui()
{
    delete ui;
}

void Userui::buildTable(){
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

void Userui::showGrid(){
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
        ss << setfill('0') << setw(4) << vhotels[i].indexH;
        table->setItem(i, 0,new QTableWidgetItem(QString::fromStdString(ss.str())));
        table->setItem(i, 1,new QTableWidgetItem(QString::fromStdString(vhotels[i].name)));
        table->setItem(i, 2,new QTableWidgetItem(QString::fromStdString(vhotels[i].city)));
        table->setItem(i, 3,new QTableWidgetItem(QString::fromStdString(vhotels[i].area)));
        for(int j = 0; j < 4; ++j) table->item(i,j)->setTextAlignment(Qt::AlignCenter);
        ss.clear();
    }
    table->resizeColumnToContents(1);
}

void Userui::viewRooms(QTableWidgetItem* item){
    uRow = item->row();
    RoomsUserui ru;
    ru.exec();
}

void Userui::viewOrders(){
    OrderUser odu;
    odu.exec();
}
