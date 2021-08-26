/* ##################################################################################
																					#
 Autor:Grupo 5																		#
Fecha: 02/06/2021																	#
descripcion: archivo h para la construccion de la clase             				#
																					#
#####################################################################################
*/
#pragma once
#include <string>
using namespace std;
class persona
{
	//atributo protegido
	string nombre;
	int edad;
public:
	//metodo publico
	persona();//constructor
	void mostrar();
	void ingresar();
	~persona();//destructor
protected:
	//atributo protegido
	int DNI;
};

