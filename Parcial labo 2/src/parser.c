/*
 * parser.c
 *
 *  Created on: 30 nov 2022
 *      Author: danil
 */

#ifndef PARSER_C_
#define PARSER_C_


#include "parser.h"

int parser_peliculaFromText(FILE* pFile , LinkedList* pListaPelicula)
{
	int retorno=-1;

		Pelicula* peliculaAux=NULL;

		char idAux[10];
		char tituloAux[50];
		char generoAux[50];
		char ratingAux[10];

		if(pFile!=NULL && pListaPelicula!=NULL)
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",idAux,tituloAux,generoAux,ratingAux);//lectura fantasma

			while(!feof(pFile))
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",idAux,tituloAux,generoAux,ratingAux);

				peliculaAux=pelicula_newParametros(idAux, tituloAux, generoAux, ratingAux);

				if(peliculaAux!=NULL)
				{
					ll_add(pListaPelicula, peliculaAux);
				}
			}
			retorno=1;
		}

		return retorno;
}

int parser_PeliculaSaveAsText(FILE* pFile , LinkedList* pListaPeliculas)
{
	int retorno=-1;
	int size=ll_len(pListaPeliculas);

	Pelicula* peliculaAux;
	int idAux;
	char titulo[50];
	char genero[50];
	int duracion;

	if(pFile!=NULL && pListaPeliculas!=NULL)
	{

		fprintf(pFile, "id_peli,titulo,genero,duracion\n");

		for(int i=0;i<size;i++)
		{
			peliculaAux=(Pelicula*)ll_get(pListaPeliculas, i);

			if(peliculaAux!=NULL)
			{

				pelicula_getId(peliculaAux, &idAux);
				pelicula_getTitulo(peliculaAux, titulo);
				pelicula_getGenero(peliculaAux, genero);
				pelicula_getDuracion(peliculaAux, &duracion);

				fprintf(pFile, "%d,%s,%s,%d\n",idAux, titulo, genero, duracion);
				retorno=1;
			}
		}
	}



    return retorno;
}

#endif /* PARSER_C_ */
