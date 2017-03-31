#ifndef UPPWD_H
#define UPPWD_H

#include <QDialog>

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
};

#endif // UPPWD_H
