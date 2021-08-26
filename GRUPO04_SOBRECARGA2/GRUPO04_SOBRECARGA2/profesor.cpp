#include <iostream>
#include <string>
using namespace std;
#include "profesor.h"
#include "curso.h"
#include "alumno.h"// incluimos a la clase anfitriona

Profesor::Profesor()
{
	nombre = " ";
	codigo = 0;
	curso = " ";
}

// método de clase amiga Alumno
void Profesor::ponerNota(Alumno& unAlumno, string nombreCursoProfesor)
{
	int nota = 0;
	// la clase amiga tiene acceso a miembros
	// privados, públicos y protegidos de la clase anfitriona
	cout << "Alumno : " << unAlumno.nombre << endl;
	for (int i = 0; i < unAlumno.cantCursos; i++)
	{
		if (unAlumno.listaCurso[i].getNombre() == nombreCursoProfesor)
		{
			cout << "Nota : "; cin >> nota;
			unAlumno.listaCurso[i].setNota(nota);
		}
	}
} // fin de función amiga setAtributos

int Profesor::getCodigo()
{
	return this->codigo;
}
string Profesor::getNombre()
{
	return this->nombre;
}
string Profesor::getCurso()
{
	return this->curso;
}
void Profesor::setCurso(string _curso)
{
	curso = _curso;
}
void Profesor::setCodigo(int _codigo)
{
	codigo = _codigo;
}
void Profesor::setNombre(string _nombre)
{
	nombre = _nombre;
}


void Profesor::ingresar()
{
	cin.ignore();
	cout << "================ PROFESOR, INGRESE DATOS AL SISTEMA ===============" << endl;
	cout << "Nombre : "; getline(cin, nombre);
	cout << "Codigo : "; cin >> codigo;
	cin.ignore();
	cout << "Curso : "; getline(cin, curso);
	cout << "==========================================================" << endl;
}

void Profesor::imprimir()
{
	cout << "================  DATOS DEL PROFESOR ===============" << endl;
	cout << "Nombre : " << nombre << endl;
	cout << "Codigo : " << codigo << endl;
	cout << "Curso : " << curso << endl;
	cout << "==========================================================" << endl;
}