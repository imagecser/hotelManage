#include "orderui.h"
#include "ui_orderui.h"

Orderui::Orderui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Orderui)
{
    ui->setupUi(this);
}

Orderui::~Orderui()
{
    delete ui;
}
