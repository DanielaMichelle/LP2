/* ##################################################################################
                                                                                    #
 Autor:Grupo 5																		#
Fecha: 02/06/2021																	#
descripcion: archivo h para la construccion de la clase             				#
                                                                                    #
#####################################################################################
*/
#pragma once
#include "empleado.h"
class directivo :
    protected empleado //herencia protegida
{
    //atributo privado
    string categoria;
public:
    //metodos publicos
    directivo(); //constructor
    void mostrar();
    void ingresar();
    ~directivo(); //destructor


};

