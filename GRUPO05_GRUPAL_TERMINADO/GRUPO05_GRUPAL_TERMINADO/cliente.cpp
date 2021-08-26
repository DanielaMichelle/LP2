/* ##################################################################################
																					#
 Autor:Grupo 5																		#
Fecha: 02/06/2021																	#
descripcion: archivo cpp que desarrolla los metodos del archivo h					#
																					#
#####################################################################################
*/





#include "cliente.h"
#include <string>
#include <iostream>
using namespace std;
cliente::cliente() {
	nombre_empresa = "";
	telefono_de_contacto = 0;
};

void cliente::ingresar() {
	cout << "========================== Datos del cliente ==============================" << endl;
	persona::ingresar();//llamamos a los datos de persona para que se pueda manipular desde este metodo
	cin.ignore();
	//Se ingresan los datos
	cout << "presione la tecla enter porfavor..." << endl;
	cout << "Ingrese nombre de la empresa:"; getline(cin, nombre_empresa, '\n');
	cout << "Ingrese el numero de contacto:"; cin >> telefono_de_contacto;
}

void cliente::mostrar() {
	cout << "========================== Datos del cliente ==============================" << endl;
	//se muestra los datos
	persona::mostrar();
	cout << "Nombre de la empresa:" << nombre_empresa << endl;
	cout << "Numero de contacto:" << telefono_de_contacto << endl;
}

cliente::~cliente() {
	//se crea el destructor
}