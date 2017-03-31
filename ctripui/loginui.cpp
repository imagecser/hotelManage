#include "loginui.h"
#include "ui_loginui.h"
#include <QDate>
#include <QMessageBox>

loginui::loginui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginui)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    this->setWindowIcon(QIcon("img.ico"));
    this->setFixedSize(400, 300);
    this->setTabOrder(ui->usernameLine, ui->passwordLine);
    this->setTabOrder(ui->passwordLine, ui->userRadio);
    this->setTabOrder(ui->userRadio, ui->loginBtn);
    this->setTabOrder(ui->loginBtn, ui->exitBtn);
    ui->passwordLine->setEchoMode(QLineEdit::Password);
    connect(ui->loginBtn, SIGNAL(clicked()), this, SLOT(login()));
    connect(ui->exitBtn, SIGNAL(clicked()), this, SLOT(exit()));
    connect(ui->forgotBtn, SIGNAL(clicked()), this, SLOT(forgot()));
    connect(ui->signupBtn, SIGNAL(clicked()), this, SLOT(signup()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(help()));
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

void loginui::forgot(){
    QMessageBox::about(NULL, "Forgot password?", QString::fromStdString("密码不知道还玩儿啥？卸载吧！"));
}

void loginui::signup(){
    username = ui->usernameLine->text().toStdString();
    password = ui->passwordLine->text().toStdString();
    if(username.size() == 0 || password.size() == 0)
        QMessageBox::warning(NULL, " ", "Incorrect username or password.", QMessageBox::Ok|QMessageBox::Ok, QMessageBox::Ok);
    else{
        for(int i = 0; i < vaccs.size(); ++i)
            if(QString::fromStdString(vaccs[i].username) == ui->usernameLine->text()){
                QMessageBox::warning(NULL, " ", "Username signed up!", QMessageBox::Ok|QMessageBox::Ok, QMessageBox::Ok);
                return;
            }
        Upsw *up = new Upsw;
        up->password = password;
        up->username = username;
        vaccs.push_back(*up);
        f.pswsave();
        QMessageBox::about(NULL, "signed up!", ("Your account information:\n \tusername: " + QString::fromStdString(up->username) + "\n \tpassword: " + QString::fromStdString(up->password)));
        Userui us;
        this->close();
        us.exec();
    }
}


void loginui::help(){
    string s = "md/readme.html";
    QDesktopServices::openUrl(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(s)).absoluteFilePath()));
}
