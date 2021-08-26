#pragma once
#include "curso.h"
#include <iostream>
using namespace std;

class Curso
{
private:
	string nombre;
	int nota;
public:
	Curso();
	// sobrecarga operador +
	Curso& operator+(const Curso&);
	void setNombre(string);
	string getNombre();
	void setNota(int);
	int getNota();
};




