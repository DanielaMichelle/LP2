#pragma once
#include "libro.h"
#include <iostream>
/************************************************************
NOMBRE     : user.h*
AUTOR      : grupo*
FECHA      : 02/05/2021*
DESCRIPCION: Clase User
************************************************************/

#include <string.h>
using namespace std;

class User
{
	string name;
	int telefono;
	string direccion;
	string pedido;
	// Referencia
	string& refNombrePedido;
public:
	User(string);
	~User();
	bool VerificarAccesibilidadLibro(Libro*);
	void pedirLibro(Libro*);
	void regresarLibro(Libro*);
	void ingresar();
	void imprimir();

	string getName();
	int getTelefono();
	string getDireccion();
	string getPedido();

	User setName(string);
	User setTelefono(int);
	User setDireccion(string);
	User setPedido(string);

};

