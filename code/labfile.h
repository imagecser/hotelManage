#pragma once
#include "chotel.h"
#include <cstdlib>



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


struct lessHotel{
    bool operator()(const Hotel &a, const Hotel &b){
        return a.indexH < b.indexH;
    }
};

struct lessRoom{
    bool operator()(const vector<Room> &a, const vector<Room> &b){
        return a[0].photel->indexH < b[0].photel->indexH;
    }
};

struct lessOrder{
    bool operator()(const Order &a, const Order &b){
        return a.orderIndex < b.orderIndex;
    }
};
