#include "roomui.h"
#include "ui_roomui.h"

roomui::roomui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::roomui)
{
    ui->setupUi(this);
}

roomui::~roomui()
{
    delete ui;
}
