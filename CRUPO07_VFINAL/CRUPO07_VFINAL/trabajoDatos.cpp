/************************************************************
NOMBRE     : travajoDatos.cpp*
************************************************************/
#include "trabajoDatos.h"

template <typename TipoDato>
trabajoDatos<TipoDato>::trabajoDatos(string nC, string nT,
	string tipoT, string _dirParcela, int _size, TipoDato _horas)
{
	nombreCliente = nC;
	nombreTractorista = nT;
	tipoTrabajo = tipoT;
	tamanio = _size;
	dirParcela = _dirParcela;
	horasTrabajo = _horas;
}

template <typename TipoDato>
void trabajoDatos<TipoDato>::printDatosTrabajo()
{
	cout << "============= DATOS DEL TRABAJO ============" << endl;
	cout << "NOMBRE DE CLIENTE: " << this->nombreCliente << endl;
	cout << "TIPO DE TRABAJO: " << this->tipoTrabajo << endl;
	cout << "DIRECCION DE PARCELA: " << this->dirParcela << endl;
	cout << "TAMANIO DE PARCELA: " << this->dirParcela << endl;
	cout << "HORAS DE TRABAJO: " << this->horasTrabajo << endl;
	cout << "=============================================" << endl;
}