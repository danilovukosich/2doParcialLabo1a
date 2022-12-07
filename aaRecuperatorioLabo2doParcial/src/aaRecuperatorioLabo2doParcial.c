/*
 ============================================================================
 Name        : aaRecuperatorioLabo2doParcial.c
 Author      : danilo
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
#include "posteos.h"
#include <time.h>

int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));

	int opcion=0;


	LinkedList* listaPosteos=ll_newLinkedList();
	LinkedList* listaConEstadisticas=ll_newLinkedList();
	LinkedList* listaMejoresPosteos=ll_newLinkedList();
	LinkedList* listaHaters=ll_newLinkedList();
	ePosteo* posteoMasPopular;


	do
	{
		MenuPrincipal();
		Utn_GetInt(&opcion, ">Ingrese una opcion:", "Error...", 1, 8, 15);

		switch(opcion)
		{
		case 1:
			//CARGA DATOS
			controller_cargarPosteosDesdeTexto("posts.csv", listaPosteos);
			break;

		case 2:
			//MOSTRAR DATOS
			controller_listarPosteos(listaPosteos);
			break;

		case 3:
			//ASIGNAT ESTADISTICAS
			listaConEstadisticas=ll_map(listaPosteos, AsignarLikes);//funciona bien
			listaConEstadisticas=ll_map(listaPosteos, AsignarDislikes);
			listaConEstadisticas=ll_map(listaPosteos, AsignarFollowers);

			controller_listarPosteos(listaConEstadisticas);
			break;

		case 4:
			//FILTRAR POR MEJORES POSTEOS MAYORES A 4000 LIKES

			listaMejoresPosteos=ll_filter(listaConEstadisticas, filtroLikes, 4000);
			controller_listarPosteos(listaMejoresPosteos);
			controller_guardarPosteosModoTexto("mejoresPosteos.csv", listaMejoresPosteos);
			//guardar modo texto.
			break;

		case 5:
			//Filtro haters
			listaHaters=ll_filter(listaConEstadisticas, filtroHaters, 0);
			controller_listarPosteos(listaHaters);
			controller_guardarPosteosModoTexto("haters.csv", listaHaters);
			break;

		case 6:
			//Ordenar por cantidad de folollowers
			ll_sort(listaConEstadisticas, ordenarPosteosFollowers, 1);
			controller_listarPosteos(listaConEstadisticas);
			break;


		case 7:
			posteoMasPopular=MasPolular(listaConEstadisticas);
			printf("El posteo mas popular es: \n");
			printf("\n|============================POSTEO MAS POPULAR=================================|\n");
			printf("|  ID    |        USUARIO         |     LIKES     |    DISLIKES    | FOLLOWERS  |\n");
			printf("|===============================================================================|\n");
			posteo_MostrarPosteo(posteoMasPopular);
			break;

		case 8:
			printf("Salio del programa...");
			ll_deleteLinkedList(listaPosteos);
			ll_deleteLinkedList(listaConEstadisticas);
			ll_deleteLinkedList(listaMejoresPosteos);
			ll_deleteLinkedList(listaHaters);
			break;
		}


	}while(opcion!=8);


	return EXIT_SUCCESS;
}
