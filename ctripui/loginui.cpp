#include "loginui.h"
#include "ui_loginui.h"

loginui::loginui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginui)
{
    ui->setupUi(this);
}

loginui::~loginui()
{
    delete ui;
}

void loginui::on_loginBtn_clicked()
{

}
