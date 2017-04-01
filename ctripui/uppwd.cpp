#include "uppwd.h"
#include "../code/chotel.h"
#include <QDebug>
#include <QMessageBox>

Uppwd::Uppwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Uppwd)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    ui->oldEdit->setEchoMode(QLineEdit::Password);
    ui->newEdit->setEchoMode(QLineEdit::Password);
    ui->firmEdit->setEchoMode(QLineEdit::Password);
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->updateBtn, SIGNAL(clicked()), this, SLOT(update()));
}

Uppwd::~Uppwd()
{
    delete ui;
}

void Uppwd::cancel(){
    this->close();
}

void Uppwd::update(){
    if(ui->newEdit->text().size() > 0)
        if(ui->emailEdit->text().size() > 0)
            if(QString::fromStdString(password) == ui->oldEdit->text())
                if(ui->newEdit->text() == ui->firmEdit->text()){
                    password = ui->newEdit->text().toStdString();
                    for(int i = 0; i < vaccs.size(); ++i)
                        if(QString::fromStdString(username) == QString::fromStdString(vaccs[i].username)){
                            vaccs[i].password = password;
                            string base("python mail.py ");
                            string mid(" ");
                            string result(base + ui->emailEdit->text().toStdString() + mid + username + mid + password);
                            system(result.c_str());
                            this->close();
                            return;
                        }
                }
    qDebug() << "false";
}
