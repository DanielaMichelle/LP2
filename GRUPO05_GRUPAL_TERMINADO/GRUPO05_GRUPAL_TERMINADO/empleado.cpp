/* ##################################################################################
																					#
 Autor:Grupo 5																		#
Fecha: 02/06/2021																	#
descripcion: archivo cpp que desarrolla los metodos del archivo h					#
																					#
#####################################################################################
*/


#include "empleado.h"
#include <string>
#include <iostream>
using namespace std;
empleado::empleado() {
	sueldo_bruto = 0;
	saldo_neto = 0;
};
void empleado::mostrar() {
	cout << "========================== Datos del empleado ==============================" << endl;
	persona::mostrar(); //llamamos al metodo mostrar de persona
	cout << "Saldo bruto:" << sueldo_bruto << endl;
	calcular_salario_neto();
}
void empleado::ingresar() {
	cout << "========================== Datos del empleado ==============================" << endl;
	persona::ingresar(); //llamamos al metodo ingresar de persona
	cout << "Ingreso de sueldo en bruto:"; cin >> sueldo_bruto;
}
void empleado::calcular_salario_neto() {
	//metodo para calcular el salario neto de la persona
	cout << "Se calculara su saldo neto..." << endl;
	saldo_neto = sueldo_bruto * 0.5;
	saldo_neto = sueldo_bruto - saldo_neto;
	cout << "Su saldo neto es:" << saldo_neto << endl;
}
empleado::~empleado() {
	//creamos al constructor
}