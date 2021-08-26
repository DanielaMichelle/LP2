/* ##################################################################################
																					#
 Autor:Grupo 5																		#
Fecha: 02/06/2021																	#
descripcion: archivo cpp que desarrolla los metodos del archivo h					#
																					#
#####################################################################################
*/


#include "directivo.h"
#include <string>
#include <iostream>
using namespace std;



directivo::directivo() {
	categoria = "";
};

void directivo::ingresar() {
	cout << "========================== Datos del directivo  ==============================" << endl;
	empleado::ingresar();//llamamos a los metodos tanto de persona como de empleado para ingresar
	cout << "Ingrese la categoria de la empresa:"; cin.ignore(); getline(cin, categoria, '\n');
}

void directivo::mostrar() {
	cout << "========================== Datos del directivo  ==============================" << endl;
	//lamamos a los metodos tanto de persona como empleado gracias a la herencia
	empleado::mostrar();
	cout << "Categoria de la empresa:" << categoria << endl;
}
directivo::~directivo() {
	//creamos el destructor
}
