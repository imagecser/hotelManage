#pragma once
#include "chotel.h"
#include "labfile.h"

class ManageInfo {
public:
    void addHotel();
    void addRoom();
    bool ediHotel(int i, int j, string str);
    bool ediRoom(int i, int j, string str);
    bool delHotel(int i);
    bool delRoom(int m);
    void msave() { fio f; f.fsave(); }
};
