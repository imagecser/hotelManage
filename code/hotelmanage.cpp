#include "hotelmanage.h"

bool judgeNum(string str);

void ManageInfo::addHotel() {
    Hotel *h = new Hotel;
    if(vhotels.size() > 0)
        h->indexH = vhotels[vhotels.size() - 1].indexH + 1;
    else h->indexH = 0;
    vhotels.push_back(*h);
    Room *pr = new Room;
    pr->photel = h;
    vector<Room> *pvr = new vector<Room>;
    pvr->push_back(*pr);
    vrooms.push_back(*pvr);
	// TODO: 添加酒店信息
}

void ManageInfo::addRoom() {
    Room *r = new Room;
    if(vrooms[iRow].size() > 1)
        r->numR = vrooms[iRow][vrooms[iRow].size() - 1].numR + 1;
    else r->numR = 0;
    r->price = 0;
    r->photel = &vhotels[iRow];
    vrooms[iRow].push_back(*r);
}

bool ManageInfo::ediHotel(int i, int j, string str) { // 第i个酒店, 第j个属性
    bool isOk = true;
    if(j == 0) {
        //stringstream pss;
        int index = atoi(str.c_str());
        //pss << setfill('0') << setw(4) <<index;
        //if(pss.str() != str) isOk = false;
        if(judgeNum(str) == false) isOk = false;
        if(index > 9999 || index < 0) isOk = false;
        for(int m = 0; m < vhotels.size(); ++m)
            if(m != i)
                if(vhotels[m].indexH == index)
                    isOk = false;
        if(isOk == true)
            vhotels[i].indexH = index;
        //pss.clear();
    }
    else if(j == 1) vhotels[i].name = str;
    else if(j == 2) vhotels[i].city = str;
    else vhotels[i].area = str;
    return isOk;
}

bool ManageInfo::ediRoom(int i, int j, string str) { // 第i个房间, 第j个属性
    bool isOk = true;
    if(j == 1 || j == 2){
        //stringstream pss;
        int num = atoi(str.c_str());
        //pss << setfill('0') << setw(6) << num;
        //if(pss.str() != str) isOk = false;
        if(judgeNum(str) == false) isOk = false;
        else if(num < 0) isOk = false;
        else
            for(int m = 0; m < vrooms[iRow].size(); ++m)
                if(m != i){
                    if(j == 1){
                        if(vrooms[iRow][m].numR == num)
                            isOk = false;
                    }
                    else if (j == 2){
                        if(vrooms[iRow][m].price == num)
                            isOk = false;
                    }
                }
        if(isOk == true){
            if(j == 1) vrooms[iRow][i].numR = num;
            else if(j == 2) vrooms[iRow][i].price = num;
        }
    }
    else if(j == 3) vrooms[iRow][i].type = str;
    return isOk;
}

bool ManageInfo::delHotel(int i) {
    if(vhotels[i].ordered == false)
        if(vhotels.size() > 0){
            vhotels.erase(vhotels.begin() + i);
            vrooms.erase(vrooms.begin() + i);
            return true;
        }
    return false;
}

bool ManageInfo::delRoom(int m) { //第m个房间(从0开始)
    if(vrooms[iRow][m + 1].ordered == false)
        if(vrooms[iRow].size() > 1){
            vrooms[iRow].erase(vrooms[iRow].begin() + m + 1);
            return true;
        }
    return false;
}

bool judgeNum(string str){
    for(int i = 0; i < str.size(); ++i){
        if(str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
