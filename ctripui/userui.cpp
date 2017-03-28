#include "userui.h"
#include "ui_userui.h"

Userui::Userui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userui)
{
    ui->setupUi(this);
}

Userui::~Userui()
{
    delete ui;
}
