#include "signup.h"
#include "ui_signup.h"

Signup::Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->signBtn, SIGNAL(clicked()), this, SLOT(signup()));
}

Signup::~Signup()
{
    delete ui;
}

void Signup::cancel(){
    this->close();
}

void Signup::signup(){
    username = ui->usernameEdit->text().toStdString();
    password = ui->passwordEdit->text().toStdString();
    email = ui->emailEdit->text().toStdString();
    if(username.size() == 0 || password.size() == 0 || email.size() == 0)
        QMessageBox::warning(NULL, " ", "Information incomplete.", QMessageBox::Ok|QMessageBox::Ok, QMessageBox::Ok);
    else{
        for(int i = 0; i < vaccs.size(); ++i)
            if(QString::fromStdString(vaccs[i].username) == ui->usernameEdit->text()){
                QMessageBox::warning(NULL, " ", "Username signed up!", QMessageBox::Ok|QMessageBox::Ok, QMessageBox::Ok);
                return;
            }
        Upsw *up = new Upsw;
        up->password = password;
        up->username = username;
        up->email = email;
        vaccs.push_back(*up);
        f.pswsave();
        QMessageBox::about(NULL, "signed up!", ("Your account information:\n\n username: " + QString::fromStdString(up->username) + "\n password: " + QString::fromStdString(up->password) + "\n email: " + QString::fromStdString(email)));
        string base("python mail.py ");
        string mid(" ");
        string result(base + email + mid + username + mid + password);
        fstream bat("sendmail.bat", ios::out);
        bat << result;
        bat.close();
        system("python trans.py");
        system("sendmail.bat");
        Userui us;
        this->close();
        us.exec();
    }
}
