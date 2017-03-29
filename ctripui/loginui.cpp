#include "loginui.h"
#include "ui_loginui.h"

loginui::loginui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginui)
{
    ui->setupUi(this);
    connect(ui->adminTemp, SIGNAL(clicked()), this, SLOT(adminTemp()));
    connect(ui->userTemp, SIGNAL(clicked()), this, SLOT(userTemp()));
}

loginui::~loginui()
{
    delete ui;
}

void loginui::on_loginBtn_clicked()
{

}

void loginui::adminTemp(){
    this->close();
    Mainn m;
    m.exec();
}

void loginui::userTemp(){
    this->close();
    Userui u;
    u.exec();
}
