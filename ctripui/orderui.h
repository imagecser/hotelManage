#ifndef ORDERUI_H
#define ORDERUI_H

#include <QDialog>

namespace Ui {
class Orderui;
}

class Orderui : public QDialog
{
    Q_OBJECT

public:
    explicit Orderui(QWidget *parent = 0);
    ~Orderui();

private:
    Ui::Orderui *ui;
};

#endif // ORDERUI_H
