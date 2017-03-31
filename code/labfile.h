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
        int ai, bi;
        qDebug() << vrooms[1][0].indexH;
        for(ai = 0; ai < vrooms.size(); ++ai)
            if(vrooms[ai][0].indexH == a[0].indexH)
                break;
        for(bi = 0; bi < vrooms.size(); ++bi)
            if(vrooms[bi][0].indexH == b[0].indexH)
                break;
        //return a[0].photel->indexH < b[0].photel->indexH;
        return mmap.find(ai * 1000)->second->indexH < mmap.find(bi * 1000)->second->indexH;
        //return mmap.find(&a[0])->second->indexH < mmap.find(&b[0])->second->indexH;
    }
};

struct lessOrder{
    bool operator()(const Order &a, const Order &b){
        return a.orderIndex < b.orderIndex;
    }
};

void sortHotel();
int getVecRow(int row);
