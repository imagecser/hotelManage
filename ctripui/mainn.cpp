#include "Mainn.h"
#include "roomui.h"
#include "orderui.h"
#include "ui_Mainn.h"

Mainn::Mainn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mainn)
{
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    //setFixedSize(this->width(), this->height());
    ui->setupUi(this);
    Roomui *r = new Roomui;
    //connect(ui->indexEdit, SIGNAL(textChanged(QString)), this, );
    //tconnect(ui->roomBtn, SIGNAL(pressed()), r, SLOT(changeBtn()));
    buildTable();
}

Mainn::~Mainn()
{
    delete ui;
}

void Mainn::buildTable(){
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
    table->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(table, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ShowContextMenu(QPoint)));
    connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->orderBtn,SIGNAL(clicked()), this, SLOT(viewOrders()));
}

void Mainn::getItemChanged(QTableWidgetItem *item){
    int j = item->column();
    int i = item->row();
    string str = item->text().toStdString();
    if(m.ediHotel(i, j, str) == false)
        QMessageBox::about(NULL, "error", "index input error!");
    ui->tableWidget->clear();
    showGrid();
}

void Mainn::showGrid(){
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
        ss << setfill('0') << setw(4) << vhotels[i].indexH;
        table->setItem(i, 0,new QTableWidgetItem(QString::fromStdString(ss.str())));
        table->setItem(i, 1,new QTableWidgetItem(QString::fromStdString(vhotels[i].name)));
        table->setItem(i, 2,new QTableWidgetItem(QString::fromStdString(vhotels[i].city)));
        table->setItem(i, 3,new QTableWidgetItem(QString::fromStdString(vhotels[i].area)));
        for(int j = 0; j < 4; ++j) table->item(i,j)->setTextAlignment(Qt::AlignCenter);
        ss.clear();
    }
    table->resizeColumnToContents(1);
    connect(table, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(getItemChanged(QTableWidgetItem*)));
}

void Mainn::ShowContextMenu(const QPoint& pos){
    QPoint gloPos = ui->tableWidget->viewport()->mapToGlobal(pos);
    QMenu *myMenu = new QMenu;
    myMenu->addAction(QIcon(), QString("view"), this ,SLOT(viewRooms()));
    myMenu->addAction(QIcon(), QString("add"), this, SLOT(addRow()));
    myMenu->addAction(QIcon(), QString("delete"), this, SLOT(deleteRow()));
    myMenu->exec(gloPos);
}

void Mainn::deleteRow(){
    int i = ui->tableWidget->currentRow();
    if(m.delHotel(i) == true)
        ui->tableWidget->removeRow(i);
    else QMessageBox::about(NULL, "error", "delete operation error!");
}

void Mainn::addRow(){
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    m.addHotel();
    stringstream ss;
    string s("INFO INPUT");
    ss << setfill('0') << setw(4) << vhotels[vhotels.size() - 1].indexH;
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(ss.str())));
    ss.clear();
    for(int m = 1; m < 4; ++m)
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, m, new QTableWidgetItem(QString::fromStdString(s)));
}

void Mainn::viewRooms(){
    iRow = ui->tableWidget->currentRow();
    Roomui r;
    r.exec();
    /*disconnect(ui->tableWidget, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(getItemChanged(QTableWidgetItem*)));
    auto *table = ui->tableWidget;
    int i = table->currentRow();
    string name = vhotels[i].name;
    ui->tableWidget->clear();
    QStringList header;
    table->setColumnCount(4);
    table->setRowCount((int)vrooms[i].size() - 1);
    header << "name" << "key" << "price" << "type";
    table->setHorizontalHeaderLabels(header);
    for(int j = 1; j < vrooms[i].size(); ++j){
        table->setItem(j - 1, 0,new QTableWidgetItem(QString::fromStdString(name)));
        stringstream ss; string s;
        ss << vrooms[i][j].numR;
        ss >> s;
        table->setItem(j - 1, 1,new QTableWidgetItem(QString::fromStdString(s)));
        ss.clear();
        ss << vrooms[i][j].price;
        ss >> s;
        table->setItem(j - 1, 2,new QTableWidgetItem(QString::fromStdString(s))); ss.clear();
    }*/
}

void Mainn::viewOrders(){
    Orderui o;
    o.exec();
}
