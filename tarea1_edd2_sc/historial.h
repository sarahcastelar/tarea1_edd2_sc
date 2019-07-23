#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct transaccion {
	char no_cuenta[5];
	int tipo;
	float monto;

	transaccion() {
		strcpy_s(this->no_cuenta, "-1");
		tipo = -1;
		monto = -1;
	}
};

class historial
{
public:
	void hacerTransaccion(transaccion struct_t) {
		ofstream fileH("historial.dat", ios::out | ios::app | ios::binary);
		if (!fileH) {
			cout << "error de apertura en el archivo. " << endl;
			return;
		}
		else {
			fileH.seekp(0, ios::end);
			fileH.write(reinterpret_cast<const char*>(&struct_t), sizeof(struct_t));
			cout << "done" << endl;
			//hacer algo aqui que ACTUALICE EL SALDO .
			fileH.close();
		}
	}

	void imprimirHistorial() {
		ifstream fileH("historial.dat", ios::in | ios::binary);
		if (!fileH) {
			cout << "Error de aprtura en el archivo!" << endl;
			return;
		}

		fileH.seekg(0, ios::beg);
		transaccion struct_t;
		fileH.read(reinterpret_cast<char*>(&struct_t), sizeof(struct_t));

		while (!fileH.eof()) {
			cout << "ID: " << struct_t.no_cuenta 
				<< " Transaccion: " << ( (struct_t.tipo == 1 ? "Deposito" : "Retiro")) << endl
				<< " Saldo Final: " << struct_t.monto << endl;

			fileH.read(reinterpret_cast<char*>(&struct_t), sizeof(struct_t));

		}
		fileH.close();
	}




};

