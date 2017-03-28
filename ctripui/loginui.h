#ifndef LOGINUI_H
#define LOGINUI_H

#include <QtWidgets\qdialog.h>
#include "mainn.h"

namespace Ui {
class loginui;
}

class loginui : public QDialog
{
    Q_OBJECT

public:
    explicit loginui(QWidget *parent = 0);
    ~loginui();

private slots:
    void on_loginBtn_clicked();
    void adminTemp();

private:
    Ui::loginui *ui;

};

#endif // LOGINUI_H
