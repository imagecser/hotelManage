#include "ordering.h"
#include <QDebug>
#include <QMessageBox>
bool judgeIDcard(string str);

Ordering::Ordering(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ordering)
{
    ui->setupUi(this);
    connect(ui->acceptedBtn, SIGNAL(clicked()), this, SLOT(dataUpdate()));
    connect(ui->rejectedBtn, SIGNAL(clicked()), this, SLOT(quitW()));
}

Ordering::~Ordering()
{
    delete ui;
}

void Ordering::dataUpdate(){
    Order *od = new Order;
    od->date[0] = ui->beginDate->date().year();
    od->date[1] = ui->beginDate->date().month();
    od->date[2] = ui->beginDate->date().day();
    od->date[3] = ui->endDate->date().year();
    od->date[4] = ui->endDate->date().month();
    od->date[5] = ui->endDate->date().day();
    od->uname = ui->nameEdit->text().toStdString();
    od->idcard = ui->cardEdit->text().toStdString();
    od->orderIndex = vorders[vorders.size() - 1].orderIndex;
    od->ppr = uRow * 100 + uColumn;
    //od->proom = &vrooms[uRow][uColumn];
    int bbeg = od->date[0] * 10000 + od->date[1] * 100 + od->date[2];
    int bend = od->date[3] * 10000 + od->date[4] * 100 + od->date[5];
    if(bbeg > bend){
        QMessageBox::critical(NULL, "error", "date input error!", QMessageBox::Ok | QMessageBox::Ok, QMessageBox::Ok);
        delete od;
        return;
    }
    if(judgeIDcard(od->idcard) == false || od->uname.size() == 0){
            QMessageBox::critical(NULL, "error", "IDcard/name input error!", QMessageBox::Ok | QMessageBox::Ok, QMessageBox::Ok);
            delete od;
            return;
    }
    for(int i = 0; i < vorders.size(); ++i){
        //qDebug() << vorders[i].proom->numR << vrooms[uRow][uColumn].numR << mmap.find(vorders[i].proom)->second->indexH << vhotels[uRow].indexH;
        int m = vorders[i].ppr / 100, n = vorders[i].ppr % 100;
        if(vrooms[m][n].numR == vrooms[uRow][uColumn].numR )
        //if(vorders[i].proom->numR == vrooms[uRow][uColumn].numR )
            if(mmap.find(vorders[i].ppr)->second->indexH == vhotels[uRow].indexH){
            //if(mmap.find(vorders[i].proom)->second->indexH == vhotels[uRow].indexH){
                if(daterep(vorders[i].date, od->date) == true){
                    QMessageBox::critical(NULL, "error", "date ordered!", QMessageBox::Ok | QMessageBox::Ok, QMessageBox::Ok);
                    delete od;
                    return;
                }
            }
    }
    int m = od->ppr / 100, n = od->ppr % 100;
    vrooms[m][n].ordered = true;
    //od->proom->ordered = true;
    mmap.find(od->ppr)->second->ordered = true;
    //mmap.find(od->proom)->second->ordered = true;
    vorders.push_back(*od);
    QMessageBox::about(NULL, "ordered", "order accepted!");
    this->close();
}

void Ordering::quitW(){
    this->close();
}

bool judgeIDcard(string str){
    if (str.size() != 18) return false;
    for(int i = 0; i < 17; ++i){
        if(str[i] < '0' || str[i] > '9')
            return false;
    }
    if(str[17] != 'x' && str[17] != 'X' && (str[17] < '0' || str[17] > '9' )) return false;
    return true;
}
