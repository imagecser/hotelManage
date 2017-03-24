#ifndef CHOTEL
#include "chotel.h"
#define CHOTEL
#endif // !CHOTEL
#include "labfile.h"

int main() {
	fio iofile;
	iofile.finput();
	iofile.fsave();
	iofile.odinput();
	iofile.odsave();
	return 0;
}