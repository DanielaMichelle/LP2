/************************************************************
NOMBRE     : ejecutar01.cpp*
AUTOR      : grupo*
FECHA      : 02/05/2021*
DESCRIPCION: Programa de biblioteca
************************************************************/


#pragma warning(disable:4996)
#include "libro.h"
#include "user.h"
#include "bibliotecario.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// ============================== PARTE REGISTRO ================================== //
	int cantidad = 2;
	FILE* registroLibros;
	registroLibros = fopen("libros.dat", "wb");

	Libro* listaLibros;
	listaLibros = new Libro[cantidad];
	for (int i = 0; i < cantidad; i++)
		listaLibros[i].ingresar();

	for (int i = 0; i < cantidad; i++)
		fwrite(&listaLibros[i], sizeof(Libro), 1, registroLibros);

	
	// ============================== FIN PARTE REGISTRO ================================== //

	// ============================== PARTE DE USER ================================== //
	
	string nombreL;
	bool verificacion;

	cout << "=================================" << endl;
	cout << "INGRESA NOMBRE DEL LIBRO: ";
	getline(cin, nombreL);
	cout << "=================================" << endl;
	

	User Juanjo(nombreL);
	// usuario verifica la exitencia del libro
	verificacion = Juanjo.VerificarAccesibilidadLibro(listaLibros);
	if (verificacion)
	{
		//usuario pide el libro
		Juanjo.pedirLibro(listaLibros);
		Bibliotecario bibliotecarioRamon(&Juanjo);
		bibliotecarioRamon.pedirDatos().imprimirRecibo();
	}	 

	// usuario regresa libro
	Juanjo.regresarLibro(listaLibros);
	
	// ============================== FIN PARTE DE USER ================================== //

	return 0;
}

