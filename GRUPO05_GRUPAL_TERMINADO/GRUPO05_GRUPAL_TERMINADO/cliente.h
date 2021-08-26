/* ##################################################################################
                                                                                    #
 Autor:Grupo 5																		#
Fecha: 02/06/2021																	#
descripcion: archivo h para la construccion de la clase             				#
                                                                                    #
#####################################################################################
*/
#pragma once
#include "persona.h"

class cliente :
    private persona //herencia privada
{
    //atributos privados
    string nombre_empresa;
    int telefono_de_contacto;
public:
    //metodos publicos
    cliente();//constructor
    void mostrar();
    void ingresar();
    ~cliente(); //destructor

};

