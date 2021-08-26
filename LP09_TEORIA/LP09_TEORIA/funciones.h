#pragma once
#include <exception>
#include <stdio.h>

#include <iostream>
using namespace std;
#include "sqlite3.h"
#include "celular.h"
static int callback(void* objeto, int argc, char** argv, char** ColName)
{
    int i;
    Celular* t = reinterpret_cast<Celular*>(objeto);
    for (i = 0; i <= argc; i++)
    {
        if (i == 0)
            t->id = atoi(argv[i]);
        if (i == 1)
            strcpy_s(t->marca, argv[i]);
        if (i == 2)
            strcpy_s(t->modelo, argv[i]);
        if (i == 3)
            t->precio = atof(argv[i]);
        if (i == 4)
        {
            t->cantidad = atoi(argv[i]);
            cout << *t;
        }

        //printf("%s = %s\n", ColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
void ejecutar(sqlite3* ptrBaseDeDatos1, char* sql, Celular* objeto, char* zErrMsg)
{
    int rc = sqlite3_exec(ptrBaseDeDatos1, sql, callback, (void*)objeto, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "ERROR: instrucción SQL no ejecutada: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Instruccion ejecutada exitosamente!\n");
    }
}
sqlite3* apertura(char* nombreBaseDeDatos, sqlite3* ptrBaseDeDatos)
{
    try {
        // instrucciones para ejecutar la apertura de la base de datos
        int resultadoConexion = sqlite3_open(nombreBaseDeDatos, &ptrBaseDeDatos);
        if (resultadoConexion)
            throw exception();
        fprintf(stderr, "Base de datos abierta exitosamente!\n");
    }
    catch (exception& e)
    {
        fprintf(stderr, "ERROR: No es posible abrir la base de datos: %s ...\n",
            sqlite3_errmsg(ptrBaseDeDatos));
        cerr << e.what() << endl;
        exit(0);
    }
    return ptrBaseDeDatos;
}
void cierre(sqlite3* ptrBaseDeDatos)
{
    // instrucciones para ejecutar el cierre de la base de datos
    sqlite3_close(ptrBaseDeDatos);
}
void funcionSelect(sqlite3* ptrBaseDeDatos, char* zErrMsg)
{
    char sql[100];
    Celular objeto;
    Celular** lista = new Celular * [10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Ingresar codigo de producto: ";
        cin >> objeto.id;
        sprintf_s(sql, "SELECT * FROM Celular WHERE ID=%d;", objeto.id);
        int rc = sqlite3_exec(ptrBaseDeDatos, sql, callback, (void*)&lista[i], &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "ERROR: instrucción SQL no ejecutada: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else {
            fprintf(stdout, "Instruccion ejecutada exitosamente!\n");
        }
        cout << lista[i];
    }

}


void funcionDelete(Celular* objeto, sqlite3* ptrBaseDeDatos, char* zErrMsg)
{
    char sql[100];
    int entero = 0;
    cout << "Ingresa el id del celular: "; cin >> entero;
    sprintf_s(sql, "DELETE from Celular where ID=%d; SELECT * from Celular;", entero);
    ejecutar(ptrBaseDeDatos, sql, objeto, zErrMsg);
}

void funcionInsertInto01(Celular* objeto, sqlite3* ptrBaseDeDatos, char* zErrMsg)
{
    char sql[100];
    for (int i = 0; i < 1; i++)
    {
        cin >> objeto[i];
        sprintf_s(sql, "INSERT INTO CELULAR(ID, MARCA, MODELO, PRECIO, CANTIDAD) VALUES(%d, '%s', '%s', %f, %d);", objeto[i].id, objeto[i].marca, objeto[i].modelo,objeto[i].precio, objeto[i].cantidad);
        ejecutar(ptrBaseDeDatos, sql, objeto, zErrMsg);
    }
}

void funcionInsertInto2(Celular* objeto, sqlite3* ptrBaseDeDatos, char* zErrMsg)
{
    char sql[] = "INSERT INTO Celular(ID, MARCA, MODELO, PRECIO, CANTIDAD)" \
        "VALUES (1, 'SAMSUNG', 'A10', 5000.0, 10 );" \
        "INSERT INTO Celular(ID, MARCA, MODELO, PRECIO, CANTIDAD)"  \
        "VALUES (2, 'SAMSUNG', 'A2', 5000.0, 10 );";
    ejecutar(ptrBaseDeDatos, sql, objeto, zErrMsg);
}
void funcionCreateTable(sqlite3* ptrBaseDeDatos1, Celular* objeto, char* zErrMsg)
{
    // instrucción SQL para crear la tabla Celular
    char sql[] = "CREATE TABLE Celular("  \
        "ID INT PRIMARY KEY NOT NULL," \
        "MARCA  CHAR(30)    NOT NULL," \
        "MODELO CHAR(30)    NOT NULL," \
        "PRECIO REAL," \
        "CANTIDAD   INT );";
    ejecutar(ptrBaseDeDatos1, sql, objeto, zErrMsg);
}


void funcionUpdate(sqlite3* ptrBaseDeDatos, Celular* objeto, char* zErrMsg)
{
    cout << "ACTUALIZAR REGISTRO" << endl;
    char sql[100];
    int intC = 0;
    cout << "Ingresa el numero de id del celular ha actualizar: "; cin >> intC;
    cin >> objeto[intC];
    sprintf_s(sql, "UPDATE Celular SET MARCA = '%s', MODELO = '%s', PRECIO = %f, CANTIDAD = %d WHERE ID = %d;",
        objeto[intC].marca, objeto[intC].modelo, objeto[intC].precio, objeto[intC].cantidad, intC);
    ejecutar(ptrBaseDeDatos, sql, objeto, zErrMsg);

};