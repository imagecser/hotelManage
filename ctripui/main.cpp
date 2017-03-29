#include "loginui.h"
#include <QApplication>
#include <iostream>
#include "../code/chotel.h"
#include "../code/labfile.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    fio f;
    f.finput();
    f.odinput();
    QApplication a(argc, argv);
    //w.show();
    QApplication::setQuitOnLastWindowClosed(true);
    loginui l;
    l.exec();
    return 0;
}
