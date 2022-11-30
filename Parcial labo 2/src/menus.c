/*
 * menus.c
 *
 *  Created on: 30 nov 2022
 *      Author: danil
 */

#ifndef MENUS_C_
#define MENUS_C_
#include "menus.h"

void MenuPrincipal(void)
{
	printf("|====================================|\n");
	printf("|-----------MENU PRINCIPAL-----------|\n");
	printf("|====================================|\n");
	printf("|1)Carga archivo.                    |\n"
		   "|2)Imprimir Lista.                   |\n"
		   "|3)Asignar tiempo.                   |\n"
		   "|4)Filtrar por tipo.                 |\n"
		   "|5)Mostrar duraciones.               |\n"
		   "|6)Guardar peliculas.                |\n"
		   "|7)Salir.                            |\n");
	printf("|====================================|\n");
}

void MenuElegirGenero(void)
{
	printf("|====================================|\n");
	printf("|------=-----ELIJA GENERO------------|\n");
	printf("|====================================|\n");
	printf("|1)Adventure.                        |\n"
		   "|2)Drama.                            |\n"
		   "|3)Comedy.                           |\n"
		   "|4)Romance.                          |\n"
		   "|5)Documentary.                      |\n"
		   "|6)Horror.                           |\n"
		   "|7)Musical.                          |\n"
		   "|8)Animation.                         |\n");
	printf("|====================================|\n");
}

#endif /* MENUS_C_ */
