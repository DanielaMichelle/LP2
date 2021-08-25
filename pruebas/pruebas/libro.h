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

	char title[30];
	char autor[20];
	int codigo;
	int nroCopias;
public:
	Libro(int = 0, string = "", string = "", int = 0);

	string getTitle();
	int getNroCopias();
	string getAutor();
	int getCodigo();

	Libro setNroCopias(int);
	Libro setTitle(string);
	Libro setAutor(string);
	Libro setCodigo(int);
};


