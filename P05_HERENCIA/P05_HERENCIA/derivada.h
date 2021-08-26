/************************************************************
NOMBRE     : derivada.h*
AUTOR      : ingeniero*
FECHA      : 02/06/2021*
DESCRIPCION: Clase Derivada
************************************************************/
#pragma once
#include "base.h"

// la clase Derivada hereda los recursos de la clase Base
class Derivada :
    public Base   // tipo de herencia public
{                    
public:
    // recursos public
    void metodoAmigo(Base&);  // esto porque la clase Derivada tambien es clase amiga de Base
    Derivada(int, int, int, int);
    ~Derivada();
    int atributoPublic;
protected:
    // recursos protected
     void ejecutarProtegido();
private: 
    // recursos private
     void ejecutarPrivado();
   
};