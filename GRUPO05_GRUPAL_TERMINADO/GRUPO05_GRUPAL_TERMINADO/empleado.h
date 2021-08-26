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
class empleado :
    public persona //herencia publica
{
    //atributos privados
    float sueldo_bruto;
    float saldo_neto;
public:
    //metodos publicos
    empleado();//constructor
    void mostrar();
    void ingresar();
    void calcular_salario_neto();
    ~empleado();//destructor
protected:
    //atributo protegido
    int codigo;
};


