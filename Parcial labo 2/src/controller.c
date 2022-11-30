/*
 * controller.c
 *
 *  Created on: 30 nov 2022
 *      Author: danil
 */

#ifndef CONTROLLER_C_
#define CONTROLLER_C_

#include "controller.h"


int controller_cargarPeliculaDesdeTexto(char* path , LinkedList* pListaPeliculas)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(path!=NULL)
	{
		pArchivo=fopen(path,"r");

		if(pArchivo!=NULL)
		{
			parser_peliculaFromText(pArchivo, pListaPeliculas);
			printf("\n<Se cargaron exitosamente las peliculas>\n");
			retorno=1;
		}
		else
		{
			printf("\n<No se pudieron cargar las peliculas>\n");
		}

		fclose(pArchivo);
	}
    return retorno;
}


int controller_listarPeliculas(LinkedList* pListaPeliculas)
{
	int retorno=-1;
	int size=ll_len(pListaPeliculas);

	Pelicula* peliculaAux;

	if(pListaPeliculas!=NULL)
	{
		printf("\n|========================LISTA PELICULAS==========================|\n");
		printf("|  ID    |        TITULO        |    GENERO    |      DURACION    |\n");
		printf("|=================================================================|\n");


		for(int i=0;i<size;i++)
		{
			peliculaAux = ll_get(pListaPeliculas, i);
			pelicula_MostrarPelicula(peliculaAux);
		}
		retorno = 0;
		//printf("JUGADORES CARGADOS : %d\n",size);
	}
	else
	{
		printf("ERROR al mostrar");
	}

	return retorno;
}

int controller_guardarPeliculasModoTexto(char* path , LinkedList* pListaPeliculas)
{
	int retorno=-1;

	FILE* pArchivo;

	if(path!=NULL && pListaPeliculas!=NULL)
	{
		pArchivo=fopen(path,"w");
		if(pArchivo!=NULL)
		{
			//printf("archivo != NULL\n");
			parser_PeliculaSaveAsText(pArchivo, pListaPeliculas);
			retorno=1;//se guardo exitosamente.
		}

	}
    return retorno;
}

#endif /* CONTROLLER_C_ */
