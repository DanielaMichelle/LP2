/************************************************************
NOMBRE     : user.cpp*
AUTOR      : grupo*
FECHA      : 02/05/2021*
DESCRIPCION: Metodos de la Clase User
************************************************************/
#include "user.h"
#include "libro.h"
#include <iostream>
#include <string.h>
using namespace std;

// inicializo referencia
User::User(string n) : refNombrePedido(this->pedido)
{
	name = " ";
	telefono = 0;
	direccion = " ";
	pedido = n;
}

User::~User()
{
	cout << "Destructor de clase User" << endl;
}

void User::ingresar()
{
	cout << "=====================================" << endl;
	cout << "INGRESAR DATOS DE USUARIO" << endl;
	cout << "=====================================" << endl;
	cout << "NOMBRE: "; getline(cin, this->name);
	cout << "DIRECCION: "; getline(cin, this->direccion);
	cout << "TELEFONO: "; cin >> this->telefono;
	cin.ignore();
}

void User::imprimir()
{
	cout << "NOMBRE: " << this->name << endl;
	cout << "DIRECCION: " << this->direccion << endl;
	cout << "TELEFONO: " << this->telefono << endl;
	cout << "NOMBRE DEL LIBRO: " << this->refNombrePedido << endl;
	cin.ignore();
}



bool User::VerificarAccesibilidadLibro(Libro* list)
{
	int contador = 0;
	for (int i = 0; i < 2; i++)
	{
		if (list[i].getTitle() == refNombrePedido)
		{
			if (list[i].getNroCopias() > 0)
			{
				cout << "El libro esta disponible" << endl;
				contador++;
				return true;
			}
		}
	};

	if (contador == 0)
	{
		cout << "El libro no esta disponible" << endl;
		return false;
	};
}

void User::pedirLibro(Libro* list)
{
	int numCopies = 0;
	for (int i = 0; i < 2; i++)
	{
		if (list[i].getTitle() == refNombrePedido)
		{
			// disminuimos cantidad de copias del registro
			numCopies = list[i].getNroCopias();
			list[i].setNroCopias(numCopies - 1);
		}
	}
	cout << "El libro se agrego a tu pedido" << endl;
}

void User::regresarLibro(Libro* list)
{
	int numCopies = 0;
	for (int i = 0; i < 2; i++)
	{
		if (list[i].getTitle() == refNombrePedido)
		{
			// aumentamos cantidad de copias del registro
			numCopies = list[i].getNroCopias();
			list[i].setNroCopias(numCopies + 1);
		}
	}
	cout << "=========================" << endl;
	cout << "EL LIBRO FUE DEVUELTO" << endl;
	cout << "=========================" << endl;
}


string User::getName()
{
	return this->name;
}

int User::getTelefono()
{
	return this->telefono;
}

string User::getDireccion()
{
	return this->direccion;
}

string User::getPedido()
{
	return this->pedido;
}

User User::setName(string _name)
{
	this->name = _name;
	return *this;
}

User User::setTelefono(int _telefono)
{
	this->telefono = _telefono;
	return *this;
}

User User::setDireccion(string _direccion)
{
	this->direccion = _direccion;
	return *this;
}

User User::setPedido(string _pedido)
{
	this->pedido = _pedido;
	return *this;
}