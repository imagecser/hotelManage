#ifndef CHOTEL
#include "chotel.h"
#define CHOTEL
#endif // !CHOTEL

vector<vector<Room>> vrooms;

vector<Hotel> vhotels;

vector<Room> vorders;

Room & Room::operator=(Hotel & h) {
	indexH = h.indexH;
	name = h.name;
	city = h.city;
	area = h.area;
	return *this;
	// TODO: ��ֵHotel��Room
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
	// TODO: ��ֵRoom��Order
}
