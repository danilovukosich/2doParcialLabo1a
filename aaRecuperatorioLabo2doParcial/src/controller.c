/*
 * controller.c
 *
 *  Created on: 7 dic 2022
 *      Author: danil
 */

#ifndef CONTROLLER_C_
#define CONTROLLER_C_

#include "controller.h"

int controller_cargarPosteosDesdeTexto(char* path , LinkedList* pListaPosteos)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(path!=NULL)
	{
		pArchivo=fopen(path,"r");

		if(pArchivo!=NULL)
		{
			parser_posteosFromText(pArchivo, pListaPosteos);
			printf("\n<Se cargaron exitosamente los posteos>\n");
			retorno=1;
		}
		else
		{
			printf("\n<No se pudieron cargar los posteos>\n");
		}

		fclose(pArchivo);
	}
    return retorno;
}


int controller_listarPosteos(LinkedList* pListaPosteos)
{
	int retorno=-1;
	int size=ll_len(pListaPosteos);

	ePosteo* posteoAux;

	if(pListaPosteos!=NULL)
	{
		printf("\n|============================LISTA POSTEOS======================================|\n");
		printf("|  ID    |        USUARIO         |     LIKES     |    DISLIKES    | FOLLOWERS  |\n");
		printf("|===============================================================================|\n");


		for(int i=0;i<size;i++)
		{
			posteoAux = ll_get(pListaPosteos, i);
			posteo_MostrarPosteo(posteoAux);
		}
		retorno = 0;
		//printf("Posteos CARGADOS : %d\n",size);
	}
	else
	{
		printf("ERROR al mostrar");
	}

	return retorno;
}

int controller_guardarPosteosModoTexto(char* path , LinkedList* pListaPosteos)
{
	int retorno=-1;

	FILE* pArchivo;

	if(path!=NULL && pListaPosteos!=NULL)
	{
		pArchivo=fopen(path,"w");
		if(pArchivo!=NULL)
		{
			//printf("archivo != NULL\n");
			parser_PosteosSaveAsText(pArchivo, pListaPosteos);
			retorno=1;//se guardo exitosamente.
		}

		fclose(pArchivo);

	}
    return retorno;
}


#endif /* CONTROLLER_C_ */
