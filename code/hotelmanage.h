#pragma once
#include "chotel.h"
#include "labfile.h"

class ManageInfo {
public:
	bool addHotel(int &index, string &name, string &city, string &area);
	bool addRoom(int &index, int &num, int &price, string &type);
	bool ediHotel(int &index, string &name, string &city, string &area);
	bool ediRoom(int &index, int &num, int &price, string &type);
	bool delHotel(int &index);
	bool delRoom(int &index, int &num);
	ManageInfo & msave(fio f) { f.fsave(); return *this; }
};