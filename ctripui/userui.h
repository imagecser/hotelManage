#ifndef USERUI_H
#define USERUI_H

#include <QDialog>

namespace Ui {
class Userui;
}

class Userui : public QDialog
{
    Q_OBJECT

public:
    explicit Userui(QWidget *parent = 0);
    ~Userui();

private:
    Ui::Userui *ui;
};

#endif // USERUI_H
