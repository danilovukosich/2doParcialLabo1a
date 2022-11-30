/*
 ============================================================================
 Name        : Parcial Laboratorio 2
 Author      : Danilo vukosich 1A DNI: 43034973
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "menus.h"
#include "controller.h"
#include "LinkedList.h"
#include "pelicula.h"
#include <time.h>


int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));
	int opcion=0;
	int generoElegido;
	char genero[50];
	//char nombreDelArchivoNuevo[50];
	int banderaOrdenado=0;


	LinkedList* listaPeliculas=ll_newLinkedList();
	LinkedList* listaFiltroGenero=ll_newLinkedList();
	LinkedList* nuevaListaMap=ll_newLinkedList();

	do
	{
		MenuPrincipal();
		Utn_GetInt(&opcion, ">Ingrese una opcion:", "Error...", 1, 7, 15);

		switch(opcion)
		{
		case 1:
			//CARGA DATOS
			controller_cargarPeliculaDesdeTexto("movies.csv", listaPeliculas);
			break;

		case 2:
			//MOSTRAR DATOS
			controller_listarPeliculas(listaPeliculas);
			break;

		case 3:
			//ASIGNAT DURACION/TIEMPOS
			nuevaListaMap=ll_map(listaPeliculas, AsiganrDuracion);//funciona bien ,auque tenga un warninig
			controller_listarPeliculas(nuevaListaMap);
			break;

		case 4:
			//FILTRAR POR TIPO/GENERO funciona//
			MenuElegirGenero();
			fflush(stdin);
			Utn_GetInt(&generoElegido, ">Ingrese una opcion: ", "Error dato invalido!", 1, 8, 10);
			GetGenero(generoElegido, genero);

			listaFiltroGenero=ll_filter(listaPeliculas, filtroGenero, genero);
			controller_listarPeliculas(listaFiltroGenero);
			controller_guardarPeliculasModoTexto("NuevoListadoPorGenero.txt", listaFiltroGenero);
			break;

		case 5:
			//LISTADO ORDENADO POR GENERO Y DURACION DESCENDENTE
			ll_sort(listaPeliculas, OrdenarPeliculaGenero, 1);
			controller_listarPeliculas(listaPeliculas);
			banderaOrdenado=1;
			break;

		case 6:
			//GUARDAR LISTA
			if(banderaOrdenado==1)
			{
				controller_guardarPeliculasModoTexto("NuevoListadoOrdenado.txt", listaPeliculas);
			}
			else
			{
				printf("Realize el punto 5 para guardar un listado ordenado\n");
			}

			break;

		case 7:
			printf("salio del programa...");
			break;


		}


	}while(opcion!=7);



	return EXIT_SUCCESS;
}
