#include "signiu.h"

bool Sign::identified(string username, string password) {
	bool i = false;
	return i;
	// TODO: 在此处插入 return 语句
}

bool Sign::isAdmin(){
    if(username == "admin" && password == "admin")
        return true;
    return false;
}

bool Sign::isUser(){
    if(username == "image" && password == "image")
        return true;
    return false;
}
