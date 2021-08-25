#pragma once
#include <iostream>
#include"tractorista.h"
#include "cliente.h"


/************************************************************
NOMBRE     : jefe.h*
************************************************************/
class Tractorista;
using namespace std;
class Jefe
{
private:
	string nombre;
public:
	Jefe(string _nombre);
	void informaTractorista(Tractorista*);
	void ingresarDatosSistema(Cliente*, Tractorista*);
};

