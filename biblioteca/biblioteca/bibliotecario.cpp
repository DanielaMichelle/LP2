/************************************************************
NOMBRE     : biblioteca.cpp*
AUTOR      : grupo*
FECHA      : 02/05/2021*
DESCRIPCION: Metodos de la Clase Biblioteca
************************************************************/

#include "bibliotecario.h"
#include <iostream>
#include <string.h>
using namespace std;

Bibliotecario::Bibliotecario(User* user)
{
	name = " ";
	codigo = 0;
	usuario = user;
}

Bibliotecario::~Bibliotecario()
{
	cout << "Destructor de clase Bibliotecario" << endl;
}

Bibliotecario Bibliotecario::pedirDatos()
{

	usuario->ingresar();
	cout << "FECHA DE ENTREGA: ";
	fechaEntrega.ingresar();
	cout << "REGRESAR ANTES DE: ";
	fechaRegreso.ingresar();
	system("pause");
	system("cls");
	return *this;
}

void Bibliotecario::imprimirRecibo()
{
	cout << "=====================================" << endl;
	cout << "RECIBO DE USUARIO" << endl;
	cout << "=====================================" << endl;
	usuario->imprimir();
	cout << "FECHA DE ENTREGA: "; fechaEntrega.imprimirFecha();
	cout << "REGRESAR ANTES DE: "; fechaRegreso.imprimirFecha();
	cout << "=====================================" << endl;
}

Bibliotecario Bibliotecario::setName(string _name)
{
	this->name = _name;
	return *this;
}

Bibliotecario Bibliotecario::setCodigo(int _codigo)
{
	this->codigo = _codigo;
	return *this;
}

string Bibliotecario::getName()
{
	return this->name;
}

int Bibliotecario::getCodigo()
{
	return this->codigo;
}