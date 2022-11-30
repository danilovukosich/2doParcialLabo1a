/*
 * pelicula.h
 *
 *  Created on: 30 nov 2022
 *      Author: danil
 */

#ifndef PELICULA_H_
#define PELICULA_H_
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "menus.h"
#include "inputs.h"

typedef struct
{
	int id;
	char titulo[50];
	char genero[50];
	int duracion;

}Pelicula;

Pelicula* pelicula_new();
Pelicula* pelicula_newParametros(char* id, char* titulo, char* genero, char* rating);


int pelicula_setId(Pelicula* this,int id);
int pelicula_getId(Pelicula* this,int* id);
int pelicula_setTitulo(Pelicula* this,char* titulo);
int pelicula_getTitulo(Pelicula* this,char* titulo);
int pelicula_setGenero(Pelicula* this,char* genero);
int pelicula_getGenero(Pelicula* this,char* genero);
int pelicula_setDuracion(Pelicula* this,int duracion);
int pelicula_getDuracion(Pelicula* this,int* duracion);
int pelicula_MostrarPelicula(Pelicula* peliculaAux);

int DuracionRandom(void);
int AsiganrDuracion(Pelicula* this);
int GetGenero(int opcion, char* genero);
int filtroGenero(void* pElement, void* filter);
Pelicula* setDuracion(void* pElement);
int OrdenarPeliculaGenero(void* pPelicula1, void* pPelicula2);
#endif /* PELICULA_H_ */
