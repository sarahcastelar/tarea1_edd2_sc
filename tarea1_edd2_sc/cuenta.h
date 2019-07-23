#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct cuentas {
	char id[5];
	char nombre[9];
	float saldo;

	cuentas() {
		strcpy_s(this->id, "-1");
		strcpy_s(this->nombre, "-1");
		saldo = 0;
	}
};

class cuenta
{
public:
	void guardarArchivo(cuentas struct_cuentas) {
		ofstream file("archivoCuentas.dat", ios::out | ios::binary);
		file.seekp(0, ios::end);
		file.write(reinterpret_cast<const char*>(&struct_cuentas), sizeof(cuentas));
		cout << "se guardo en el archivo: " << endl;
		cout << struct_cuentas.id << " " << struct_cuentas.nombre << " " << struct_cuentas.saldo << endl;
		cout << "done" << endl;
	}

};

