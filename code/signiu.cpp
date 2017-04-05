#include "signiu.h"
#include "QWidget"
#include <QDebug>

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
    for(int i = 0; i < vaccs.size(); ++i){
        if(QString::fromStdString(username) == QString::fromStdString(vaccs[i].username))
            if(QString::fromStdString(password) == QString::fromStdString(vaccs[i].password)){
                email = vaccs[i].email;
                return true;
            }
    }
    return false;
}
