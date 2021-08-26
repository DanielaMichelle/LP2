/************************************************************
NOMBRE     : base.cpp*
AUTOR      : ingeniero*
FECHA      : 02/06/2021*
DESCRIPCION: Definicion de metodos de clase Base
************************************************************/
#include "base.h"
#include <iostream>
using namespace std;

// constructor de clase Base
Base::Base(int a, int b, int c)
{
    cout << "Construccion Base" << endl;
    atributoPublic = a;
    this->atributoPrivate = b;
    this->atributoProtected = c;
    cout << atributoStatic << endl;
    cout << "=========================" << endl;
}

// destructor de la clase
Base::~Base()
{
    cout << "Destruccion Base" << endl;
}

int Base::metodoPublic()
{
    atributoPublic = 11;
    return atributoPublic;
}
int Base::metodoProtected()
{
    atributoProtected = 12;
    return atributoProtected;
}
int Base::metodoPrivate()
{
    atributoPrivate = 13;
    return 0;
}
int Base::mostrarProtected()
{
    // este metodo le permite a una clase derivada
    // manipular (imprimir), un atributo privado
    // al no poder hacerlo directamente
    cout << "Datos clase base" << endl;
    cout << "================" << endl;
    cout << "AtributoPublic: " << atributoPublic << endl;
    cout << "AtributoProtected: " << atributoProtected << endl;
    cout << "AtributoPrivate: " << atributoPrivate << endl;
    cout << "================" << endl;
    return 0;
}
int Base::mostrarPublic()
{
    cout << "Datos clase base" << endl;
    cout << "================" << endl;
    cout << "AtributoPublic: " << atributoPublic << endl;
    cout << "AtributoProtected: " << atributoProtected << endl;
    cout << "AtributoPrivate: " << atributoPrivate << endl;
    cout << "================" << endl;
    return 0;
}
void Base::llamarPrivate()
{
    atributoPrivate = 22;
    cout << "AtributoPrivate: " << atributoPrivate << endl;
    metodoPrivate();
}
