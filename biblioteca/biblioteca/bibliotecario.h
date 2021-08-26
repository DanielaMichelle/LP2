/************************************************************
NOMBRE     : biblioteca.h*
AUTOR      : grupo*
FECHA      : 02/05/2021*
DESCRIPCION: Clase Biblioteca
************************************************************/

#pragma once
#include <iostream>
#include <string.h>
#include "user.h"
#include "fecha.h"
using namespace std;

class Bibliotecario
{
	string name;
	int codigo;
	User* usuario;
	Fecha fechaEntrega;
	Fecha fechaRegreso;
public:
	Bibliotecario(User*);
	~Bibliotecario();
	Bibliotecario pedirDatos();
	void imprimirRecibo();

	Bibliotecario setName(string);
	Bibliotecario setCodigo(int);
	string getName();
	int getCodigo();
};

