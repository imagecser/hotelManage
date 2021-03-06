#include "searchrooms.h"
#include "ui_searchrooms.h"

string keyword;

struct Loc{
    int i;
    int j;
};


vector<Loc> vsearch;

SearchRooms::SearchRooms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchRooms)
{
    this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    this->setFixedSize(880, 460);
    qDebug() << QString::fromStdString(keyword);
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(orderRoom(QTableWidgetItem*)));
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
    table->clear();
    QStringList header;
    table->setColumnCount(6);
    header << "city" << "name" << "area" << "key" << "price" << "type";
    table->setHorizontalHeaderLabels(header);
    showData();
}

void SearchRooms::showData(){
    auto *table = ui->tableWidget;
    for(int i = 0; i < vrooms.size(); ++i){
        for(int j = 1; j < vrooms[i].size(); ++j){
            if(algo(i, j) == true){
                Loc *pl = new Loc;
                pl->i = i; pl->j = j;
                vsearch.push_back(*pl);
                //qDebug() << vsearch.size();
                table->insertRow(table->rowCount());
                int row = table->rowCount() - 1;
                table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(mmap.find(i * 1000 + j)->second->city)));
                stringstream ss; string s;
                table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(mmap.find(i * 1000 + j)->second->name)));
                table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(mmap.find(i * 1000 + j)->second->area)));
                ss << vrooms[i][j].numR; ss >> s;
                table->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(s))); ss.clear();
                ss << vrooms[i][j].price; ss >> s;
                table->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(s))); ss.clear();
                table->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(vrooms[i][j].type)));
                for(int k = 0; k < 6; ++k) table->item(row, k)->setTextAlignment(Qt::AlignCenter);
            }
            table->resizeColumnToContents(1);
        }
    }
}

bool SearchRooms::algo(int i, int j){
    if(mmap.find(i * 1000 + j)->second->city.find(keyword) != string::npos)
        return true;
    else if(mmap.find(i * 1000 + j)->second->name.find(keyword) != string::npos)
        return true;
    else if(mmap.find(i * 1000 + j)->second->area.find(keyword) != string::npos)
        return true;
    else if(vrooms[i][j].type.find(keyword) != string::npos)
        return true;
    else return false;
}

void SearchRooms::orderRoom(QTableWidgetItem *item){
    uRow = vsearch[item->row()].i;
    uColumn = vsearch[item->row()].j;
    Ordering od;
    od.exec();
}
