#pragma once
#include "chotel.h"

class fio {
	string hotelLoc;
	string orderLoc;
	fstream f;
public:
	fio() :hotelLoc("hotel.txt"), orderLoc("order.txt") {}
	fstream & finput();
	fstream & fsave();

};
