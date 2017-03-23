#pragma once
#include "chotel.h"
#include "labfile.h"

class ManageInfo {
public:
	vector<vector<Room>> & addInfo();
	vector<vector<Room>> & ediInfo();
	vector<vector<Room>> & delInfo();
	ManageInfo & msave(fio f) { f.fsave(); return *this; }
};