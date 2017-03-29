#ifndef ORDERING_H
#define ORDERING_H

#include <QDialog>
#include "../code/chotel.h"
#include "ui_ordering.h"

namespace Ui {
class Ordering;
}

class Ordering : public QDialog
{
    Q_OBJECT

public:
    explicit Ordering(QWidget *parent = 0);
    ~Ordering();

private:
    Ui::Ordering *ui;
private slots:
    void dataUpdate();
    void quitW();
};

#endif // ORDERING_H
