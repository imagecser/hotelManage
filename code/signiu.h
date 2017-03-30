#pragma once
#include "chotel.h"
class Sign {
public:
    bool isAdmin();
    bool isUser();
    bool identified(string username, string password);
};
