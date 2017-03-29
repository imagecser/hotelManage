#include "labfile.h"
#include <algorithm>

fstream & fio::finput() {
	stringstream ss, ps;
	f.open(hotelLoc, ios::in);
	while (true) {
		string line, sIndex;
		getline(f, line); 
		if (line.size() == 0) break;
		Hotel *h = new Hotel;
		ss << line; // 将一行输入ss流中
        getline(ss, sIndex, ',');
        h->indexH = atoi(sIndex.c_str());
		ps.clear(); // 将首个index字符串转化为整型
		getline(ss, h->name, ','); 
		getline(ss, h->city, ','); 
		getline(ss, h->area, '|'); // 填充hotel实例的属性
		vector<Room> *pvecr = new vector<Room>;
        Room *pr = new Room;
        //pr->photel = h;
        pr->indexH = h->indexH;
        pvecr->push_back(*pr);
		while (true) {
			Room *r = new Room;
            //r->photel = h;
            r->indexH = h->indexH;
			getline(ss, sIndex, ',');
			if (sIndex.size() == 0) break; // 判断到头与否
			ps << sIndex;
			ps >> r->numR; ps.clear(); // 将首个numR字符串转化为整型
			getline(ss, sIndex, ',');
			ps << sIndex;
			ps >> r->price;
			ps.clear(); // 将首个price字符串转化为整型
			getline(ss, r->type, '|'); // 填充room实例的属性
            pvecr->push_back(*r);
		}
		ss.clear();
        vrooms.push_back(*pvecr);
        vhotels.push_back(*h);
        //sort(vhotels.begin(), vhotels.end(), lessHotel());
        for(int i = 0; i < vrooms.size(); ++i){
            for(int j = 0; j < vrooms[i].size(); ++j){
                mmap[&vrooms[i][j]] = &vhotels[i];
            }
        }
        //sort(vrooms.begin(), vrooms.end(), lessRoom());
    }
    f.close();
    return f;
	// TODO: 从hotelLoc读入到数据结构
}

fstream & fio::fsave() {
	f.open(hotelLoc, ios::out);
	for (unsigned int i = 0; i < vhotels.size(); ++i) {
		f << setfill('0') << setw(4) << vhotels[i].indexH;
		f << ',' << vhotels[i].name << ',' << vhotels[i].city << ',' << vhotels[i].area << '|';
        qDebug() << mmap.find(&vrooms[4][0])->second->indexH;
        int pi = getVecRow(i);
        for (unsigned int j = 1; j < vrooms[pi].size(); ++j)
            f << vrooms[pi][j].numR << ',' << vrooms[pi][j].price << ',' << vrooms[pi][j].type << '|';
		f << endl;
	}
	f.close();
	return f;
	// 存储数据结构到hotelLoc
}

fstream & fio::odinput() {
    f.open(orderLoc, ios::in);
	stringstream ss, ps;
	while(f) {
		Order *od = new Order;
		string line, sIndex;
        getline(f, line);
		if(line.size() == 0) break;
		ss << line;
        getline(ss, sIndex, ',');
		ps << sIndex; ps >> od->orderIndex; ps.clear();
		int indexag, numarg;
		getline(ss, sIndex, ',');
		ps << sIndex; ps >> indexag; ps.clear();
		getline(ss, sIndex, '|');
        ps << sIndex; ps >> numarg; ps.clear();
        for(int i = 0; i < vrooms.size(); ++i)
            for(int j = 1; j < vrooms[i].size(); ++j){
                if(numarg == vrooms[i][j].numR && indexag == mmap.find(&vrooms[i][j])->second->indexH){
                    od->proom = &vrooms[i][j];
                    od->proom->ordered = true;
                    mmap.find(od->proom)->second->ordered = true;
                }
            }
		string pstr[6];
		for (int i = 0; i < 6; ++i) {
			getline(ss, pstr[i], '/');
			ps << pstr[i]; ps >> od->date[i]; ps.clear();
		}
		getline(ss, od->uname, '|');
		getline(ss, od->idcard, '|');
        getline(ss, od->user, '|');
		vorders.push_back(*od);
	}
	f.close();
	// TODO: 导入order.txt文件
	return f;
}

fstream & fio::odsave() {
    f.open(orderLoc, ios::out);
    qDebug() << vorders.size();
    for (int i = 0; i < vorders.size(); ++i) {
        f << setfill('0') << setw(6) << vorders[i].orderIndex;
        f << ',' << setfill('0') << setw(4) << mmap.find(vorders[i].proom)->second->indexH;
        f << ',' << vorders[i].proom->numR << '|';
        for (int j = 0; j < 6; ++j)
            f << vorders[i].date[j] << '/';
        f << vorders[i].uname << '|' << vorders[i].idcard << '|' << vorders[i].user << '|';
		f << endl;
	}
	f.close();
	return f;
	// TODO: 存储vorders到order.txt
}

void sortHotel(){
    //for(int i = 0; i < vrooms.size(); ++i)
    //    qDebug() << vrooms[i][0].indexH << ' ' << vrooms[i][0].photel->indexH;
    sort(vhotels.begin(), vhotels.end(), lessHotel());
    for(int i = 0; i < vrooms.size(); ++i){
        if(vrooms[i][0].indexH != mmap.find(&vrooms[i][0])->second->indexH){
            for(int m = 0; m < vhotels.size(); ++m){
                if(vrooms[i][0].indexH == vhotels[m].indexH){
                    for(int j = 0; j < vrooms[i].size(); ++j)
                        mmap[&vrooms[i][j]] = &vhotels[m];
                    //qDebug() << i << m << vrooms[i][0].indexH << mmap.find(&vrooms[i][0])->second->indexH;
                }
            }
        }
    }
    //for(int i = 0; i < vrooms.size(); ++i)
    //    qDebug() << vrooms[i][0].indexH << mmap.find(&vrooms[i][0])->second->indexH;
}

int getVecRow(int row){
    for(int i = 0; i < vrooms.size(); ++i){
        if(mmap.find(&vrooms[i][0])->second == &vhotels[row]){
            return i;
        }
    }
}
