/************************************************************
NOMBRE     : Source.cpp*
AUTOR      : ingeniero*
FECHA      : 02/06/2021*
DESCRIPCION: Uso de Herencia public
************************************************************/
#include "derivada.h"
#include "base.h"
#include <iostream>
using namespace std;

//int Base::atributoStatic=100;
int Derivada::atributoStatic = 10;

int main()
{
	Base objetoBase(99, 88, 77);
	Derivada objetoDerivada(11, 12, 13, 1111);

	// Podemos usar atributo static por que la  herencia es public
	cout << "Derivada::atributoStatic: " << Derivada::atributoStatic << endl;
	Derivada::atributoStatic = Derivada::atributoStatic + 1;

	cout << "Base::atributoStatic: " << Base::atributoStatic << endl;
	cout << "Derivada::atributoStatic: " << Derivada::atributoStatic << endl;

	objetoBase.atributoPublic = 1002;
	objetoDerivada.metodoAmigo(objetoDerivada); // recibe un objeto tipo base

	// Ya que la herencia es public, podemos usar metodos protected y public de 
	// la clase Base en metodos no miembros de esta.
    objetoDerivada.mostrarPublic();

	cout << "objetoDerivada.AtributoPublic: " << objetoDerivada.atributoPublic << endl;

	objetoDerivada.atributoPublic = 21;
	cout << "Base::AtributoPublic: " << objetoDerivada.Base::atributoPublic << endl;
	objetoDerivada.Base::atributoPublic = 2003;
    cout << "Base::AtributoPublic: " << objetoDerivada.Base::atributoPublic << endl;
	

	objetoDerivada.Base::atributoPublic = 121;
	cout << objetoDerivada.metodoPublic()<<endl;
	objetoDerivada.mostrarPublic();

	// no se puede usar recursos protected ni private de una clase cualquiera,
	// desde una funcion externa, como main.
	// objetoDerivada.ejecutarProtegido();
	// objetoDerivada.ejecutarPrivado();

	objetoDerivada.mostrarPublic();
	
	return 0;
}