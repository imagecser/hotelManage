#pragma once
#ifndef INFILE
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <assert.h>
using namespace std;
#define INFINE
#endif // !INFILE

struct Room;
struct Order;
struct Hotel;
extern vector<vector<Room>> vrooms;
extern vector<Hotel> vhotels;
extern vector<Room> vorders;

struct Hotel {
	int indexH;
	string name;
	string city;
	string area;
};

struct Room {
	int numR;
	int price;
	string type;
	Hotel photel;
};

struct Order {
	int orderR;
	string uname;
	int date[6];
	Room proom;
};

struct Upsw {
	string username;
	string password;
};

/*

struct Room :public Hotel {
int numR;
int price;
string type;
Room & operator=(Hotel & h);
};

struct Order:public Room {
	int orderR;
	int date[6];
	Order & operator=(Room & r);
};
*/
