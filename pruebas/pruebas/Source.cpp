// Archivo de acceso aleatorio
#include "libro.h"
#include <iostream>
using std::cerr;
using std::endl;
using std::ios;
using std::cout;
using std::cin;

#include <iomanip>
using std::setw;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <cstdlib> 
using std::exit; // prototipo de la función exit



class Excepciones :
    public exception {
public:
    virtual const char* noAbre() const throw()
    {
        return "No se puede abrir el archivo\n";
    }
    virtual const char* siExiste() const throw()
    {
        return "El archivo ya existe\n";
    }
};


void menu();
void crearArchivo();
void leerArchivo();
void escribirArchivo();
void agregar();

int main()
{
    menu();

    return 0;
}


void menu()
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
            escribirArchivo();
            break;
        case 2:
            leerArchivo();
            break;
        case 3:
            crearArchivo();
            break;
        case 4:
            agregar();
            break;
        }
    } while (opc != 4);
}

void agregar()
{
    int _codigo, _nroCopias;
    char _autor[20];
    char _titulo[30];
    char respuesta = 'n';
    Libro libroBlanco;

    ofstream archivoLibros("libros01.dat", ios::app | ios::binary);
    Excepciones expEscribir;
    try {
        // constructor ofstream apertura de archivo
        if (!archivoLibros)
            throw expEscribir;
    }
    catch (Excepciones& exp)
    {
        cerr << exp.noAbre();
        exit(EXIT_FAILURE);
    }

    for (;;)
    {
        cout << "Ingrese al codigo del registro (1 a 10): ";
        cin >> _codigo;
        cout << "Ingrese el titulo: ";
        cin >> setw(30) >> _titulo;
        cout << "Ingrese el autor: ";
        cin >> setw(20) >> _autor;
        cout << "Ingrese nro. de copias: ";
        cin >> _nroCopias;

        libroBlanco.setCodigo(_codigo);
        libroBlanco.setTitle(_titulo);
        libroBlanco.setAutor(_autor);
        libroBlanco.setNroCopias(_nroCopias);

        // Buscamos en que posicion del archivo tenemos que escribir
        archivoLibros.seekp((libroBlanco.getCodigo() - 1) * sizeof(Libro));
        archivoLibros.write(reinterpret_cast<const char*>(&libroBlanco), sizeof(Libro));

        cout << "\nDesea continuar?: ";
        cin >> respuesta;
        if (respuesta != 's')
            break;
    }
    archivoLibros.close();
    system("pause");
    system("cls");
}

void escribirArchivo()
{
    int _codigo, _nroCopias;
    char _autor[20];
    char _titulo[30];
    char respuesta = 'n';
    Libro libroBlanco;

    ofstream archivoLibros("libros01.dat", ios::out | ios::binary);
    Excepciones expEscribir;
    try {
        // constructor ofstream apertura de archivo
        if (!archivoLibros)
            throw expEscribir;
    }
    catch (Excepciones& exp)
    {
        cerr << exp.noAbre();
        exit(EXIT_FAILURE);
    }

    for (;;)
    {
        cout << "Ingrese al codigo del registro (1 a 10): ";
        cin >> _codigo;
        cout << "Ingrese el titulo: ";
        cin >> setw(30) >> _titulo;
        cout << "Ingrese el autor: ";
        cin >> setw(20) >> _autor;
        cout << "Ingrese nro. de copias: ";
        cin >> _nroCopias;

        libroBlanco.setCodigo(_codigo);
        libroBlanco.setTitle(_titulo);
        libroBlanco.setAutor(_autor);
        libroBlanco.setNroCopias(_nroCopias);

        // Buscamos en que posicion del archivo tenemos que escribir
        archivoLibros.seekp((libroBlanco.getCodigo() - 1) * sizeof(Libro));
        archivoLibros.write(reinterpret_cast<const char*>(&libroBlanco), sizeof(Libro));

        cout << "\nDesea continuar?: ";
        cin >> respuesta;
        if (respuesta != 's')
            break;
    }
    archivoLibros.close();
    system("pause");
    system("cls");
}

void leerArchivo()
{
    int _codigo, _nroCopias;
    char _autor[20];
    char _titulo[30];
    char respuesta = 'n';
    Libro libroBlanco;

    fstream archivoLibros("libros01.dat", ios::in |  ios::out | ios::binary);
    //ifstream ArchivoLibrosLectura("libros01.dat", ios::in | ios::binary);

    Excepciones expLeer;
    try {
        if (!archivoLibros)
            throw expLeer;
    }
    catch (Excepciones& exp) {
        cerr << exp.noAbre();
        exit(EXIT_FAILURE);
    }


    for (;;)
    {
        cout << "Codigo: "; cin >> _codigo;
        libroBlanco.setCodigo(_codigo);
        archivoLibros.seekp((libroBlanco.getCodigo() - 1) * sizeof(Libro));

        archivoLibros.read(reinterpret_cast<char*>(&libroBlanco), sizeof(Libro));

        cout << "SALIDA  DE DATOS: " << endl;
        cout << "Codigo	: " << (int)libroBlanco.getCodigo() << endl;
        cout << "Autor: " << libroBlanco.getAutor() << endl;
        cout << "Titulo	: " << libroBlanco.getTitle() << endl;
        cout << "Nro. de copias	: " << (int)libroBlanco.getNroCopias() << endl;

        cout << "\nDesea continuar?: ";
        cin >> respuesta;
        if (respuesta != 's')
            break;
    }
    archivoLibros.close();
    system("pause");
    system("cls");
}

void crearArchivo()
{
    ofstream archivoLibros("libros01.dat", ios::out | ios::binary);
    Excepciones expCrear;
    try
    {
        if (archivoLibros)
            throw expCrear;
    }
    catch (Excepciones& exp)
    {
        cerr << exp.siExiste();
    }

    Libro libroBlanco;
    //cout << sizeof(libroBlanco) << endl;

    // crearemos espacios (10) para los registros
    for (int i = 0; i < 10; ++i) // ++i no genera copia
    {
        // write(): genera numero de bytes fijo
        archivoLibros.write(reinterpret_cast<const char*>(&libroBlanco), sizeof(Libro));
    }
    // hasta aqui creo el archivo de longitud fija
    archivoLibros.close();
    system("pause");
    system("cls");
}
