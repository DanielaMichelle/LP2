/************************************************************
NOMBRE     : ejecutar02.cpp*
AUTOR      : grupo*
FECHA      : 02/05/2021*
DESCRIPCION: Programa de biblioteca con menu para registro
************************************************************/

#pragma warning(disable:4996)
#include "libro.h"
#include "user.h"
#include "bibliotecario.h"
#include <iostream>
#include <string>
using namespace std;


void menu(FILE* archivo, Libro* lista);
void crearArchivo(FILE* archivo);
void leerArchivo(FILE* archivo, Libro* lista);
void escribirArchivo(FILE* archivo, Libro* lista);

int main()
{
    // ============================== PARTE REGISTRO ================================== //
    int cantidad = 10;
    FILE* registroLibros;
    registroLibros = fopen("libros.dat", "rb");
    Libro* listaLibros;
    listaLibros = new Libro[cantidad];
    menu(registroLibros, listaLibros);

    // ============================== FIN PARTE REGISTRO ================================== //

    // ============================== PARTE DE USER ================================== //

    string nombreL;
    bool verificacion;

    cin.ignore();
    cout << "=================================" << endl;
    cout << "INGRESA NOMBRE DEL LIBRO: ";
    getline(cin, nombreL);
    cout << "=================================" << endl;


    User Juanjo(nombreL);
    // usuario verifica la exitencia del libro
    verificacion = Juanjo.VerificarAccesibilidadLibro(listaLibros);
    if (verificacion)
    {
        //usuario pide el libro
        Juanjo.pedirLibro(listaLibros);
        Bibliotecario bibliotecarioRamon(&Juanjo);
        bibliotecarioRamon.pedirDatos().imprimirRecibo();
    }

    // usuario regresa libro
    Juanjo.regresarLibro(listaLibros);

    // ============================== FIN PARTE DE USER ================================== //

    return 0;
}

void menu(FILE* archivo, Libro* lista)
{
    int opc = 0;
    do
    {
        cout << "                  MENU " << endl;
        cout << "                  ==== " << endl;
        cout << " 1. Escribir datos en Archivo " << endl;//a
        cout << " 2. Leer datos de Archivo " << endl;//r
        cout << " 3. Crear Archivo " << endl;//w
        cout << " 4. Salir " << endl << endl;
        cout << " Elija una opcion(1-4): ";

        do
        {
            cin >> opc;
            if (opc < 1 || opc > 4)
                cout << "ERROR: ingrese un numero valido..." << endl;
        } while (opc < 1 || opc > 4);


        switch (opc)
        {
        case 1:
            escribirArchivo(archivo, lista);
            break;
        case 2:
            leerArchivo(archivo, lista);
            break;
        case 3:
            crearArchivo(archivo);
            break;
        }
    } while (opc != 4);
}

void escribirArchivo(FILE* archivo, Libro* lista)
{
    int cant = 0;
    //////////////////// COMPROBACION PARA ESCRITURA /////////////////////////////
    if (archivo != 0) // = existe
    {
        fclose(archivo);
        ///////////////////////// ESCRIBIMOS EN EL ARCHIVO ////////////////

        archivo = fopen("libros.dat", "ab"); // aqui puedo agregar

        cout << "Ingresar numero de libros: "; cin >> cant;
        for (int i = 0; i < cant; i++)
            lista[i].ingresar();

        // escribimos data en el archivo:
        for (int i = 0; i < cant; i++)
            fwrite(&lista[i], sizeof(Libro), 1, archivo);

        system("pause");
        system("cls");

        // imprimimos informacion
        cout << "\n=========== INFORMACION INGRESADA: ========" << endl;
        for (int i = 0; i < cant; i++)
            lista[i].imprimir();

        // ahora cerramos el archivo
        fclose(archivo);
        system("pause");
        system("cls");
    }
    else
        cout << "EL ARCHIVO NO EXISTE" << endl;
}


void leerArchivo(FILE* archivo, Libro* lista)
{
    int cant = 0;
    //////////////////// COMPROBACION PARA LECTURA /////////////////////////////
            // tenemos que asegurarnos que el archivo ya fue creado o qu existe
            // AQUI COMPRUEBO DE QUE EXISTA
    if (archivo != 0)  // si existe entonces...
    {
        ///////////////////////// LEEMOS EL ARCHIVO ////////////////
        cout << "Ingresar numero de libros: "; cin >> cant;
        // leemos data en el archivo:
        for (int i = 0; i < cant; i++)
            fread(&lista[i], sizeof(Libro), 1, archivo);

        // imprimimos la informacion
        for (int i = 0; i < cant; i++)
            lista[i].imprimir();

        system("pause");
        system("cls");
    }
    else
        cout << "EL ARCHIVO NO EXISTE" << endl;
    system("pause");
    system("cls");
}

void crearArchivo(FILE* archivo)
{
    //////////////////// COMPROBACION PARA CREACION///////////////////////////
    if (archivo == 0) // = no existe, sino existe lo puedo crear
    {
        /////////////////////// CREAMOS EL ARCHIVO///////////////////////   
        //crear el archivo con w
        archivo = fopen("libros.dat", "wb");

        // decimos que el archivo fue creado               
        cout << "\nEL ARCHIVO FUE CREADO " << endl;
        cout << "\nESCOGE LA OPCION 1 PARA INGRESAR DATOS " << endl;

        // ahora cerramos el archivo
        fclose(archivo);
        system("pause");
        system("cls");
    }
    else  // en caso de que ya exista:
        cout << "EL ARCHIVO YA EXISTE" << endl;
    system("pause");
    system("cls");
}

