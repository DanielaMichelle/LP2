#pragma once
#include "alumno.h"

////////// FUNCION AMIGA DE LA CLASE ALUMNO ///////////
bool getNamesCursos(Alumno& unObjeto, string unObjeto_nombre)
{
	bool estudianteLlevaCurso = false;
	for (int i = 0; i < unObjeto.cantCursos; i++)
	{
		if (unObjeto.listaCurso[i].getNombre() == unObjeto_nombre)
		{
			estudianteLlevaCurso = true;
		}
	}
	return estudianteLlevaCurso;
}