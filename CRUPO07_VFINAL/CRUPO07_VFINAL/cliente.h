/************************************************************
NOMBRE     : cliente.h*
************************************************************/
#pragma once
#include <iostream>
using namespace std;

class Cliente
{
private:
	string nombre;
	string trabajo;
	string direccionP;
	int sizeP;
public:
	Cliente(string name);
	void ingresarDatosDeServicio();
	string getNombre();
	string getTrabajoTipo();
	string getdirParcela();
	int getSizeP();
};

