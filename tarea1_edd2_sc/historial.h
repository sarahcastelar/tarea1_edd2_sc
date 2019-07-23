#pragma once
#include <iostream>
using namespace std;

class historial
{
	char id[5];
	int cod;
	float tamano;

	historial() {
		strcpy_s(this->id, "-1");
		cod = -1;
		tamano = -1;
	}

};

