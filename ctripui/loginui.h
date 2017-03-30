#ifndef LOGINUI_H
#define LOGINUI_H

#include <QtWidgets\qdialog.h>
#include "mainn.h"
#include "userui.h"
#include "ui_userui.h"
#include "../code/signiu.h"
#include "../code/chotel.h"

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
    void login();
    void exit();

private:
    Ui::loginui *ui;
    Sign sg;
};

#endif // LOGINUI_H
