/************************************************************
NOMBRE     : derivada.cpp*
AUTOR      : ingeniero*
FECHA      : 02/06/2021*
DESCRIPCION: Definicion de metodos de clase Derivada
************************************************************/
#include "derivada.h"
#include <iostream>
using namespace std;

// constructor de clase Derivada
// para pasar parametros a la clase base se hace esto,
// sino tuviera, no habria necesidad
Derivada::Derivada(int a, int b, int c, int d) :Base(a, b, c)
{
	cout << "Construccion Derivada" << endl;
	this->atributoPublic = d; // atributo public de Derivada
	this->atributoStatic++; 
	cout << atributoStatic << endl;
	cout << "=====================" << endl;

}
Derivada::~Derivada()
{
	cout << "Destruccion Derivada" << endl;
}

void Derivada::ejecutarProtegido()
{
	// ya que la herencia es publica, podemos usar
	// recursos protegifos de la clase Base
	Base::atributoProtected = 111;
	Base::metodoProtected();
	// atributo publi de clase Derivada
	cout << "AtributoPublic: " << this->atributoPublic<<endl;
	// Podemos usar atributos public de la clase Base
	cout << "Base::AtributoPublic: " << this->Base::atributoPublic << endl;
}
void Derivada::ejecutarPrivado()
{
	// metodo miembro protected de clase Base
	// con este podemos manipular el atributo
	// privado "atributoPrivate"
	Base::llamarPrivate();
	// Base::atributoPrivate = 112; es privado
	Base::atributoStatic = 4;
}

void Derivada::metodoAmigo(Base& unObjeto)
{
	// ya que la clase es amiga, si puede acceder a recursos
	// privados, no como en la herencia.
	cout << "metodoAmigo: " << endl;
	unObjeto.atributoPrivate = 222;
}

/*
void Derivada::metodoPublic()
{

}
*/