/************************************************************
NOMBRE     : tractorista.h*
************************************************************/
#pragma once
#include <iostream>
using namespace std;
#include "jefe.h"

class Tractorista
{
private:
	int codigo;
	string nombre;
public:
	Tractorista(string _name, int _code);
	void trabajar();
	friend class Jefe;
	string getNombre();
};

