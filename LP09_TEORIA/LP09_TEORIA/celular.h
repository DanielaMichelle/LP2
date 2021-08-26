#pragma once
#include <iostream>
using namespace std;

class Celular
{
public:
	friend ostream& operator<<(ostream&, Celular&);
	friend istream& operator>>(istream&, Celular&);
public:
	int id;
	char marca[30];
	char modelo[30];
	float precio;
	int cantidad;
};

