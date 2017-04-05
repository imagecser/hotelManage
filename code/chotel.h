#pragma once
#ifndef INFILE
#include <map>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <assert.h>
#include <ctype.h>
#include <QDesktopServices>
#include <QFileInfo>
#include <QUrl>
using namespace std;
#define INFINE
#endif // !INFILE

struct Room;
struct Order;
struct Hotel;
struct Upsw;
extern vector<vector<Room>> vrooms;
extern vector<Hotel> vhotels;
extern vector<Order> vorders;
extern vector<Upsw> vaccs;
extern map<int, Hotel*> mmap;

extern int iRow;
extern int uRow;
extern int uColumn;
extern int itemp;
extern string username;
extern string password;
extern string email;


struct Hotel {
	int indexH;
	string name;
	string city;
	string area;
    bool ordered;
    Hotel():ordered(false){}
};

struct Room {
    int indexH;
	int numR;
	int price;
    string type;
    bool ordered;
    Room():ordered(false){}
};

struct Order {
	int orderIndex;
	string uname;
	int date[6];
	Room *proom;
    int ppr;
	string idcard;
    string user;
};

struct Upsw {
	string username;
	string password;
    string email;
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
