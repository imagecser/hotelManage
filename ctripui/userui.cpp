#include "userui.h"
#include "roomsuserui.h"
#include "loginui.h"

Userui::Userui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userui)
{
    this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    this->setFixedSize(680, 430);
    buildTable();
    this->setTabOrder(ui->searchBtn, ui->orderBtn);
    ui->label->setText(QString::fromStdString("username: " + username));
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(viewRooms(QTableWidgetItem*)));
    connect(ui->orderBtn, SIGNAL(clicked()), this, SLOT(viewOrders()));
    connect(ui->searchBtn, SIGNAL(clicked()), this, SLOT(search()));
    connect(ui->returnBtn, SIGNAL(clicked()), this, SLOT(returnsg()));
    connect(ui->label, SIGNAL(clicked()), this, SLOT(changepwd()));
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
    //sort(vhotels.begin(), vhotels.end(), lessHotel());
    //sort(vrooms.begin(), vrooms.end(), lessRoom());
    sortHotel();
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

void Userui::search(){
    keyword = ui->lineEdit->text().toStdString();
    if(keyword.size() != 0){
        SearchRooms sr;
        sr.exec();
    }
    else
        QMessageBox::warning(NULL, "error", "Keyword input error!", QMessageBox::Ok|QMessageBox::Ok, QMessageBox::Ok);
}

void Userui::returnsg(){
    this->close();
    loginui l;
    l.exec();
}

void Userui::changepwd(){
    Uppwd up;
    up.exec();
}
