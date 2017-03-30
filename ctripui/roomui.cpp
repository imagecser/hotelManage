#include "roomui.h"


Roomui::Roomui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Roomui)
{
    ui->setupUi(this);
    this->setFixedSize(630, 470);
    itemp = iRow;
    iRow = getVecRow(iRow);
    buildTable();
}

Roomui::~Roomui()
{
    delete ui;
}

void Roomui::getItemChanged(QTableWidgetItem *item){
    int j = item->column();
    int i = item->row();
    string str = item->text().toStdString();
    if((m.ediRoom(i + 1, j, str)) == false)
        QMessageBox::about(NULL, "error", "number input error!");
    ui->tableWidget->clear();
    showGrid();
}

void Roomui::ShowContextMenu(const QPoint& pos){
    QPoint gloPos = ui->tableWidget->viewport()->mapToGlobal(pos);
    QMenu *myMenu = new QMenu;
    myMenu->addAction(QIcon(), QString("add"), this, SLOT(addRow()));
    myMenu->addAction(QIcon(), QString("delete"), this, SLOT(deleteRow()));
    myMenu->exec(gloPos);
}

void Roomui::deleteRow(){
    int i = ui->tableWidget->currentRow();
    if(i == -1) ++i;
    if(m.delRoom(i) == true && i > -1)
        ui->tableWidget->removeRow(i);
    else QMessageBox::about(NULL, "error", "delete operation error!");
}

void Roomui::addRow(){
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    m.addRoom();
    stringstream ss; string s;
    ss << vrooms[iRow][vrooms[iRow].size() - 1].numR;
    ss >> s;
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(s))); ss.clear();
    ss << vrooms[iRow][vrooms[iRow].size() - 1].price;
    ss >> s;
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(s))); ss.clear();
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem(QString("INFO INPUT")));
}

void Roomui::buildTable(){
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
}

void Roomui::showGrid(){
    auto *table = ui->tableWidget;
    disconnect(table, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(getItemChanged(QTableWidgetItem*)));
    int i = iRow;
    string name = vhotels[itemp].name;
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
    for(int i = 0; i < table->rowCount(); ++i) table->item(i, 0)->setFlags(Qt::NoItemFlags);
    connect(table, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(getItemChanged(QTableWidgetItem*)));
}


