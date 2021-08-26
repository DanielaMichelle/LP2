/* ##################################################################################
																					#
 Autor:Grupo 5																		#
Fecha: 02/06/2021																	#
descripcion: archivo cpp qprinciplar que contiene todo el programa en uso			#
																					#
#####################################################################################
*/


#pragma warning (disable:4996)
#include "persona.h"
#include "empleado.h"
#include "directivo.h"
#include "cliente.h"
#include <string>
#include <iostream>
using namespace std;

int main() {

	string confir = "si", consul;
	int cant1, cant_1, cant2, cant3, cant4, caso;
	cout << "********************* marvisur ***********************" << endl;
	cout << "cuantas turistas ingresaran a nuestro registro:"; cin >> cant1;
	cout << "cuantas empleados ingresaran a nuestro registro:"; cin >> cant2;
	cout << "cuantas directivos ingresaran a nuestro registro:"; cin >> cant3;
	cout << "cuantas cliente ingresaran a nuestro registro:"; cin >> cant4;

	//arreglos dinamicos de objetos con punteros
	persona* arr, * arr_;
	arr = new persona[cant1];
	FILE* archivo_persona;
	archivo_persona = fopen("archivo1.txt", "wb"); //creacion de archivos
	for (int i = 0; i < cant1; i++) {
		arr[i].ingresar();
	}
	for (int i = 0; i < cant1; i++) {
		fwrite(&arr[i], sizeof(persona), 1, archivo_persona); //escritura de archivos
	}
	system("cls");
	empleado* arr1, * arr_1;
	arr1 = new empleado[cant2];
	FILE* archivo_empleado;
	archivo_empleado = fopen("archivo2.txt", "wb");
	for (int i = 0; i < cant2; i++) {
		arr1[i].ingresar();
	}
	for (int i = 0; i < cant2; i++) {
		fwrite(&arr1[i], sizeof(empleado), 1, archivo_empleado);
	}
	system("cls");
	directivo* arr2, * arr_2;
	arr2 = new directivo[cant3];
	FILE* archivo_directivo;
	archivo_directivo = fopen("archivo3.txt", "wb");
	for (int i = 0; i < cant3; i++) {
		arr2[i].ingresar();
	}
	for (int i = 0; i < cant3; i++) {
		fwrite(&arr2[i], sizeof(directivo), 1, archivo_directivo);
	}
	system("cls");
	cliente* arr3, * arr_3;
	arr3 = new cliente[cant4];
	FILE* archivo_cliente;
	archivo_cliente = fopen("archivo4.txt", "wb");
	for (int i = 0; i < cant4; i++) {
		arr3[i].ingresar();
	}
	for (int i = 0; i < cant4; i++) {
		fwrite(&arr3[i], sizeof(cliente), 1, archivo_cliente);
	}

	system("cls");

	persona arr__[1000];  //creacioon de arreglos estaticos
	empleado arr__1[1000];
	directivo arr__2[1000];
	cliente arr__3[1000];

	while (confir == "Si" or confir == "si") {
		cout << "####################### menu #####################" << endl;
		cout << "\t1.Datos de persona" << endl;
		cout << "\t2.Datos de empleado" << endl;
		cout << "\t3.Datos de directivo" << endl;
		cout << "\t4.Datos de cliente" << endl;
		cout << "Que desea consultar? "; cin >> caso;
		system("cls");
		switch (caso)
		{

		case 1: {

			cout << "Desea agregar mas datos? (Si/No) "; cin >> consul;
			if (consul == "si" or consul == "Si") {
				archivo_persona = fopen("archivo1", "ab");//abrimos el archivo para su escritura
				cout << "Cuantos datos desea ingresar:"; cin >> cant_1;
				arr_ = new persona[cant_1];
				for (int i = 0; i < cant1; i++) {
					arr_[i].ingresar();//ingresamos los segundos datos del arreglo...
				}

				int total = cant1 + cant_1;
				int cont1 = 0, cont2 = 0;
				while (total > cont1) { //si la suma de la cantidad de los dos arreglos es menor al primer arreglo entra en el while
					if (cont1 > cant1 - 1) {  //si contador 1 es mayor a la cantidad 1 restada ingresa al arreglo
						arr__[cont1] = arr_[cont2]; // el arreglo estatico toma posicion del arreglo que se agregara asi adquiere todo sus valores ya que est arreglo estatico es de 1000 espacions
						cont2++;
					}
					else {
						arr__[cont1] = arr[cont1]; //si el contador 1 es menor ingresamos primero los arreglos del primer arreglo ai se asigna en total 
					}
					cont1++;// es nuestro contralador 
				}//al terminar el while habra ingresado los arreglos juntados


				for (int i = 0; i < cant1; i++) {
					fwrite(&arr__[i], sizeof(persona), 1, archivo_persona);//escribimos en nuestro archivo el total del arreglo final
				}
			}
			else if (consul == "No" or consul == "no") {
				cout << "Se le mostrara los datos actuales..." << endl;
				for (int i = 0; i < cant1 + cant_1; i++) {
					arr__[i].mostrar();
				}
			}
		};


			  break;
		case 2: {

			cout << "Desea agregar mas datos? (Si/No) "; cin >> consul;
			if (consul == "si" or consul == "Si") {
				archivo_persona = fopen("archivo1", "ab");
				cout << "Cuantos datos desea ingresar:"; cin >> cant_1;
				arr_1 = new empleado[cant_1];
				for (int i = 0; i < cant1; i++) {
					arr_1[i].ingresar();
				}

				int total = cant1 + cant_1;
				int cont1 = 0, cont2 = 0;
				while (total > cont1) {
					if (cont1 > cant1 - 1) {
						arr__1[cont1] = arr_1[cont2];
						cont2++;
					}
					else {
						arr__1[cont1] = arr1[cont1];
					}
					cont1++;
				}


				for (int i = 0; i < cant1; i++) {
					fwrite(&arr__1[i], sizeof(empleado), 1, archivo_empleado);
				}
			}
			else if (consul == "No" or consul == "no") {
				cout << "Se le mostrara los datos actuales..." << endl;
				for (int i = 0; i < cant2 + cant_1; i++) {
					arr__1[i].mostrar();
				}
			}
		};

			  break;
		case 3: {
			persona arr__[1000];
			cout << "Desea agregar mas datos? (Si/No) "; cin >> consul;
			if (consul == "si" or consul == "Si") {
				archivo_persona = fopen("archivo1", "ab");
				cout << "Cuantos datos desea ingresar:"; cin >> cant_1;
				arr_2 = new directivo[cant_1];
				for (int i = 0; i < cant1; i++) {
					arr_2[i].ingresar();
				}

				int total = cant1 + cant_1;
				int cont1 = 0, cont2 = 0;
				while (total > cont1) {
					if (cont1 > cant1 - 1) {
						arr__2[cont1] = arr_2[cont2];
						cont2++;
					}
					else {
						arr__2[cont1] = arr2[cont1];
					}
					cont1++;
				}


				for (int i = 0; i < cant1 + cant_1; i++) {
					fwrite(&arr__2[i], sizeof(directivo), 1, archivo_directivo);
				}
			}
			else if (consul == "No" or consul == "no") {
				cout << "Se le mostrara los datos actuales..." << endl;
				for (int i = 0; i < cant3 + cant_1; i++) {
					arr__3[i].mostrar();
				}
			}
		};

			  break;
		case 4: {
			persona arr__[1000];
			cout << "Desea agregar mas datos? (Si/No) "; cin >> consul;
			if (consul == "si" or consul == "Si") {
				archivo_persona = fopen("archivo1", "ab");
				cout << "Cuantos datos desea ingresar:"; cin >> cant_1;
				arr_3 = new cliente[cant_1];
				for (int i = 0; i < cant1; i++) {
					arr_3[i].ingresar();
				}

				int total = cant1 + cant_1;
				int cont1 = 0, cont2 = 0;
				while (total > cont1) {
					if (cont1 > cant1 - 1) {
						arr__3[cont1] = arr_3[cont2];
						cont2++;
					}
					else {
						arr__3[cont1] = arr3[cont1];
					}
					cont1++;
				}


				for (int i = 0; i < cant1; i++) {
					fwrite(&arr__3[i], sizeof(cliente), 1, archivo_cliente);
				}
			}
			else if (consul == "No" or consul == "no") {
				cout << "Se le mostrara los datos actuales..." << endl;

				for (int i = 0; i < cant4 + cant_1; i++) {
					arr__3[i].mostrar();
				}
			}
			break;
			;
		};
		}

		cout << "Desea seguir consultando el menu? (Si/No):"; cin >> confir;
		system("cls");
	}
	cout << "Que tenga un buen dia..." << endl;

	delete[]arr, arr1, arr2, arr3, arr_, arr_1, arr_2, arr_3, arr__, arr__1, arr__2, arr__3; //hacemos una limpieza de nuestros punteros para liberar espacio




}
