/************************************************************
NOMBRE     : tractorista.cpp*
************************************************************/
#include "tractorista.h"

Tractorista::Tractorista(string _name, int _code)
{
	nombre = _name;
	codigo = _code;
}

void Tractorista::trabajar()
{
	cout << "Ir a trabajar a la Parcela" << endl;
}

string Tractorista::getNombre()
{
	return nombre;
}