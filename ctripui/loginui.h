#ifndef LOGINUI_H
#define LOGINUI_H

#include <QDialog>

namespace Ui {
class loginui;
}

class loginui : public QDialog
{
    Q_OBJECT

public:
    explicit loginui(QWidget *parent = 0);
    ~loginui();

private:
    Ui::loginui *ui;
};

#endif // LOGINUI_H
