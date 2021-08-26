#include "copia.h"
#include <iostream>
#include <string>
using namespace std;

Copia::Copia()
{
	id = 0;
	estado = "none";
}

Copia::~Copia()
{

}

int Copia::getId()
{
	return this->id;
}

string Copia::getEstado()
{
	return this->estado;
}

Copia Copia::setId(int _id)
{
	this->id = _id;
	return *this;
}

Copia Copia::setEstado(string _estado)
{
	this->estado = _estado;
	return *this;
}