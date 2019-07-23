#pragma once
#include <iostream>
using namespace std;

class historial
{
	char no_cuenta[5];
	int tipo;
	float monto;

	historial() {
		strcpy_s(this->no_cuenta, "-1");
		tipo = -1;
		monto = -1;
	}

};

