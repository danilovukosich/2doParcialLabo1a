/*
 * parser.c
 *
 *  Created on: 7 dic 2022
 *      Author: danil
 */

#ifndef PARSER_C_
#define PARSER_C_

#include "parser.h"

int parser_posteosFromText(FILE* pFile , LinkedList* pListaPosteos)
{
	int retorno=-1;

		ePosteo* posteoAux=NULL;

		char idAux[10];
		char ususarioAux[50];
		char likesAux[10];
		char dislikesAux[10];
		char followersAux[10];

		if(pFile!=NULL && pListaPosteos!=NULL)
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,ususarioAux,likesAux,dislikesAux,followersAux);//lectura fantasma

			while(!feof(pFile))
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,ususarioAux,likesAux,dislikesAux,followersAux);

				posteoAux=posteo_newParametros(idAux, ususarioAux, likesAux, dislikesAux, followersAux);

				if(posteoAux!=NULL)
				{
					ll_add(pListaPosteos, posteoAux);
				}
			}
			retorno=1;
		}

		return retorno;
}

int parser_PosteosSaveAsText(FILE* pFile , LinkedList* pListaPosteos)
{
	int retorno=-1;
	int size=ll_len(pListaPosteos);

	ePosteo* posteoAux;
	int idAux;
	char usuario[50];
	int likes;
	int dislikes;
	int followers;

	if(pFile!=NULL && pListaPosteos!=NULL)
	{

		fprintf(pFile, "id,user,likes,dislikes,followers\n");

		for(int i=0;i<size;i++)
		{
			posteoAux=(ePosteo*)ll_get(pListaPosteos, i);

			if(posteoAux!=NULL)
			{

				posteo_getId(posteoAux, &idAux);
				posteo_getUsuario(posteoAux, usuario);
				posteo_getLikes(posteoAux, &likes);
				posteo_getDislikes(posteoAux, &dislikes);
				posteo_getFollowers(posteoAux, &followers);

				//printf( "%d  %s  %s %d\n",idAux, titulo, genero, duracion);

				fprintf(pFile, "%d,%s,%d,%d,%d\n",idAux, usuario, likes, dislikes,followers);

				retorno=1;
			}
		}
	}



    return retorno;
}

#endif /* PARSER_C_ */
