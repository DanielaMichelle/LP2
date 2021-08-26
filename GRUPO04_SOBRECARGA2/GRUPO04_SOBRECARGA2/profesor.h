#pragma once
#include <iostream>
#include "curso.h"
using namespace std;
#include "alumno.h"
class Alumno;

class Profesor // es CLASE AMIGA de Alumno
{
private:
	int codigo;
	string curso;
protected:
	string nombre;
public:
	Profesor();
	int getCodigo();
	string getNombre();
	string getCurso();
	void setCurso(string);
	void setCodigo(int);
	void setNombre(string);
	void ingresar();
	void imprimir();

	//////////MÉTODO USADO EN LA AMISTAD///////
	// métodos que usan recursos de Alumno 
	// estos metodos reciben como valor de parametro 
	// un objeto tipo Alumno.
	void ponerNota(Alumno&, string);
	//////////fin de métodos usados en la amistad///////

};


