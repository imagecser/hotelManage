#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "signup.h"
#include "userui.h"
#include "../code/labfile.h"

namespace Ui {
class Signup;
}

class Signup : public QDialog
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = 0);
    ~Signup();

private:
    Ui::Signup *ui;
    fio f;
private slots:
    void cancel();
    void signup();
};

#endif // SIGNUP_H
