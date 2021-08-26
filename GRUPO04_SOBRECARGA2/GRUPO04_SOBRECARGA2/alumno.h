#pragma once
#include <iostream>
using namespace std;
#include "curso.h"
#include "profesor.h" // -> clase amiga

// Declaración de clase UnaClase
class Alumno // clase anfitriona de Profesor
{
private:
	int codigo;
	int cantCursos;
	////////// ATRIBUTO STATIC ////
	static string colegioNombre;
protected:
	string nombre;
public:
	Alumno();
	friend class Profesor; // declaración de clase amiga o invitada
	void registrarse();
	void imprimir();
	int getCodigo();
	int getCantCursos();
	string getNombre();
	void setCodigo(int);
	void setNombre(string);
	Curso listaCurso[10];
	void obtenerPromedio();

	///////////// FUNCIONES AMIGAS ////////////////
	// no son miembros de la clase Alumno
	// pero si se declaran aqui, con el keyword friend.
	friend bool getNamesCursos(Alumno& unObjeto, string unObjeto_nombre); // función amiga
	///////////// fin de funciones amigas/////////

	/////////////// METODO STATIC ////////////
	// Por si el colegio cambia de nombre
	static void setNombreColegio(string _nuevoNombre);
};




