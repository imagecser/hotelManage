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
        pr->photel = h;
        pvecr->push_back(*pr);
		while (true) {
			Room *r = new Room;
			r->photel = h;
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
        sort(vhotels.begin(), vhotels.end(), lessHotel());
        sort(vrooms.begin(), vrooms.end(), lessRoom());
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
        for (unsigned int j = 1; j < vrooms[i].size(); ++j)
			f << vrooms[i][j].numR << ',' << vrooms[i][j].price << ',' << vrooms[i][j].type << '|';
		f << endl;
	}
	f.close();
	return f;
	// 存储数据结构到hotelLoc
}

fstream & fio::odinput() {
	f.open("order.txt", ios::in);
	stringstream ss, ps;
	while(f) {
		Order *od = new Order;
		string line, sIndex;
		getline(f, line);
		if(line.size() == 0) break;
		ss << line;
		getline(ss, sIndex, '|');
		ps << sIndex; ps >> od->orderIndex; ps.clear();
		int indexag, numarg;
		getline(ss, sIndex, ',');
		ps << sIndex; ps >> indexag; ps.clear();
		getline(ss, sIndex, '|');
		ps << sIndex; ps >> numarg; ps.clear();
		for (auto &outitem:vrooms)
			for (auto &initem : outitem) {
				if (indexag == initem.photel->indexH && numarg == initem.numR) {
					od->proom = &initem;
					break;
				}
			}
		string pstr[6];
		for (int i = 0; i < 6; ++i) {
			getline(ss, pstr[i], '/');
			ps << pstr[i]; ps >> od->date[i]; ps.clear();
		}
		getline(ss, od->uname, '|');
		getline(ss, od->idcard, '|');
		vorders.push_back(*od);
	}
	f.close();
	// TODO: 导入order.txt文件
	return f;
}

fstream & fio::odsave() {
	f.open("orderx.txt", ios::out);
	cout << vorders.size();
	for (auto item : vorders) {
		f << setfill('0') << setw(6) << item.orderIndex;
		f << ',' << setfill('0') << setw(4) <<item.proom->photel->indexH;
		f << ',' << item.proom->numR << '|';
		for (int i = 0; i < 6; ++i) f << item.date[i] << '/';
		f << item.uname << '|' << item.idcard << '|';
		f << endl;
	}
	f.close();
	return f;
	// TODO: 存储vorders到order.txt
}
