#ifndef UPPWD_H
#define UPPWD_H

#include <QDialog>
#include "ui_uppwd.h"

namespace Ui {
class Uppwd;
}

class Uppwd : public QDialog
{
    Q_OBJECT

public:
    explicit Uppwd(QWidget *parent = 0);
    ~Uppwd();

private:
    Ui::Uppwd *ui;
private slots:
    void cancel();
    void update();
};

#endif // UPPWD_H
