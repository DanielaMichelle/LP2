/************************************************************
NOMBRE     : libro.h*
AUTOR      : grupo*
FECHA      : 02/05/2021*
DESCRIPCION: Clase Libro
************************************************************/

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Libro
{
private: 
	string title;
	string type;
	string editorial;
	int year;
	int nroCopias;
public:
	Libro();
	~Libro();
	void ingresar();
	void imprimir();
	string getTitle();
	int getNroCopias();
	string getType();
	string getEditorial();
	int GetYear();


	Libro setNroCopias(int);
	Libro setTitle(string);
	Libro setType(string);
	Libro setEditorial(string);
	Libro setYear(int);
	
};

