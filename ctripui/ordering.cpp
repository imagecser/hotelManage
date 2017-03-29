#include "ordering.h"
#include <QDebug>

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
    dateo[0] = ui->beginDate->date().year();
    dateo[1] = ui->beginDate->date().month();
    dateo[2] = ui->beginDate->date().day();
    dateo[3] = ui->endDate->date().year();
    dateo[4] = ui->endDate->date().month();
    dateo[5] = ui->endDate->date().day();
    unameo = ui->nameEdit->text().toStdString();
    idcardo = ui->cardEdit->text().toStdString();
}

void Ordering::quitW(){
    this->close();
}
