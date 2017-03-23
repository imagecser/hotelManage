#pragma once
#include "chotel.h"
#ifndef INFILE
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
#define INFINE
#endif // !INFILE

class CmdUI {
	CmdUI & initial();
	CmdUI & mngInitial();
	CmdUI & userInitial();
	CmdUI & findInfoUser();
	CmdUI &	hotelChoose();
	CmdUI & roomChoose();
	CmdUI & viewOrder();
};