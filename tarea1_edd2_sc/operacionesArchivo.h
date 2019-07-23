#pragma once
#include <iostream>
#include <fstream>


class operacionesArchivo
{
	ofstream file;

	void guardarArchivo() {
		file.open("file.dat", ios::in | ios::binary);

		
	}

};

