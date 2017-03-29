#pragma once
#include "chotel.h"
#include <cstdlib>
#include <QtDebug>


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
    bool operator()(vector<Room> &a, vector<Room> &b){
        //return a[0].photel->indexH < b[0].photel->indexH;
        return mmap.find(&a[0])->second->indexH < mmap.find(&b[0])->second->indexH;
    }
};

struct lessOrder{
    bool operator()(const Order &a, const Order &b){
        return a.orderIndex < b.orderIndex;
    }
};

void sortHotel();
int getVecRow(int row);
