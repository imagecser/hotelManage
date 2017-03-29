#ifndef LOGINUI_H
#define LOGINUI_H

#include <QtWidgets\qdialog.h>
#include "mainn.h"
#include "userui.h"

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
    void adminTemp();
    void userTemp();

private:
    Ui::loginui *ui;

};

#endif // LOGINUI_H
