/************************************************************
NOMBRE     : travajoDatos.h*
************************************************************/
#pragma once
#include <iostream>
using namespace std;

template <typename TipoDato>
class trabajoDatos
{
private:
	string nombreCliente;
	string nombreTractorista;
	string tipoTrabajo;
	TipoDato horasTrabajo;
	string dirParcela;
	int tamanio;
public:
	trabajoDatos(string nC, string nT, string tipoT,
		string dirParcela, int _size, TipoDato _horas);
	void printDatosTrabajo();
};

