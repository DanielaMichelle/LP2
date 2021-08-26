/************************************************************
NOMBRE     : fecha.cpp*
AUTOR      : grupo*
FECHA      : 02/05/2021*
DESCRIPCION: Metodos de la Clase Fecha
************************************************************/

#include "fecha.h"
#include <iostream>
#include <string.h>
using namespace std;


Fecha::Fecha()     
{
	day = 0;
	month = 0;
	year = 0;
}

Fecha Fecha::setDay(int _day)
{
	this->day = _day;
	return *this;
}

Fecha Fecha::setMonth(int _month)
{
	this->month = _month;
	return *this;
}

Fecha Fecha::setYear(int _year)
{
	this->year = _year;
	return *this;
}

void Fecha::ingresar()
{
	cout << endl;
	cout << "DIA    : "; cin >> this->day;
	cout << "MES    : "; cin >> this->month;
	cout << "AÑO    : "; cin >> this->year;
}

void Fecha::imprimirFecha()
{
	cout << this->day << "/" << this->month << "/" << this->year << endl;
}

int Fecha::getDay()
{
	return this->day;
}

int Fecha::getMonth()
{
	return this->month;
}

int Fecha::getYear()
{
	return this->year;
}