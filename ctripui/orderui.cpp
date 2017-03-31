#include "orderui.h"

Orderui::Orderui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Orderui)
{
    this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    this->setFixedSize(1150, 440);
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
    table->setColumnCount(8);
    //table->setRowCount((int)vorders.size());
    header << "index" << "city" << "name" << "area" <<"key" << "type" << "time" << "user";
    table->setHorizontalHeaderLabels(header);
    for(int i = 0, k = 0; i < vorders.size();++i){
            table->setRowCount(table->rowCount() + 1);
            stringstream ss; string s;
            ss << setfill('0') << setw(6) << vorders[i].orderIndex; ss >> s;
            table->setItem(k, 0, new QTableWidgetItem(QString::fromStdString(s))); ss.clear();
            table->setItem(k, 1, new QTableWidgetItem(QString::fromStdString(mmap.find(vorders[i].ppr)->second->city)));
            table->setItem(k, 2, new QTableWidgetItem(QString::fromStdString(mmap.find(vorders[i].ppr)->second->name)));
            table->setItem(k, 3, new QTableWidgetItem(QString::fromStdString(mmap.find(vorders[i].ppr)->second->area)));
            //table->setItem(k, 1, new QTableWidgetItem(QString::fromStdString(mmap.find(vorders[i].proom)->second->city)));
            //table->setItem(k, 2, new QTableWidgetItem(QString::fromStdString(mmap.find(vorders[i].proom)->second->name)));
            //table->setItem(k, 3, new QTableWidgetItem(QString::fromStdString(mmap.find(vorders[i].proom)->second->area)));
            int m = vorders[i].ppr / 1000, n = vorders[i].ppr % 1000;
            ss << vrooms[m][n].numR; ss >> s;
            //ss << vorders[i].proom->numR; ss >> s;
            table->setItem(k, 4, new QTableWidgetItem(QString::fromStdString(s))); ss.clear();
            table->setItem(k, 5, new QTableWidgetItem(QString::fromStdString(vrooms[m][n].type)));
            ss << vorders[i].date[0] << "-" << vorders[i].date[1] << "-" << vorders[i].date[2] << "..." <<vorders[i].date[3] << "-" << vorders[i].date[4] << "-" << vorders[i].date[5];
            ss >> s;
            table->setItem(k, 6, new QTableWidgetItem(QString::fromStdString(s))); ss.clear();
            table->setItem(k, 7, new QTableWidgetItem(QString::fromStdString(vorders[i].user)));
            //table->setItem(k, 5, new QTableWidgetItem(QString::fromStdString(vorders[i].proom->type)));
            for(int j = 0; j < 8; ++j) table->item(k, j)->setTextAlignment(Qt::AlignCenter);
            ++k;
    }
    //for(int i = 0; i < table->rowCount(); ++i) table->item(i, 0)->setFlags(Qt::NoItemFlags);
    table->resizeColumnToContents(2);
    table->resizeColumnToContents(6);
}
