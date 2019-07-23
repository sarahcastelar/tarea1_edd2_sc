#include <iostream>
#include "cuenta.h"
#include "historial.h"

using namespace std;

int main() {

	struct cuentas test;
	strcpy_s(test.nombre, "sara");
	cout << test.nombre;
	int resp = -1;
	char id1[5];
	char nombre1[5];
	float saldo;
	bool hayCuenta = false;
	cuenta c;

	//pedir los datos
	do {
		
		cout << "Bienvenido al Banco" << endl
			<< "1. Crear cuenta" << endl
			<< "2. Depositar dinero" << endl
			<< "3. Retirar dinero" << endl
			<< "4. Salir" << endl;
		cin >> resp;

		if (resp == 1) {
			cout << "Ingrese id: " << endl;
			cin >> id1;
			strcpy_s(test.id, id1);
			cout << "Ingrese nombre: " << endl;
			cin >> nombre1;
			strcpy_s(test.nombre, nombre1);

			//guardar el struct en el archivo
			c.guardarArchivo(test);
			hayCuenta = true;
		}

		if (resp == 2 && hayCuenta) {

		}

		if (resp == 3 && hayCuenta) {

		}

	} while (resp != 4);



	return 0;
}