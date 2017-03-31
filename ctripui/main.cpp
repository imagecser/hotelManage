#include "loginui.h"
#include <QApplication>
#include <iostream>
#include "../code/chotel.h"
#include "../code/labfile.h"
#include <QTextCodec>
#include "dialog.h"
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    fio f;
    f.finput();
    f.odinput();
    f.pswinput();
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("img.ico"));
    //w.show();
    QApplication::setQuitOnLastWindowClosed(true);
    loginui l;
    l.exec();
    return 0;
}
