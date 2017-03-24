#pragma once
#include "chotel.h"

class fio {
	string hotelLoc;
	string orderLoc;
	string pswLoc;
	fstream f;
public:
	fio() :hotelLoc("hotel.txt"), orderLoc("order.txt"), pswLoc("psw.txt") {}
	fstream & finput();
	fstream & fsave();
	fstream & odinput();
	fstream & odsave();
	fstream & pswinput();
	fstream & pswsave();
};
