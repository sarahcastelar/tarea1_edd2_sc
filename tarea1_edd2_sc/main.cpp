#include <iostream>
#include "cuenta.h"
#include "historial.h"

using namespace std;

int main() {

	struct cuentas struct_cuentas;
	struct transaccion struct_t;
	bool hayCuenta = false;
	int resp = -1;
	cuenta c;
	historial h;

	//pedir los datos
	do {
		char id1[5];
		char nombre1[9];
		float monto = -1;
		
		cout << "---------------------" << endl
			<< "Bienvenido al Banco" << endl
			<< "1. Agregar cliente" << endl
			<< "2. Depositos/Retiros" << endl
			<< "3. Ver historial de transacciones" << endl
			<< "4. Salir" << endl
			<< "---------------------" << endl;
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
			cout << "--Depositos y Retiros -- " << endl
				<< "1. Depositos" << endl
				<< "2. Retiros" << endl
				<< "3. atras " << endl
				<< "Ingrese su opcion: " << endl;
			int resp2 = -1;
			cin >> resp2;

			if (resp2 != 3) {
				c.imprimirArchivo();

				cout << "Ingrese id: " << endl;
				cin >> id1;
				strcpy_s(struct_t.no_cuenta, id1);
				cout << "Ingrese monto: " << endl;
				cin >> struct_t.monto;
			
				if (resp2 == 1)
					struct_t.tipo = 1;
				else 
					struct_t.tipo = 2;

				h.hacerTransaccion(struct_t);
				cout << "Deposito hecho exitosamente. " << endl;
			}
		}

		if (resp == 3) {
			h.imprimirHistorial();
		}

	} while (resp != 4);



	return 0;
}