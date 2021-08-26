/* ##################################################################################
																					#
 Autor:Grupo 5																		#
Fecha: 02/06/2021																	#
descripcion: archivo cpp que desarrolla los metodos del archivo h					#
																					#
#####################################################################################
*/

#include "persona.h"
#include <string>
#include <iostream>
using namespace std;
persona::persona() {
	nombre = "";
	edad = 0;
}

void persona::ingresar() {
	cout << "========================== Datos personales ==============================" << endl;
	cin.ignore();
	cout << "Ingrese su nombre porfavor:"; getline(cin, nombre, '\n');
	cout << "Ingrese su edad porfavor:"; cin >> edad;

}

void persona::mostrar() {
	cout << "========================== Datos persona ==============================" << endl;
	cout << "Nombre:" << nombre << endl;
	cout << "Edad:" << edad << endl;
}

persona::~persona() {

}