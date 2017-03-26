#pragma once
#include "chotel.h"
class Sign {
	Sign & signup();
	Sign & signin();
    bool identified(string username, string password);
};
