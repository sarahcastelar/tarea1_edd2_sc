#include <iostream>
#include "cuenta.h"
#include "historial.h"

using namespace std;

int main() {

	struct cuentas struct_cuentas;
	//strcpy_s(struct_cuentas.nombre, "sara");
	//cout << struct_cuentas.nombre;
	int resp = -1;
	char id1[5];
	char nombre1[5];
	bool hayCuenta = false;
	cuenta c;

	//pedir los datos
	do {
		
		cout << "Bienvenido al Banco" << endl
			<< "1. Agregar cliente" << endl
			<< "2. Depositar dinero" << endl
			<< "3. Retirar dinero" << endl
			<< "4. Salir" << endl;
		cin >> resp;

		if (resp == 1) {
			cout << "Ingrese id: " << endl;
			cin >> id1;
			strcpy_s(struct_cuentas.id, id1);
			cout << "Ingrese nombre: " << endl;
			cin >> nombre1;
			strcpy_s(struct_cuentas.nombre, nombre1);

			//guardar el nuevo cliente en el archivo
			c.guardarArchivo(struct_cuentas);
			hayCuenta = true;
			cout << "Cliente/cuenta agregado exitosamente. " << endl;
		}

		if (resp == 2 && hayCuenta) {

		}

		if (resp == 3 && hayCuenta) {

		}

	} while (resp != 4);



	return 0;
}