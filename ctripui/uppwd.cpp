#include "uppwd.h"
#include "ui_uppwd.h"

Uppwd::Uppwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Uppwd)
{
    ui->setupUi(this);
}

Uppwd::~Uppwd()
{
    delete ui;
}
