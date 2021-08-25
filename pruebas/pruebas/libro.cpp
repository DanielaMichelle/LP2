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


Libro::Libro(int _code, string _title, string _autor, int _nC)
{
	setTitle(_title);
	setAutor(_autor);
	setCodigo(_code);
	setNroCopias(_nC);
}

/*
Libro::~Libro()
{
	cout << "Destructor de clase Libro" << endl;
}

void Libro::ingresar()
{
	string titl, edit, tipo;
	int anio;
	cout << "INGRESAR DATOS DEL LIBRO" << endl;
	cout << "=================================" << endl;

	cout << "CODIGO DEL LIBRO: ";
	cin >> this->codigo;

	cout << "TITULO: ";
	cin.getline(this->title, 30);
	cin.ignore();

	cout << "AUTOR: ";
	cin.getline(this->autor, 20);
	cin.ignore();

	cout << "NRO DE COPIAS: ";
	cin >> this->nroCopias;
	cin.ignore();
	cout << "=================================" << endl;
}


void Libro::imprimir()
{
	cout << "DATOS DEL LIBRO" << endl;
	cout << "=================================" << endl;
	cout << "CODIGO: " << this->codigo << endl;
	cout << "TITULO: " << this->title << endl;
	cout << "AUTOR: " << this->autor << endl;
	cout << "NUMERO DE COPIAS: " << this->nroCopias << endl;
	cout << "=================================" << endl;
}
*/

// no hay problema es retornar un string
// ya que un arreglo se puede 
// convertir implicitamente en un string.
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

string Libro::getAutor()
{
	return this->autor;
}

int Libro::getCodigo()
{
	return this->codigo;
}

Libro Libro::setTitle(string _title)
{
	// data(); convierte string a arreglo
	const char* valorTitulo = _title.data();
	int longitud = _title.size();
	//longitud = (longitud < 30 ? longitud : 29);
	longitud = (longitud < 30 ? longitud : 29);

	strncpy_s(title, valorTitulo, longitud);
	title[longitud] = '\0'; // caracter nulo
	return *this;
}

Libro Libro::setAutor(string _autor)
{
	const char* valorEdit = _autor.data();
	int longitud = _autor.size();
	longitud = (longitud < 20 ? longitud : 19);
	strncpy_s(autor, valorEdit, longitud);
	autor[longitud] = '\0';
	return *this;
}

Libro Libro::setCodigo(int _code)
{
	this->codigo = _code;
	return *this;
}