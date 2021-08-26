#include "curso.h"
Curso::Curso()
{
	nombre = " ";
	//nota = 0;
}

// Sobrecarga de operador +
Curso& Curso::operator+(const Curso& Cursoobj)
{
	nota = nota + Cursoobj.nota;
	return *this;
}

void Curso::setNombre(string _nombre)
{
	nombre = _nombre;
}

string Curso::getNombre()
{
	return nombre;
}

void Curso::setNota(int _nota)
{
	nota = _nota;
}

int Curso::getNota()
{
	return this->nota;
}