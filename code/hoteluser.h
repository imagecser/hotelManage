#pragma once
#include "labfile.h"
#include "chotel.h"

class UserInfo {
public:
    bool del(int i);
    void usave(){
        fio f;
        f.odsave();
    }
};


bool daterep(int a[6], int b[6]);
