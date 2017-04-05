#ifndef CHOTEL
#include "chotel.h"
#define CHOTEL
#endif // !CHOTEL

vector<vector<Room>> vrooms;

vector<Hotel> vhotels;

vector<Order> vorders;

vector<Upsw> vaccs;

int itemp;
int iRow;
int uRow;
int uColumn;
string username;
string password;
string email;
map<int, Hotel*> mmap;


/*
Room & Room::operator=(Hotel & h) {
	indexH = h.indexH;
	name = h.name;
	city = h.city;
	area = h.area;
	return *this;
	// TODO: 赋值Hotel到Room
}

Order & Order::operator=(Room & r) {
	indexH = r.indexH;
	name = r.name;
	city = r.city;
	area = r.area;
	numR = r.numR;
	price = r.price;
	type = r.type;
	return *this;
	// TODO: 赋值Room到Order
}
*/
