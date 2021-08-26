#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "sqlite3.h"
#include "funciones.h"
#include "celular.h"
using namespace std;
int main()
{
    // declaraciones para manejar bases de datos
    sqlite3* ptrBaseDeDatos = 0;
    char nombreBaseDeDatos[] = "celulares01.db";
    char* zErrMsg = 0;

    Celular* objeto = new Celular[10];
    
       
    int opc = 0;
    char resp = 's';
    do {
        cout << "\t\t\tMENU" << endl;
        cout << "\t\t\t====" << endl;
        cout << "\t1.- APERTURA DE LA BASE DE DATOS" << endl;
        cout << "\t2.- CIERRE DE LA BASE DE DATOS" << endl;
        cout << "\t3.- CREAR TABLA EN LA BASE DE DATOS" << endl;
        cout << "\t4.- INSERTAR REGISTROS EN TABLA" << endl;
        cout << "\t5.- BORRAR REGISTROS EN TABLA" << endl;
        cout << "\t6.- ACTUALIZAR REGISTROS EN TABLA" << endl;
        cout << "\t7.- CONSUTAR REGISTRO EN TABLA" << endl;
        cout << "\t8.- SALIR" << endl;

        cout << "Ingrese una opcion(1-7): ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            ptrBaseDeDatos = apertura(nombreBaseDeDatos, ptrBaseDeDatos);
            break;
        case 2:
            cierre(ptrBaseDeDatos);
            break;
        case 3:
            funcionCreateTable(ptrBaseDeDatos, objeto, zErrMsg);
            break;
        case 4:
            funcionInsertInto01(objeto, ptrBaseDeDatos, zErrMsg);
            break;
        case 5:
            funcionDelete(objeto, ptrBaseDeDatos, zErrMsg);
            break;
        case 6:
            funcionUpdate(ptrBaseDeDatos, objeto, zErrMsg);
            break;
        case 7:
            funcionSelect(ptrBaseDeDatos, zErrMsg);
        }
    } while (opc != 8);

    return 0;
}
