/*
 * posteos.h
 *
 *  Created on: 7 dic 2022
 *      Author: danil
 */

#ifndef POSTEOS_H_
#define POSTEOS_H_

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "menus.h"
#include "inputs.h"
#include "LinkedList.h"
typedef struct
{
	int id;
	char usuario[50];
	int likes;
	int dislikes;
	int followers;

}ePosteo;

ePosteo* Posteo_new();
ePosteo* posteo_newParametros(char* id, char* usuario, char* likes, char* dislikes, char* followers);


int posteo_setId(ePosteo* this,int id);
int posteo_getId(ePosteo* this,int* id);
int posteo_setUsuario(ePosteo* this,char* usuario);
int posteo_getUsuario(ePosteo* this,char* usuario);
int posteo_setLikes(ePosteo* this,int likes);
int posteo_getLikes(ePosteo* this,int* likes);
int posteo_setDislikes(ePosteo* this,int dislikes);
int posteo_getDislikes(ePosteo* this,int* dislikes);
int posteo_setFollowers(ePosteo* this,int followers);
int posteo_getFollowers(ePosteo* this,int* followers);
int posteo_MostrarPosteo(ePosteo* posteoAux);

int NumeroRandom(int minimo, int maximo);
int AsignarLikes(void* this);
int AsignarDislikes(void* this);
int AsignarFollowers(void* this);
int filtroLikes(void* pElement, void* filter);
int filtroHaters(void* pElement, void* filter);
int ordenarPosteosFollowers(void* pPosteo1 ,void* pPosteo2);
ePosteo* MasPolular(LinkedList* pListaPosteos);
#endif /* POSTEOS_H_ */






