/************************************************************
NOMBRE     : Source.cpp*
AUTOR      : ingeniero*
FECHA      : 02/06/2021*
DESCRIPCION: Uso de Herencia
************************************************************/
/*
#include "derivada.h"
#include "base.h"
#include <iostream>
using namespace std;

//int Base::atributoStatic=100;
int Derivada::atributoStatic = 10;

int main()
{
	Base objetoBase(99,88,77);
	Derivada objetoDerivada(11, 12, 13, 1111);
	
	// no podemos usar el atributo static desde Derivada desde aqui, por que la herencia es protected
	// cout << "Derivada::atributoStatic: " << Derivada::atributoStatic << endl;
	//Derivada::atributoStatic = Derivada::atributoStatic + 1;

	cout << "Base::atributoStatic: " << Base::atributoStatic << endl;
	// cout << "Derivada::atributoStatic: " << Derivada::atributoStatic << endl;

	objetoBase.atributoPublic = 1002;
	objetoDerivada.metodoAmigo(objetoBase); // recibe un objeto tipo Base

	// no se puede usar ya que la herencia de Derivada es protected
	// entonces no podemos usar los metodos de la clase padre en funciones no miembro.
	// objetoDerivada.mostrarPublic();

	cout << "objetoDerivada.AtributoPublic: " << objetoDerivada.atributoPublic << endl;

	objetoDerivada.atributoPublic = 21;
	// herencia protected: no podemos usar los metodos de la clase padre en funciones no miembro.
	// cout << "Base::AtributoPublic: " << objetoDerivada.Base::atributoPublic << endl;
	// objetoDerivada.Base::atributoPublic = 2003;
	// cout << "Base::AtributoPublic: " << objetoDerivada.Base::atributoPublic << endl;
	/*
	objetoDerivada.Base::atributoPublic = 121;
	cout << objetoDerivada.metodoPublic()<<endl;
	objetoDerivada.mostrarPublic();
	objetoDerivada.ejecutarProtegido();
	objetoDerivada.ejecutarPrivado();
	objetoDerivada.mostrarPublic();
	
	return 0;

}
*/