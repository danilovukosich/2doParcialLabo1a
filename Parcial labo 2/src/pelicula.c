 /*
 * pelicula.c
 *
 *  Created on: 30 nov 2022
 *      Author: danil
 */

#ifndef PELICULA_C_
#define PELICULA_C_
#include "pelicula.h"



Pelicula* pelicula_new()
{
	return malloc(sizeof(Pelicula));
}

Pelicula* pelicula_newParametros(char* id, char* titulo, char* genero, char* rating)
{
	Pelicula* unaPelicula;

	unaPelicula= pelicula_new();

	if(id!=NULL && titulo!=NULL && genero!=NULL && rating!=NULL )
	{
		pelicula_setId(unaPelicula, atoi(id));
		pelicula_setTitulo(unaPelicula, titulo);
		pelicula_setGenero(unaPelicula, genero);
		pelicula_setDuracion(unaPelicula, atoi(rating));
	}
	else
	{
		printf("\nError de pelicula_newParametros\n");
	}


	return unaPelicula;
}

int pelicula_setId(Pelicula* this,int id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->id = id;
		retorno=1;
	}

	return retorno;
}

int pelicula_getId(Pelicula* this,int* id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*id=this->id;
		retorno=1;
	}

	return retorno;
}

int pelicula_setTitulo(Pelicula* this,char* titulo)
{
	int retorno=-1;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(this->titulo, titulo);
		retorno=1;
	}

	return retorno;
}

int pelicula_getTitulo(Pelicula* this,char* titulo)
{
	int retorno=-1;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo, this->titulo);
		retorno=1;
	}

	return retorno;
}

int pelicula_setGenero(Pelicula* this,char* genero)
{
	int retorno=-1;
	if(this!=NULL && genero!=NULL)
	{
		strcpy(this->genero, genero);
		retorno=1;
	}

	return retorno;
}

int pelicula_getGenero(Pelicula* this,char* genero)
{
	int retorno=-1;
	if(this!=NULL && genero!=NULL)
	{
		strcpy(genero, this->genero);
		retorno=1;
	}

	return retorno;
}

int pelicula_setDuracion(Pelicula* this,int duracion)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->duracion = duracion;
		retorno=1;
	}

	return retorno;
}

int pelicula_getDuracion(Pelicula* this,int* duracion)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*duracion=this->duracion;
		retorno=1;
	}

	return retorno;
}

int pelicula_MostrarPelicula(Pelicula* peliculaAux)
{
	int retorno=-1;

	int idAux;
	char tituloAux[50];
	char generoAux[50];
	int duracionAux;

	if(peliculaAux!=NULL)
	{

		pelicula_getId(peliculaAux, &idAux);
		pelicula_getTitulo(peliculaAux, tituloAux);
		pelicula_getGenero(peliculaAux, generoAux);
		pelicula_getDuracion(peliculaAux, &duracionAux);

		printf("    %2d %25s   %20s        %2d\n",idAux, tituloAux, generoAux, duracionAux);

		retorno=1;
	}

	return retorno;
}
////////////////////////////


int DuracionRandom(void)
{
	int numero;

	for(int i=0; i<50; i++)
	{
		numero=rand() % (240 - 100 + 1) + 100;
	}

	return numero;
}

int AsiganrDuracion(Pelicula* this)
{
	int numero=DuracionRandom();

	pelicula_setDuracion(this, numero);

	return 1;
}

int GetGenero(int opcion, char* genero)
{
	int retorno=-1;

	if(genero!=NULL)
	{
		switch(opcion)
		{
		case 1:
			strcpy(genero, "Adventure");
			break;
		case 2:
			strcpy(genero, "Drama");
			break;
		case 3:
			strcpy(genero, "Comedy");
			break;
		case 4:
			strcpy(genero, "Romance");
			break;
		case 5:
			strcpy(genero, "Documentary");
			break;
		case 6:
			strcpy(genero, "Horror");
			break;
		case 7:
			strcpy(genero, "Musical");
			break;
		case 8:
			strcpy(genero, "Animation");
			break;
		retorno=1;
	}



	}

	return retorno;
}
int filtroGenero(void* pElement, void* filter)
{

	return(strcmp(((Pelicula*)pElement)->genero , (char*)filter));

}

int OrdenarPeliculaGenero(void* pPelicula1, void* pPelicula2)
{
	int retorno;
	char genero1[50];
	char genero2[50];
	int duracion1;
	int duracion2;

	Pelicula* peliculaAux1=NULL;
	Pelicula* peliculaAux2=NULL;

	if(pPelicula1!=NULL && pPelicula2!=NULL)
	{
		peliculaAux1=(Pelicula*)pPelicula1;
		peliculaAux2=(Pelicula*)pPelicula2;

		pelicula_getGenero(peliculaAux1, genero1);
		pelicula_getGenero(peliculaAux2, genero2);
		pelicula_getDuracion(peliculaAux1, duracion1);
		pelicula_getDuracion(peliculaAux1, duracion2);

		retorno=strcmp(genero1,genero2);
	}


	return retorno;
}



//Pelicula* setDuracion(void* pElement)
//{
//	srand(time(NULL));
//
//	float duracion;
//	int max=10;
//	int min=1;
//	duracion = rand() % (max - min + 1)+min;
//
//	//pelicula_setDuracion((Pelicula*)pElement, duracion);
//
//	return pElement;
//}
//



#endif /* PELICULA_C_ */




