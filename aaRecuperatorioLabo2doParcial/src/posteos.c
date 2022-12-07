/*
 * posteos.c
 *
 *  Created on: 7 dic 2022
 *      Author: danil
 */

#ifndef POSTEOS_C_
#define POSTEOS_C_

#include "posteos.h"

ePosteo* Posteo_new()
{
	return malloc(sizeof(ePosteo));
}


ePosteo* posteo_newParametros(char* id, char* usuario, char* likes, char* dislikes, char* followers)
{
	ePosteo* posteoAux;

	posteoAux= Posteo_new();

	if(id!=NULL && usuario!=NULL && likes!=NULL && dislikes!=NULL && followers)
	{
		posteo_setId(posteoAux, atoi(id));
		posteo_setUsuario(posteoAux, usuario);
		posteo_setLikes(posteoAux, atoi(likes));
		posteo_setDislikes(posteoAux, atoi(dislikes));
		posteo_setFollowers(posteoAux, atoi(followers));
	}
	else
	{
		printf("\nError de posteo_newParametros\n");
	}


	return posteoAux;
}

int posteo_setId(ePosteo* this,int id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->id = id;
		retorno=1;
	}

	return retorno;
}

int posteo_getId(ePosteo* this,int* id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*id=this->id;
		retorno=1;
	}

	return retorno;
}

int posteo_setUsuario(ePosteo* this,char* usuario)
{
	int retorno=-1;
	if(this!=NULL && usuario!=NULL)
	{
		strcpy(this->usuario, usuario);
		retorno=1;
	}

	return retorno;
}

int posteo_getUsuario(ePosteo* this,char* usuario)
{
	int retorno=-1;
	if(this!=NULL && usuario!=NULL)
	{
		strcpy(usuario, this->usuario);
		retorno=1;
	}

	return retorno;
}

int posteo_setLikes(ePosteo* this,int likes)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->likes = likes;
		retorno=1;
	}

	return retorno;
}

int posteo_getLikes(ePosteo* this,int* likes)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*likes=this->likes;
		retorno=1;
	}

	return retorno;
}

int posteo_setDislikes(ePosteo* this,int dislikes)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->dislikes = dislikes;
		retorno=1;
	}

	return retorno;
}

int posteo_getDislikes(ePosteo* this,int* dislikes)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*dislikes=this->dislikes;
		retorno=1;
	}

	return retorno;
}

int posteo_setFollowers(ePosteo* this,int followers)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->followers = followers;
		retorno=1;
	}

	return retorno;
}

int posteo_getFollowers(ePosteo* this,int* followers)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*followers=this->followers;
		retorno=1;
	}

	return retorno;
}

int posteo_MostrarPosteo(ePosteo* posteoAux)
{
	int retorno=-1;

	int idAux;
	char ususario[50];
	int likes;
	int dislikes;
	int followers;

	if(posteoAux!=NULL)
	{

		posteo_getId(posteoAux, &idAux);
		posteo_getUsuario(posteoAux, ususario);
		posteo_getLikes(posteoAux, &likes);
		posteo_getDislikes(posteoAux, &dislikes);
		posteo_getFollowers(posteoAux, &followers);
		printf("    %3d %25s       %4d            %4d           %5d\n",idAux, ususario, likes, dislikes,followers);

		retorno=1;
	}

	return retorno;
}

int NumeroRandom(int minimo, int maximo)
{
	int numero;

	for(int i=0; i<100; i++)//100 es la cantidad de numeros
	{
		numero=rand() % (maximo - minimo + 1) + minimo;
	}

	return numero;
}

int AsignarLikes(void* this)
{
	int retorno=-1;
	if(this!=NULL)
	{
		int numero=NumeroRandom(600, 5000);
		posteo_setLikes((ePosteo*)this, numero);
		retorno=1;
	}


	return retorno;
}

int AsignarDislikes(void* this)
{
	int retorno=-1;
	if(this!=NULL)
	{
		int numero=NumeroRandom(300, 3500);
		posteo_setDislikes((ePosteo*)this, numero);
		retorno=1;
	}


	return retorno;
}


int AsignarFollowers(void* this)
{
	int retorno=-1;
	if(this!=NULL)
	{
		int numero=NumeroRandom(10000, 20000);
		posteo_setFollowers((ePosteo*)this, numero);
		retorno=1;
	}


	return retorno;
}

int filtroLikes(void* pElement, void* filter)
{
	int retorno=-1;

	if(((ePosteo*)pElement)->likes > (int*)filter)
	{
		retorno=0;
	}

	return retorno;
}


int filtroHaters(void* pElement, void* filter)
{
	int retorno=-1;

	if(((ePosteo*)pElement)->dislikes > ((ePosteo*)pElement)->likes)
	{
		retorno=0;
	}

	return retorno;
}


int ordenarPosteosFollowers(void* pPosteo1 ,void* pPosteo2)
{
	int followers1;
	int followers2;

	ePosteo* posteo1=NULL;
	ePosteo* posteo2=NULL;


	if(pPosteo1!=NULL && pPosteo2!=NULL)
	{
		posteo1=(ePosteo*)pPosteo1;
		posteo2=(ePosteo*)pPosteo2;

		posteo_getFollowers(posteo1, &followers1);
		posteo_getFollowers(posteo2, &followers2);


	}

	return(followers1<followers2);
}

ePosteo* MasPolular(LinkedList* pListaPosteos)
{

	int size=ll_len(pListaPosteos);
	ePosteo* posteoAux=NULL;
	ePosteo* posteoAuxMayor=NULL;
	int bandera=0;

	for(int i=0; i<size; i++)
	{
		posteoAux=ll_get(pListaPosteos, i);

		if(bandera==0 || posteoAux->likes > posteoAuxMayor->likes)
		{
			posteoAuxMayor=posteoAux;
			bandera=1;
		}

	}
	return posteoAuxMayor;

}

#endif /* POSTEOS_C_ */




