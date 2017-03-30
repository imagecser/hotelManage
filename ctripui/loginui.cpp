#include "loginui.h"
#include "ui_loginui.h"
#include <QDate>

loginui::loginui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginui)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("img.ico"));
    this->setFixedSize(400, 300);
    this->setTabOrder(ui->usernameLine, ui->passwordLine);
    this->setTabOrder(ui->passwordLine, ui->userRadio);
    this->setTabOrder(ui->userRadio, ui->loginBtn);
    this->setTabOrder(ui->loginBtn, ui->exitBtn);
    ui->passwordLine->setEchoMode(QLineEdit::Password);
    connect(ui->loginBtn, SIGNAL(clicked()), this, SLOT(login()));
    connect(ui->exitBtn, SIGNAL(clicked()), this, SLOT(exit()));
}

loginui::~loginui()
{
    delete ui;
}


void loginui::login(){
    username = ui->usernameLine->text().toStdString();
    password = ui->passwordLine->text().toStdString();
    if(ui->adminRadio->isChecked() == true){
        if(sg.isAdmin() == true){
            Mainn m;
            this->close();
            m.exec();
        }
        else
            QMessageBox::warning(NULL, " ", "Incorrect username or password.", QMessageBox::Ok|QMessageBox::Ok, QMessageBox::Ok);
    }
    else{
        if(sg.isUser() == true){
            Userui us;
            this->close();
            us.exec();
        }
        else
            QMessageBox::about(NULL, " ", "Incorrect username or password.");
    }
}

void loginui::exit(){
    this->close();
}
