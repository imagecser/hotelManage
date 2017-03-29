#include "hoteluser.h"
#include <QDebug>


bool daterep(int a[6], int b[6]){
    int abeg = a[0] * 10000 + a[1] * 100 + a[2];
    int aend = a[3] * 10000 + a[4] * 100 + a[5];
    qDebug() << b[0] << b[1] << b[2];
    int bbeg = b[0] * 10000 + b[1] * 100 + b[2];
    int bend = b[3] * 10000 + b[4] * 100 + b[5];
    if(bbeg >= abeg && bbeg <= aend)
        return true;
    else if(abeg >= bbeg && abeg <= bend)
        return true;
    else return false;
}

bool UserInfo::del(int i){
    if(vorders.size() > 0){
        vorders[i].proom->ordered = false;
        mmap.find(vorders[i].proom)->second->ordered = false;
        vorders.erase(vorders.begin() + i);
        return true;
    }
    return false;
}

