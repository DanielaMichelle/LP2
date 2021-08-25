/************************************************************
NOMBRE     : jefe.cpp*
************************************************************/
#include "jefe.h"
#include "trabajoDatos.h"
#include "trabajoDatos.cpp"

Jefe::Jefe(string _nombre)
{
	nombre = _nombre;
}
void Jefe::informaTractorista(Tractorista* objT)
{
	cout << "Informando a Tractorista...";
	objT->trabajar();
}

void Jefe::ingresarDatosSistema(Cliente* Client1, Tractorista* Tract1)
{
	string nombreC = Client1->getNombre(), nombreT = Tract1->getNombre(),
		tipoTrab = Client1->getTrabajoTipo(), dirP = Client1->getdirParcela();
	int size = Client1->getSizeP();
	int cantTrabajos = 4;
	if (tipoTrab == "borrado")
	{
		float hora = 3.5;
		trabajoDatos<float> nameFil(nombreC, nombreT, tipoTrab, dirP, size, hora);
	}
	else if (tipoTrab == "sursulado")
	{
		int hora = 2;
		trabajoDatos<float> nameFil(nombreC, nombreT, tipoTrab, dirP, size, hora);
	}
	else if (tipoTrab == "surco")
	{
		float hora = 4.5;
		trabajoDatos<float> nameFil(nombreC, nombreT, tipoTrab, dirP, size, hora);
	}
	else if (tipoTrab == "plastificado")
	{
		int hora = 3;
		trabajoDatos<float> nameFil(nombreC, nombreT, tipoTrab, dirP, size, hora);
	}
}