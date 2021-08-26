#include "celular.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, Celular& objeto)
{
	out << "DATOS DEL CELULAR: " << endl;
	out << "===================== " << endl;
	out << "ID       : " << objeto.id << endl;
	out << "MARCA   : " << objeto.marca << endl;
	out << "MODELO     : " << objeto.modelo << endl;
	out << "PRECIO: " << objeto.precio << endl;
	out << "CANTIDAD  : " << objeto.cantidad << endl;
	return out;
}
istream& operator>>(istream& in, Celular& objeto)
{
	cout << "INGRESO DE DATOS DEL CELULAR: " << endl;
	cout << "================================ " << endl;
	cout << "ID       : "; in >> objeto.id; cin.ignore();
	cout << "MARCA   : "; cin.getline(objeto.marca, 30);
	cout << "MODELO     : "; cin.getline(objeto.modelo, 30);
	cout << "PRECIO: "; in >> objeto.precio; 
	cout << "CANTIDAD  : "; in >> objeto.cantidad;
	return in;
}
