#include "alumno.h"
#include "curso.h"
#include <iostream>
#include <string>
using namespace std;

Alumno::Alumno()
{
	codigo = 0;
	nombre = " ";
	cantCursos = 0;
}



void Alumno::registrarse()
{
	string nombreCurso;
	cout << "/////////////// REGISTRATE /////////////" << endl;
	cout << "Nombre: "; getline(cin, nombre);
	cout << "Codigo: "; cin >> codigo;
	cout << "Cantidad de Cursos: "; cin >> cantCursos;
	cin.ignore();
	for (int i = 0; i < cantCursos; i++)
	{
		cout << "Nombre del Curso : "; getline(cin, nombreCurso);
		listaCurso[i].setNombre(nombreCurso);
	}
	cout << "/////////////// ////////// /////////////" << endl;
}
void Alumno::imprimir()
{
	cout << "/////////////// DATOS DE ESTUDIANTE /////////////" << endl;
	cout << "Colegio : " << colegioNombre << endl;
	cout << "Nombre : " << nombre << endl;
	cout << "Codigo : " << codigo << endl;
	cout << "CURSOS " << endl;
	for (int i = 0; i < cantCursos; i++)
	{
		cout << "Nombre del Curso :" << listaCurso[i].getNombre() << endl;
	}
	cout << "/////////////// ////////////////// /////////////" << endl;
}

//////////////// RECURSO ESTATIC /////////////
void Alumno::setNombreColegio(string _nuevoNombre)
{
	colegioNombre = _nuevoNombre;
}

///// usando sobrecarga //
void Alumno::obtenerPromedio()
{
	for (int i = 1; i < cantCursos; i++)
	{
		// uso de SOBRECARGA con el operador +
		listaCurso[0] + listaCurso[i];
	}
	int total = listaCurso[0].getNota();
	cout << "Promedio General de " << nombre << " : " << total / cantCursos << endl;
}



int Alumno::getCantCursos()
{
	return cantCursos;
}

int Alumno::getCodigo()
{
	return this->codigo;
}
string Alumno::getNombre()
{
	return this->nombre;
}
void Alumno::setCodigo(int _codigo)
{
	codigo = _codigo;
}
void Alumno::setNombre(string _nombre)
{
	nombre = _nombre;
}