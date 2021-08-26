/************************************************************
NOMBRE     : base.h*
AUTOR      : ingeniero*
FECHA      : 02/06/2021*
DESCRIPCION: Clase base
************************************************************/
#pragma once
class Base
{
    // recursos public
public:
    Base(int, int, int);
    int atributoPublic;
    int metodoPublic();
    int mostrarPublic();
    int static atributoStatic; // atributo static
    friend class Derivada;     // clase amiga
    ~Base();
    // recursos protected
protected:
    int atributoProtected;
    int metodoProtected();
    int mostrarProtected();
    void llamarPrivate();
    // recursos private
private:
    int atributoPrivate;
    int metodoPrivate();
};