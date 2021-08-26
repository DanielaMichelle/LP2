/************************************************************
NOMBRE     : libro.cpp*
AUTOR      : grupo*
FECHA      : 02/05/2021*
DESCRIPCION: Metodos de la Clase Libro
************************************************************/


#include "libro.h"
#include <iostream>
#include <string.h>
using namespace std;


Libro::Libro()
{
	title = "none";
	type = "none";
	editorial = "none";
	year = 0;
	nroCopias = 2;
}

Libro::~Libro()
{
	cout << "Destructor de clase Libro" << endl;
}

void Libro::ingresar()
{
	cout << "INGRESAR DATOS DEL LIBRO" << endl;
	cout << "=================================" << endl;
	cin.ignore();
	cout << "TITULO: "; 
	getline(cin, this->title);

	cout << "EDITORIAL: "; 
	getline(cin, this->editorial);

	cout << "TIPO: ";
	getline(cin, this->type);

	cout << "ANIO: "; 
	cin >> this->year;
	cin.ignore();
	cout << "=================================" << endl;
}

void Libro::imprimir()
{
	cout << "DATOS DEL LIBRO" << endl;
	cout << "=================================" << endl;
	cout << "TITULO: " << this->title << endl;
	cout << "EDITORIAL: " << this->editorial << endl;
	cout << "TIPO: " << this->type << endl;
	cout << "ANIO: " << this->year << endl;
	cout << "=================================" << endl;
}

string Libro::getTitle()
{
	return this->title;
}

int Libro::getNroCopias()
{
	return this->nroCopias;
}

Libro Libro::setNroCopias(int _nroCopias)
{
	this->nroCopias = _nroCopias;
	return *this;
}

string Libro::getType()
{
	return this->type;
}

string Libro::getEditorial()
{
	return this->editorial;
}

int Libro::GetYear()
{
	return this->year;
}

Libro Libro::setTitle(string _title)
{
	this->title = _title;
	return *this;
}

Libro Libro::setType(string _type)
{
	this->type = _type;
	return *this;
}
Libro Libro::setEditorial(string _editorial)
{
	this->editorial = _editorial;
	return *this;
}

Libro Libro::setYear(int _year)
{
	this->year = _year;
	return *this;
}
