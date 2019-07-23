#pragma once
#include <iostream>
#include <fstream>
#include "cuenta.h"
using namespace std;

struct transaccion {
	char no_cuenta[5];
	int tipo;
	float monto;
	char nombre[9];

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
		ofstream fileH("historial1.dat", ios::out | ios::app | ios::binary);
		if (!fileH) {
			cout << "error de apertura en el archivo. " << endl;
			return;
		}
		else {
			string s = struct_t.no_cuenta;
			float floatTemporal = -2;
			floatTemporal = getMonto(s);
			
			if (floatTemporal != -1) {
				if (struct_t.tipo == 2) {
					if (floatTemporal >= struct_t.monto) {
						floatTemporal -= struct_t.monto;
						actualizarSaldo(s, floatTemporal);
					} else 
						cout << "Sus fondos son insufiencientes para retirar dinero. " << endl;
				}
				else {
					floatTemporal += struct_t.monto;
					actualizarSaldo(s, floatTemporal);
				}
				fileH.seekp(0, ios::end);
				fileH.write(reinterpret_cast<const char*>(&struct_t), sizeof(struct_t));
			}
			else
				cout << "La cuenta ingresada no existe. " << endl;
			
			fileH.close();
		}
	}

	void imprimirHistorial() {
		ifstream fileH("historial1.dat", ios::in | ios::binary);
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

	float getMonto(string no_cuenta) {
		ifstream fileH("archivoCuentas4.dat", ios::in | ios::binary);
		if (!fileH) {
			cout << "Error de aprtura en el archivo!" << endl;
			return -1;
		}

		fileH.seekg(0, ios::beg);
		cuentas struct_c;
		fileH.read(reinterpret_cast<char*>(&struct_c), sizeof(struct_c));

		while (!fileH.eof()) {
			string s2 = struct_c.id;
			if (no_cuenta.compare(s2) == 0) {
				return struct_c.saldo;
				break;
			}
			fileH.read(reinterpret_cast<char*>(&struct_c), sizeof(struct_c));
		}
		fileH.close();
		return -1;
	}

	void actualizarSaldo(string no_cuenta, float monto) {
		cuenta c;
		ifstream fileC("archivoCuentas4.dat", ios::in | ios::binary);
		if (!fileC)
		{
			cout << "Error de aprtura en el archivo!" << endl;
			return;
		}

		fileC.seekg(0, ios::beg);
		cuentas struct_cuentas;
		fileC.read(reinterpret_cast<char*>(&struct_cuentas), sizeof(struct_cuentas));

		while (!fileC.eof()) {
			string s2 = struct_cuentas.id;
			if (no_cuenta.compare(s2) == 0) {
				struct_cuentas.saldo = monto;
				c.guardarArchivo(struct_cuentas);
				break;
			}
			fileC.read(reinterpret_cast<char*>(&struct_cuentas), sizeof(struct_cuentas));
		}
		fileC.close();
	}




};

