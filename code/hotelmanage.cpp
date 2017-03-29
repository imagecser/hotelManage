#include "hotelmanage.h"

bool judgeNum(string str);

void ManageInfo::addHotel() {
    qDebug() << vhotels.size();
    Hotel *h = new Hotel;
    if(vhotels.size() > 0)
        h->indexH = vhotels[vhotels.size() - 1].indexH + 1;
    else h->indexH = 0;
    /*
    int i;
    for(i = 0; i < vhotels.size() - 1; ++i){
        if(vhotels[i + 1].indexH - vhotels[i].indexH != 1){
            h->indexH = vhotels[i].indexH + 1;
            break;
        }
    }
    if(vhotels.size() == 0) h->indexH = 0;
    else if(vhotels.size() == 1 || i == vhotels.size() - 1) h->indexH = vhotels[vhotels.size() - 1].indexH + 1;*/
    vhotels.push_back(*h);
    Room *pr = new Room;
    vector<Room> *pvr = new vector<Room>;
    pvr->push_back(*pr);
    vrooms.push_back(*pvr);
    mmap[&vrooms[vrooms.size() - 1][0]] = &vhotels[vhotels.size() - 1];
    qDebug() << vhotels.size();
	// TODO: 添加酒店信息
}

void ManageInfo::addRoom() {
    Room *r = new Room;
    int i;
    for(i = 1; i < vrooms[iRow].size() - 1; ++i){
        if(vrooms[iRow][i + 1].numR - vrooms[iRow][i].numR != 1){
            r->numR = vrooms[iRow][i].numR + 1;
            break;
        }
    }
    if(vrooms[iRow].size() == 1) r->numR = 0;
    else if(vrooms[iRow].size() == 2 || i == vrooms[iRow].size() - 1) r->numR = vrooms[iRow][vrooms[iRow].size() - 1].numR + 1;
    //if(vrooms[iRow].size() > 1)
    //    r->numR = vrooms[iRow][vrooms[iRow].size() - 1].numR + 1;
    //else r->numR = 0;
    r->price = 0;
    qDebug() << vrooms[iRow].size();
    r->indexH = vhotels[itemp].indexH;
    vrooms[iRow].push_back(*r);
    mmap[&vrooms[iRow][vrooms[iRow].size() - 1]] = &vhotels[itemp];
    //vrooms[iRow][vrooms[iRow].size() - 1].indexH = vhotels[itemp].indexH;
    //xsortHotel();
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
        if(isOk == true){
            vhotels[i].indexH = index;
            for(int j = 0; j < vrooms[i].size();++j)
                vrooms[i][j].indexH = index;
        }//pss.clear();
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
    if(vhotels.size() > 0)
        if(vhotels[i].ordered == false){
            vrooms.erase(vrooms.begin() + getVecRow(i));
            vhotels.erase(vhotels.begin() + i);
            return true;
        }
    return false;
}

bool ManageInfo::delRoom(int m) { //第m个房间(从0开始)
    if(vrooms[iRow].size() > 1)
        if(vrooms[iRow][m + 1].ordered == false){
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
