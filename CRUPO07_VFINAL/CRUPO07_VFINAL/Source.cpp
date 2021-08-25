/************************************************************
NOMBRE     : Source.h*
************************************************************/
#include <iostream>
using namespace std;
#include "trabajoDatos.h"
#include "trabajoDatos.cpp"
#include "tractorista.h"
#include "cliente.h"
int main()
{
	float num1 = 2.5;

	Cliente Client1("Julio Ramirez");
	Cliente Client2("Lorenzo Moran");
	Tractorista Tract1("Lucas", 111);
	Tractorista Tract2("Rauo", 222);
	Jefe jefeDeAQPServisur("Yeffer");

	
	Client1.ingresarDatosDeServicio();
	jefeDeAQPServisur.informaTractorista(&Tract1);
	jefeDeAQPServisur.ingresarDatosSistema(&Client1, &Tract1);
	return 0;
}