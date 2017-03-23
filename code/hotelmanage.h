#pragma once
#include "chotel.h"
#include "labfile.h"

class ManageInfo {
public:
	ManageInfo & addInfo();
	ManageInfo & ediInfo();
	ManageInfo & delInfo();
	ManageInfo & msave(fio f) { f.fsave(); return *this; }
};