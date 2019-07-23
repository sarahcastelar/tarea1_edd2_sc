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
		ofstream file("archivoCuentas.dat", ios::out | ios::app | ios::binary);
		if (!file) {
			cout << "----------error de apertura en el archivo. " << endl;
			return;
		}
		else {
			file.seekp(0, ios::end);
			file.write(reinterpret_cast<const char*>(&struct_cuentas), sizeof(cuentas));
			cout << "done" << endl;
			file.close();
		}
	}

	void imprimirArchivo() {
		ifstream file("archivosCuentas.dat", ios::in | ios::binary);
		if (!file)
		{
			cout << "Error de aprtura en el archivo!" << endl;
			return;
		}

		file.seekg(0, ios::beg);
		cuentas struct_cuentas;
		file.read(reinterpret_cast<char*>(&struct_cuentas), sizeof(struct_cuentas));

		while (!file.eof()) {
			cout << "ID: " << struct_cuentas.id
				<< " Nombre: " << struct_cuentas.nombre << " " 
				<< "Saldo: " << struct_cuentas.saldo << endl;

			file.read(reinterpret_cast<char*>(&struct_cuentas), sizeof(struct_cuentas));

		}
		file.close();
	}

};

