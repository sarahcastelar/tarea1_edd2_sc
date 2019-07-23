#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct cuentas {
	char id[5];
	char nombre[5];
	float saldo;

	cuentas() {
		strcpy_s(this->id, "-1");
		strcpy_s(this->nombre, "-1");
		saldo = -1;
	}
};

class cuenta
{
public:
	void guardarArchivo(cuentas test) {
		ofstream file("file.dat", ios::out | ios::binary);
		file.seekp(0, ios::end);
		file.write(reinterpret_cast<const char*>(&test), sizeof(cuentas));
	}

};

