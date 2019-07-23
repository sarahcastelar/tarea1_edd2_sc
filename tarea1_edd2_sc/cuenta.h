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
		ofstream fileC("archivoCuentas4.dat", ios::out | ios::app | ios::binary);
		if (!fileC) {
			cout << "----------error de apertura en el archivo. " << endl;
			return;
		}
		else {
			fileC.seekp(0, ios::end);
			fileC.write(reinterpret_cast<const char*>(&struct_cuentas), sizeof(cuentas));
			cout << "done" << endl;
			fileC.close();
		}
	}

	void imprimirArchivo() {
		cout << "** imprimiendo cuentas ** " << endl;
		ifstream fileC("archivoCuentas4.dat", ios::in | ios::binary);
		if (!fileC)
		{
			cout << "Error de aprtura en el archivo!" << endl;
			return;
		}

		fileC.seekg(0, ios::beg);
		cuentas struct_cuentas;
		fileC.read(reinterpret_cast<char *>(&struct_cuentas), sizeof(struct_cuentas));

		while (!fileC.eof()) {
			cout << "ID: " << struct_cuentas.id
				<< " Nombre: " << struct_cuentas.nombre << " " 
				<< "Saldo: " << struct_cuentas.saldo << endl;

			fileC.read(reinterpret_cast<char *>(&struct_cuentas), sizeof(struct_cuentas));

		}
		fileC.close();
		cout << "** fin imprimiendo cuentas ** " << endl;
	}

	

};

