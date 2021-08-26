/************************************************************
NOMBRE     : fecha.h*
AUTOR      : grupo*
FECHA      : 02/05/2021*
DESCRIPCION: Clase Fecha
************************************************************/

#pragma once
class Fecha
{
	int day;
	int month;
	int year;
public:
	Fecha();
	Fecha setDay(int);
	Fecha setMonth(int);
	Fecha setYear(int);
	int getMonth();
	int getYear();
	int getDay();
	void imprimirFecha();
	void ingresar();	
};

