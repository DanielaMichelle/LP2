/************************************************************
NOMBRE     : cliente.cpp*
************************************************************/
#include "cliente.h"

Cliente::Cliente(string name)
{
	nombre = name;
}

void Cliente::ingresarDatosDeServicio()
{
	cout << "======== INGRESAR DATOS DE TRABAJO ========" << endl;
	cout << "TIPO DE TRABAJO: "; cin >> trabajo;
	cout << "DIRECCION DE PARCELA: "; cin >> direccionP;
	cout << "TAMANIO DE PARCELA POR TOPOS: "; cin >> sizeP;
	cout << "==========================================" << endl;
}

string Cliente::getNombre()
{
	return nombre;
}
string Cliente::getTrabajoTipo()
{
	return trabajo;
}
string Cliente::getdirParcela()
{
	return direccionP;
}
int Cliente::getSizeP()
{
	return sizeP;
}