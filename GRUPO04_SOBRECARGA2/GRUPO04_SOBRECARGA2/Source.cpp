#pragma warning(disable:4996)
#include "curso.h"
#include "string.h"
using namespace std;
#include "alumno.h"
#include "profesor.h"
#include "funcionamiga.h"

// Inicializamos el atributo static de la clase Alumno
string Alumno::colegioNombre = "I.E.P. PRE";

int main() {

	// ============================== PARTE REGISTRO DE ALUMNOS ================================== //
	int cantidad = 2;
	FILE* registroAlumnos1ro;
	registroAlumnos1ro = fopen("alumnos1ro.dat", "wb");

	// declaración de un ARREGLO DINAMICO DE OBJETOS, 
	// uso de constructor implícito   
	Alumno* listaAlumnos1ro;
	listaAlumnos1ro = new Alumno[cantidad];

	// Registramos nombre, codigó y que cursos llevarán los alumnos
	for (int i = 0; i < cantidad; i++)
		listaAlumnos1ro[i].registrarse();
	// Imprimimos datos de cada alumno registrado
	for (int i = 0; i < cantidad; i++)
		listaAlumnos1ro[i].imprimir();
	// Escribimos los datos en el archivo "alumnos1ro.dat"
	for (int i = 0; i < cantidad; i++)
		fwrite(&listaAlumnos1ro[i], sizeof(Alumno), 1, registroAlumnos1ro);


	// ============================== FIN PARTE REGISTRO DE ALUMNOS ================================== //

	cout << "======================== PLATAFORMA PROFESOR ========================" << endl;
	// ============================== PROFESOR FILOSOFIA================================== //
	Profesor ProfFilosofia;
	ProfFilosofia.ingresar();  // Ingresar nombre, codigo y curso que dicta el profesor
	ProfFilosofia.imprimir();  // Imprimimos datos del profesor

	cout << "=============================== REGISTRAR NOTAS ============================" << endl;
	// Registro de notas por parte del profesor
	bool llevaElCurso; // variable que usaremos para verificar que alumnos
					   // llevan el curso de este profesor
	for (int i = 0; i < cantidad; i++)
	{
		// Con esta linea verifico que alumnos llevan el curso de este profesor
		// getNamesCursos() es función amiga de la clase Alumno
		llevaElCurso = getNamesCursos(listaAlumnos1ro[i], ProfFilosofia.getCurso());
		// si lleva el curso recien permitimos que le ponga una nota
		if (llevaElCurso)
		{
			ProfFilosofia.ponerNota(listaAlumnos1ro[i], ProfFilosofia.getCurso());
		}
	}

	// ============================== PROFESOR MATEMATICA================================== //
	Profesor ProfMatematica;
	ProfMatematica.ingresar();  // Ingresar nombre, codigo y curso que dicta el profesor
	ProfMatematica.imprimir();  // Imprimimos datos del profesor

	cout << "=============================== REGISTRAR NOTAS ============================" << endl;
	llevaElCurso = false;
	for (int i = 0; i < cantidad; i++)
	{
		// Con esta linea verifico que alumnos llevan el curso de este profesor
		// getNamesCursos() es función amiga de la clase Alumno
		llevaElCurso = getNamesCursos(listaAlumnos1ro[i], ProfMatematica.getCurso());
		// si lleva el curso recien permitimos que le ponga una nota
		if (llevaElCurso)
		{
			ProfMatematica.ponerNota(listaAlumnos1ro[i], ProfMatematica.getCurso());
		}
	}


	/////////////////////////////////// SACAMOS PROMEDIOS DE ALUMNOS ///////////////////////////////////

	cout << "==================== PROMEDIOS GENERALES DE ALUMNOS ===========================" << endl;
	for (int i = 0; i < cantidad; i++)
	{
		listaAlumnos1ro[i].obtenerPromedio();
	}




	// =========================================== EL COLEGIO CAMBIÓ DE NOMBRE ==========================
	// cambia el nombre del colegio en el registro de todos los alumnos
	cout << "========================== EL COLEGIO CAMBIO DE NOMBRE ==========================" << endl;
	Alumno::setNombreColegio("I.E.P. VON NEUMAN");
	// Imprimimos datos de cada alumno registrado
	for (int i = 0; i < cantidad; i++)
		listaAlumnos1ro[i].imprimir();
	return 0;
}