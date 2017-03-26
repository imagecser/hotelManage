#include "hotelmanage.h"



bool ManageInfo::addHotel(int &index, string &name, string &city, string &area) {
	for (auto photel : vhotels) {
		if (photel.indexH == index) return false;
		else if (photel.city == city && photel.name == name && photel.area == area) return false;
	}
	Hotel *h = new Hotel;
	vector<Room> *vr = new vector<Room>;
	h->area = area;
	h->city = city;
	h->name = name;
	h->indexH = index;
	vhotels.push_back(*h);
	vrooms.push_back(*vr);
	return true;
	// TODO: 添加酒店信息
}

bool ManageInfo::addRoom(int &index, int &num, int &price, string &type) {
	for (int i = 0; i < vhotels.size(); ++i) {
		if (vhotels[i].indexH == index) {
			for (int j = 0; j < vrooms[i].size(); ++j) 
				if (vrooms[i][j].numR == num) return false;
			Room *r = new Room;
			r->numR = num;
			r->photel = &vhotels[i];
			r->price = price;
			r->type = type;
			vrooms[i].push_back(*r);
			return true;
		}
	}
    return false;
}

bool ManageInfo::ediHotel(int & index, string & name, string & city, string & area) {
	for (int i = 0; i < vhotels.size(); ++i) {
		if (vhotels[i].indexH == index) {
			vhotels[i].name = name;
			vhotels[i].city = city;
			vhotels[i].area = area;
			return true;
		}
	}
	return false;
}

bool ManageInfo::ediRoom(int & index, int & num, int & price, string & type) {
	for (int i = 0; i < vhotels.size(); ++i) 
		if(vhotels[i].indexH = index)
			for (int j = 0; j < vrooms[i].size(); ++j) 
				if (vrooms[i][j].numR == num) {
					vrooms[i][j].price = price;
					vrooms[i][j].type = type;
					return true;
				}
	return false;
}

bool ManageInfo::delHotel(int & index) {
	for (int i = 0; i < vhotels.size(); ++i) {
		if (vhotels[i].indexH == index) {
			vhotels.erase(vhotels.begin() + i);
			vrooms.erase(vrooms.begin() + i);
			return true;
		}
	}
	return false;
}

bool ManageInfo::delRoom(int & index, int & num) {
	for (int i = 0; i < vhotels.size(); ++i) 
		if (vhotels[i].indexH == index)
			for (int j = 0; j < vrooms[i].size(); ++j)
				if (vrooms[i][j].numR == num) {
					vrooms[i].erase(vrooms[i].begin() + j);
					return true;
				}
	return false;
}

