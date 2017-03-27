#ifndef ROOMUI_H
#define ROOMUI_H

#include <QDialog>

namespace Ui {
class roomui;
}

class roomui : public QDialog
{
    Q_OBJECT

public:
    explicit roomui(QWidget *parent = 0);
    ~roomui();

private:
    Ui::roomui *ui;
};

#endif // ROOMUI_H
